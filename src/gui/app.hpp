#ifndef _GALE_GUI_APP_H_
#define _GALE_GUI_APP_H_

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "gui/windows/window_main/window_main.hpp"
#include "gui/project/project.hpp"
#include "gui/sound/output/sound_output.hpp"
#include "gui/sound/output/sound_output_impl.hpp"

class App: public wxApp
{
public:
    virtual bool OnInit();

private:
    WindowMain* mainWindow;
    Project project;
    SoundOutput* soundOutput;

    ~App();
};

#endif