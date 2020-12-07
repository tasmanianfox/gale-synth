#include "project_area.hpp"

ProjectArea::ProjectArea()
{

}

ProjectArea::ProjectArea(Project *project) : Gtk::Fixed()
{
    this->project = project;
}

bool ProjectArea::on_draw(const Cairo::RefPtr<Cairo::Context>& cr)
{
    Gtk::Fixed::on_draw(cr);

    for (Node* outputNode: this->project->nodes)
    {
        int outputX = this->child_property_x(*outputNode);
        int outputY = this->child_property_y(*outputNode);
        for (Port* outputPort: outputNode->getOutputPorts())
        {
            for (Connection* connection: outputPort->getConnections())
            {
                Node* inputNode = connection->getInput()->getNode();
                int inputX = this->child_property_x(*inputNode);
                int inputY = this->child_property_y(*inputNode);

                cr->set_line_width(10.0);
                cr->set_source_rgba(0.0, 0.0, 1.0, 0.5);
                cr->move_to(outputX, outputY);
                cr->line_to(inputX, inputY);
                cr->stroke();
            }
        }
    }

    return true;
}