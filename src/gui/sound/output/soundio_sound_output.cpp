#include "soundio_sound_output.hpp"

using namespace std;

static float gale_gui_sound_output_soundio_sound_output_seconds_offset = 0.0f;

static void gale_gui_sound_output_soundio_sound_output_write_callback(struct SoundIoOutStream *outstream,
        int frame_count_min, int frame_count_max) {
    const struct SoundIoChannelLayout *layout = &outstream->layout;
    float float_sample_rate = outstream->sample_rate;
    float seconds_per_frame = 1.0f / float_sample_rate;
    struct SoundIoChannelArea *areas;
    int frames_left = frame_count_max;
    int err;

    while (frames_left > 0) {
        int frame_count = frames_left;
        if ((err = soundio_outstream_begin_write(outstream, &areas, &frame_count))) {
            throw soundio_strerror(err);
        }

        if (!frame_count)
            break;

        float pitch = 440.0f;
        float radians_per_second = pitch * 2.0f * M_PI;
        for (int frame = 0; frame < frame_count; frame += 1) {
            float sample = sin((gale_gui_sound_output_soundio_sound_output_seconds_offset + frame * seconds_per_frame) * radians_per_second);
            // square
            // sample = sample > 0 ? 1.0 : -1.0;
            // sound
            sample *= 0.5;
            
            float *ptr;
            // LEFT
            ptr = (float*)(areas[0].ptr + areas[0].step * frame);
            *ptr = sample;
            // RIGHT
            ptr = (float*)(areas[1].ptr + areas[1].step * frame);
            *ptr = sample;
        }
        gale_gui_sound_output_soundio_sound_output_seconds_offset =
            fmod(gale_gui_sound_output_soundio_sound_output_seconds_offset + seconds_per_frame * frame_count, 1.0);

        if ((err = soundio_outstream_end_write(outstream))) {
            fprintf(stderr, "%s\n", soundio_strerror(err));
            exit(1);
        }

        frames_left -= frame_count;
    }
}

SoundioSoundOutput::SoundioSoundOutput() {

}

void SoundioSoundOutput::soundThread() {
    int err;
    struct SoundIo *soundio = soundio_create();

    if (!soundio) {
        throw "out of memory";
    }

    if ((err = soundio_connect(soundio))) {
        throw string("error connecting: ") + soundio_strerror(err);
    }

    soundio_flush_events(soundio);

    int default_out_device_index = soundio_default_output_device_index(soundio);
    if (default_out_device_index < 0) {
        throw "no output device found";
    }

    struct SoundIoDevice *device = soundio_get_output_device(soundio, default_out_device_index);
    if (!device) {
        throw "out of memory";
    }

    struct SoundIoOutStream *outstream = soundio_outstream_create(device);
    if (!outstream) {
        throw "out of memory";
    }
    outstream->format = SoundIoFormatFloat32NE;
    outstream->write_callback = gale_gui_sound_output_soundio_sound_output_write_callback;

    if ((err = soundio_outstream_open(outstream))) {
        throw string("unable to open device: ") + soundio_strerror(err);
    }

    if (outstream->layout_error)
        throw string("unable to set channel layout: ") + soundio_strerror(outstream->layout_error);

    if ((err = soundio_outstream_start(outstream))) {
        throw string("unable to start device: ") + soundio_strerror(err);
    }

    for (;;)
        soundio_wait_events(soundio);

    soundio_outstream_destroy(outstream);
    soundio_device_unref(device);
    soundio_destroy(soundio);
}