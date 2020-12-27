#include "window_main.hpp"

WindowMain::WindowMain(const wxString& title, const wxPoint& pos, const wxSize& size, Project* project) :
    wxFrame(NULL, wxID_ANY, title, pos, size),
    project(project),
    projectArea(new ProjectArea(project))
{
    this->initMenu();
    this->loadProject();
}

WindowMain::~WindowMain()
{
    delete this->projectArea;
}

void WindowMain::loadProject()
{
    vector<ProjectNode*> nodes = this->project->getNodes();
    for (int i = 0; i < nodes.size(); i++)
    {
        ProjectNode* node = nodes.at(i);
        this->projectArea->addNode(node);
    }   
}

void WindowMain::onExit(wxCommandEvent& event)
{
    Close(true);
}