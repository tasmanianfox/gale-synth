#ifndef _GALE_GUI_SOUND_OUTPUT_SOUND_OUTPUT_H_
#define _GALE_GUI_SOUND_OUTPUT_SOUND_OUTPUT_H_

#include <string>
#include <thread>

#include <wx/msgdlg.h>

#include "core/project/pipeline.hpp"

class SoundOutput {
public:
    SoundOutput(Gale::Core::Pipeline* pipeline);
    void startSoundThread();
protected:
    virtual void soundThread() = 0;
    void soundThreadWrapper();

    Gale::Core::Pipeline* pipeline;
private:
    std::thread thread;
};

#endif