#include "app.hpp"

const char APP_ID[] = "com.github.tasmanianfox.gale";
const char APP_NAME[] = "Gale";

App::App(int argc, char *argv[]) : Gtk::Application(APP_ID)
{
    Glib::set_application_name(APP_NAME);
}

Glib::RefPtr<App> App::create(int argc, char *argv[])
{
  return Glib::RefPtr<App>(new App(argc, argv));
}

void App::on_startup()
{
  Gtk::Application::on_startup();

  this->mainWindow = new WindowMain();
  add_window(*this->mainWindow);
  this->mainWindow->show_all();
}