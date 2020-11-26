#include "synth/app/app.hpp"

int main(int argc, char *argv[])
{
  Glib::RefPtr<App> app = App::create(argc, argv);
  return app->run();
}