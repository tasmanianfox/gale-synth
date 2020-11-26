#ifndef _GALE_SYNTH_APP_APP_H_
#define _GALE_SYNTH_APP_APP_H_

#include <gtkmm.h>

#include "synth/ui/window_main/window_main.hpp"

class App
{
public:
    App(int argc, char *argv[]);

    int run();
private:
    WindowMain* mainWindow;

    Glib::RefPtr<Gtk::Application> gtkApplication;
};

#endif