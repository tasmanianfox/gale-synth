#ifndef _GALE_GUI_WINDOWS_WINDOW_MAIN_WINDOW_MAIN_H_
#define _GALE_GUI_WINDOWS_WINDOW_MAIN_WINDOW_MAIN_H_

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "gui/project/project.hpp"
#include "gui/windows/window_main/node_widget.hpp"
#include "gui/windows/window_main/project_area.hpp"

class WindowMain : public wxFrame
{
public:
  WindowMain(Project* project);
  virtual ~WindowMain();

  void loadProject();

private:
  ProjectArea *projectArea;
  Project* project;

  void initMenu();

  void onExit(wxCommandEvent& event);

  wxDECLARE_EVENT_TABLE();
};

#endif