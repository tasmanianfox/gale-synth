#ifndef _GALE_SYNTH_UI_WINDOW_MAIN_WINDOW_MAIN_H_
#define _GALE_SYNTH_UI_WINDOW_MAIN_WINDOW_MAIN_H_

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "synth/app/project/project.hpp"
#include "synth/ui/window_main/node_widget.hpp"
#include "synth/ui/window_main/project_area.hpp"

class WindowMain : public wxFrame
{
public:
  WindowMain(const wxString& title, const wxPoint& pos, const wxSize& size, Project* project);
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