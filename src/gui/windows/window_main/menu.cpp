#include "window_main.hpp"

enum
{
    ID_New,
    ID_Save,
    ID_Open,
};

wxBEGIN_EVENT_TABLE(WindowMain, wxFrame)
    EVT_MENU(wxID_EXIT,  WindowMain::onExit)
wxEND_EVENT_TABLE()

void WindowMain::initMenu()
{
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(ID_New, "&New\tCtrl-N", "Create a new project");
    menuFile->Append(ID_Save, "&Save\tCtrl-S", "Save current project");
    menuFile->Append(ID_Open, "&Open\tCtrl-O", "Open an existing project");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);
    wxMenu *menuAdd = new wxMenu;
    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);
    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuAdd, "&Add");
    menuBar->Append(menuHelp, "&Help");

    SetMenuBar(menuBar);
}