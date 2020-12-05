#include "window_main.hpp"

WindowMain::WindowMain(Project* project)
{
    this->project = project;

	this->set_default_size(800, 600);
    this->set_title("Gale");


    this->add(this->m_Box);
    this->initMenu();

    this->projectArea = new Gtk::Fixed();
    this->m_Box.pack_start(*projectArea);

    for (int i = 0; i < this->project->nodes.size(); i++)
    {
        Node* node = this->project->nodes.at(i);

        projectArea->put(*node, node->x, node->y);

        // projectArea->child_property_x(*node).set_value(10);
        // projectArea->child_property_y(*node).set_value(50);

        node->show();
    }    
}

WindowMain::~WindowMain()
{
    delete this->projectArea;
}