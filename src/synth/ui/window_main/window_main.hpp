#ifndef _GALE_SYNTH_UI_WINDOW_MAIN_WINDOW_MAIN_H_
#define _GALE_SYNTH_UI_WINDOW_MAIN_WINDOW_MAIN_H_

#include <iostream>

#include <gtkmm.h>

class WindowMain : public Gtk::Window
{

public:
  WindowMain();
  virtual ~WindowMain();

private:
  Gtk::VBox m_Box;

  void initMenu();
  void on_menu_file_quit();
};

#endif