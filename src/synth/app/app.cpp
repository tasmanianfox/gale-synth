#include "app.hpp"

#include <iostream>

App::App(int argc, char *argv[])
{
    this->gtkApplication = Gtk::Application::create(argc, argv, "com.github.tasmanianfox.gale");
}

int App::run()
{
    this->mainWindow = new WindowMain();
    return this->gtkApplication->run(*this->mainWindow);
}