#include "window_main.hpp"

WindowMain::WindowMain(Project* project)
{
    this->project = project;

	this->set_default_size(800, 600);
    this->set_title("Gale");

    this->m_Box.set_events(Gdk::BUTTON_PRESS_MASK);
    this->add(this->m_Box);
    this->initMenu();

    this->projectArea = ProjectArea(project);
    this->m_Box.pack_start(this->projectArea);

    this->loadProject();
}

WindowMain::~WindowMain()
{
    
}

void WindowMain::loadProject()
{
    vector<ProjectNode*> nodes = this->project->getNodes();
    for (int i = 0; i < nodes.size(); i++)
    {
        ProjectNode* node = nodes.at(i);
        this->projectArea.addNode(node);
    }   
}