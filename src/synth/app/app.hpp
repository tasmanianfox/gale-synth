#ifndef _GALE_SYNTH_APP_APP_H_
#define _GALE_SYNTH_APP_APP_H_

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "synth/ui/window_main/window_main.hpp"
#include "synth/app/project/project.hpp"

class App: public wxApp
{
public:
    virtual bool OnInit();

private:
    WindowMain* mainWindow;
    Project project;

    ~App();
};

#endif