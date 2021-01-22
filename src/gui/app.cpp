#include "app.hpp"

#ifdef __linux__
    #include "gui/sound/output/soundio_sound_output.hpp"
    using SoundOutputImpl = SoundioSoundOutput;
#endif

bool App::OnInit()
{
  this->project.reset();

  this->soundOutput = new SoundOutputImpl(this->project.getProject()->getPipelinePtr());
  this->soundOutput->startSoundThread();

  this->mainWindow = new WindowMain(&this->project);
  this->mainWindow->Show(true);
  return true;
}

App::~App()
{
  if (this->mainWindow != nullptr) {
    delete this->mainWindow;
  }
  if (this->soundOutput != nullptr) {
    delete this->soundOutput;
  }
}