#ifndef _GALE_GUI_SOUND_OUTPUT_SOUND_OUTPUT_H_
#define _GALE_GUI_SOUND_OUTPUT_SOUND_OUTPUT_H_

#include <string>
#include <thread>

#include <wx/msgdlg.h>

class SoundOutput {
public:
    void startSoundThread();
protected:
    virtual void soundThread() = 0;
    void soundThreadWrapper();
private:
    std::thread thread;
};

#endif