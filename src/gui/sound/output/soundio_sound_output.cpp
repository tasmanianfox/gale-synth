#include "soundio_sound_output.hpp"

static float gale_gui_sound_output_soundio_sound_output_seconds_offset = 0.0f;
Gale::Core::Pipeline* gale_gui_sound_output_soundio_sound_output_pipeline = nullptr;

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

        for (int frame = 0; frame < frame_count; frame += 1) {
            struct Gale::Core::NodePlayContext context = {
                .frame = frame,
                .frame_count = frame_count,
                .sample_rate = outstream->sample_rate,
                .seconds_offset = gale_gui_sound_output_soundio_sound_output_seconds_offset
            };
            Gale::Core::SoundOutputData data = gale_gui_sound_output_soundio_sound_output_pipeline->generateSound(&context);

            float *ptr;
            // LEFT
            ptr = (float*)(areas[0].ptr + areas[0].step * frame);
            *ptr = data.left.value;
            // RIGHT
            ptr = (float*)(areas[1].ptr + areas[1].step * frame);
            *ptr = data.right.value;
        }
        gale_gui_sound_output_soundio_sound_output_seconds_offset =
            fmod(gale_gui_sound_output_soundio_sound_output_seconds_offset + seconds_per_frame * frame_count, 1.0);

        if ((err = soundio_outstream_end_write(outstream))) {
            throw soundio_strerror(err);
        }

        frames_left -= frame_count;
    }
}

SoundioSoundOutput::SoundioSoundOutput(Gale::Core::Pipeline* pipeline) :
        SoundOutput(pipeline) {
    gale_gui_sound_output_soundio_sound_output_pipeline = pipeline;
}

void SoundioSoundOutput::soundThread() {
    int err;
    struct SoundIo *soundio = soundio_create();

    if (!soundio) {
        throw "out of memory";
    }

    // TODO: Configurable sound backend
    // soundio_connect_backend(soundio, SoundIoBackendJack)
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