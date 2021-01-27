#ifndef _GALE_GUI_SOUND_OUTPUT_PLUGIN_SOUND_OUTPUT_IMPL_H_
#define _GALE_GUI_SOUND_OUTPUT_PLUGIN_SOUND_OUTPUT_IMPL_H_

#if defined GALE_TYPE_NATIVE && defined __linux__
  #include "gui/sound/output/soundio_sound_output.hpp"
  typedef SoundioSoundOutput SoundOutputImpl;
#endif
#ifdef GALE_TYPE_LV2
  #include "gui/sound/output/plugin_sound_output.hpp"
  typedef PluginSoundOutput SoundOutputImpl;
#endif

#endif