#include "app.hpp"

bool App::OnInit()
{
  this->project.reset();
  this->mainWindow = new WindowMain(&this->project);
  this->mainWindow->Show(true);
  return true;
}

App::~App()
{
  if (this->mainWindow != nullptr)
  {
    delete this->mainWindow;
  } 
}