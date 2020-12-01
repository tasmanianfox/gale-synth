#include "window_main.hpp"

#include <iostream>
using namespace std;


WindowMain::WindowMain(Project* project)
{
    this->project = project;

	this->set_default_size(800, 600);
    this->set_title("Gale");


    this->add(this->m_Box);
    this->initMenu();

    Gtk::Fixed* projectArea = new Gtk::Fixed();
    this->m_Box.pack_start(*projectArea);

    cout << "Constructor called!" << endl;
    for (int i = 0; i < this->project->nodes.size(); i++)
    {
        cout << "Drawing widget!" << endl;
        Node* node = this->project->nodes[i];
        projectArea->add(*node);

        projectArea->child_property_x(*node).set_value(10);
        projectArea->child_property_y(*node).set_value(50);

        node->show();
    }    
}

WindowMain::~WindowMain()
{

}