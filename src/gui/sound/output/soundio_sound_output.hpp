#ifndef _GALE_GUI_SOUND_OUTPUT_SOUNDIO_SOUND_OUTPUT_H_
#define _GALE_GUI_SOUND_OUTPUT_SOUNDIO_SOUND_OUTPUT_H_

#include <soundio/soundio.h>

#include "sound_output.hpp"

/**
 * Provides sound output using Soundio library
 */
class SoundioSoundOutput : public SoundOutput {
public:
    SoundioSoundOutput();
protected:
    virtual void soundThread() override;
};

#endif