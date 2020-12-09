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
}

WindowMain::~WindowMain()
{
    
}

void WindowMain::load()
{
    this->project = project;

    for (int i = 0; i < this->project->nodes.size(); i++)
    {
        Node* node = this->project->nodes.at(i);
        NodeWidget widget(node);
        projectArea.put(widget, node->x, node->y);

        node->show();
    }   
}