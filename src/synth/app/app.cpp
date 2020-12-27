#include "app.hpp"

const char APP_NAME[] = "Gale";

bool App::OnInit()
{
  this->project.reset();
  this->mainWindow = new WindowMain(APP_NAME, wxPoint(50, 50), wxSize(450, 340), &this->project);
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