#ifndef _GALE_CORE_SOUND_SOUND_DATA_H_
#define _GALE_CORE_SOUND_SOUND_DATA_H_

namespace Gale::Core {

struct SoundChannelData {
    float value;
};

/**
 * Sound output
 */
struct SoundOutputData {
    SoundChannelData left;
    SoundChannelData right;
};

}

#endif