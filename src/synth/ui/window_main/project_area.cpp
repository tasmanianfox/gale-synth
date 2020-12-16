#include "project_area.hpp"

ProjectArea::ProjectArea(Project *project) :
    project(project),
    Gtk::Fixed()
{
    this->add_events(Gdk::BUTTON1_MOTION_MASK);
}

bool ProjectArea::on_draw(const Cairo::RefPtr<Cairo::Context>& cr)
{
    cr->set_line_width(10.0);
    cr->set_source_rgba(0.0, 0.0, 1.0, 0.5);

    for (NodeContainerWidget* outputNodeContainer: this->nodes)
    {
        NodeWidget* outputNode = outputNodeContainer->getNodeWidget();
        vector<Gale::Port*> outputPorts = outputNode->getNode()->getNode()->getOutputPorts();
        for (int outputPortIndex = 0; outputPortIndex < outputPorts.size(); outputPortIndex++)
        {
            Gale::Port* outputPort = outputPorts.at(outputPortIndex);
            int outputX = this->child_property_x(*outputNodeContainer) + outputNode->getOutputPortMiddleX(outputPortIndex);
            int outputY = this->child_property_y(*outputNodeContainer) + outputNode->getOutputPortMiddleY(outputPortIndex);
            for (Gale::Connection* connection: outputPort->getConnections())
            {
                Gale::Port *inputPort = connection->getInput();
                Gale::Node* inputNode = inputPort->getNode();
                int inputPortIndex = inputNode->getInputPortIndex(inputPort);
                NodeContainerWidget* inputContainerWidget = this->getNodeContainerWidget(inputNode);
                NodeWidget* inputWidget = inputContainerWidget->getNodeWidget();
                int inputX = this->child_property_x(*inputContainerWidget) + inputWidget->getInputPortMiddleX(inputPortIndex);
                int inputY = this->child_property_y(*inputContainerWidget) + inputWidget->getInputPortMiddleY(inputPortIndex);
                
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

void ProjectArea::addNode(ProjectNode* node)
{
    NodeContainerWidget* widget = new NodeContainerWidget(this, node);
    this->nodes.push_back(widget);
    this->put(*widget, node->getX(), node->getY());
    widget->show();
}

NodeContainerWidget* ProjectArea::getNodeContainerWidget(Gale::Node* node)
{
    for (NodeContainerWidget* widget: this->nodes)
    {
        if (widget->getNodeWidget()->getNode()->getNode() == node)
        {
            return widget;
        }
    }
    return nullptr;
}