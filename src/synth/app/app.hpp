#ifndef _GALE_SYNTH_APP_APP_H_
#define _GALE_SYNTH_APP_APP_H_

#include <gtkmm.h>

#include "synth/ui/window_main/window_main.hpp"
#include "synth/project/project.hpp"

class App : public Gtk::Application
{
public:
    static Glib::RefPtr<App> create(int argc, char *argv[]);

private:
    WindowMain* mainWindow;
    Project project;

    App(int argc, char *argv[]);
    
    void on_startup() override;    
};

#endif