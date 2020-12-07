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
    cr->set_line_width(10.0);
    cr->set_source_rgba(0.0, 0.0, 1.0, 0.5);

    for (Node* outputNode: this->project->nodes)
    {
        vector<Port*> outputPorts = outputNode->getOutputPorts();
        for (int outputPortIndex = 0; outputPortIndex < outputPorts.size(); outputPortIndex++)
        {
            Port* outputPort = outputPorts.at(outputPortIndex);
            int outputX = this->child_property_x(*outputNode) + outputNode->getOutputPortMiddleX(outputPortIndex);
            int outputY = this->child_property_y(*outputNode) + outputNode->getOutputPortMiddleY(outputPortIndex);
            for (Connection* connection: outputPort->getConnections())
            {
                Port *inputPort = connection->getInput();
                Node* inputNode = inputPort->getNode();
                int inputPortIndex = inputNode->getInputPortIndex(inputPort);
                int inputX = this->child_property_x(*inputNode) + inputNode->getInputPortMiddleX(inputPortIndex);
                int inputY = this->child_property_y(*inputNode) + inputNode->getInputPortMiddleY(inputPortIndex);
                
                cr->move_to(outputX, outputY);
                cr->line_to(inputX, inputY);
                cr->stroke();
            }
        }
    }

    cr->set_line_width(1.0);

    Gtk::Fixed::on_draw(cr);

    return true;
}