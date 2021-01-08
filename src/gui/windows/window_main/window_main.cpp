#include "window_main.hpp"

const char TITLE[] = "Gale";
const int WIDTH = 1024;
const int HEIGHT = 768;

WindowMain::WindowMain(Project* project) :
    wxFrame(nullptr, wxID_ANY, TITLE, wxDefaultPosition, wxSize(WIDTH, HEIGHT)),
    project(project),
    projectArea(new ProjectArea(this, project))
{
    this->Center();
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