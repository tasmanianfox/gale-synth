#ifndef _GALE_GUI_SOUND_OUTPUT_PLUGIN_SOUND_OUTPUT_H_
#define _GALE_GUI_SOUND_OUTPUT_PLUGIN_SOUND_OUTPUT_H_

#include "core/project/node/node_play_context.hpp"
#include "core/sound/sound_data.hpp"
#include "sound_output.hpp"

/**
 * Returns numeric values for external players
 */
class PluginSoundOutput : public SoundOutput {
public:
    PluginSoundOutput(Gale::Core::Pipeline* pipeline);
protected:
    virtual void soundThread() override;
};

#endif