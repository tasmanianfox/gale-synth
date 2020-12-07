#ifndef _GALE_SYNTH_UI_WINDOW_MAIN_WINDOW_MAIN_H_
#define _GALE_SYNTH_UI_WINDOW_MAIN_WINDOW_MAIN_H_

#include <iostream>

#include <gtkmm.h>

#include "synth/project/project.hpp"
#include "synth/ui/window_main/project_area.hpp"

class WindowMain : public Gtk::Window
{
public:
  WindowMain(Project* project);
  virtual ~WindowMain();

private:
  Gtk::VBox m_Box; // menu
  ProjectArea projectArea;

  Project* project;

  void initMenu();
  void on_menu_file_quit();
};

#endif