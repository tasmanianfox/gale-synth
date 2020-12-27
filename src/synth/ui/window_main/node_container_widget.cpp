#include "node_container_widget.hpp"
#include "project_area.hpp"

NodeContainerWidget::NodeContainerWidget(ProjectArea *projectArea, ProjectNode* node) :
    wxControl(),
    projectArea(projectArea),
    node(node),
    nodeWidget(this, node)
{
    // TODO: REMOVE
    // this->put(this->nodeWidget, 0, 0);
    // this->nodeWidget.show();

    // int inputIndex = 0, outputIndex = 0;
    // for(Gale::Port* port: node->getNode()->getPorts())
    // {
    //     int* index = port->isInput() ? &inputIndex : &outputIndex;
        
    //     NodePortWidget* widget = new NodePortWidget(this, port);
    //     int port_minimum_width = 0, port_natural_width = 0, node_minimum_width = 0, node_natural_width = 0;
    //     this->nodeWidget.get_preferred_width_vfunc(node_minimum_width, node_natural_width);
    //     widget->get_preferred_width_vfunc(port_minimum_width, port_natural_width);
    //     int left = port->isInput() ? 0 : node_minimum_width - port_minimum_width;
    //     this->put(*widget, left, this->getPortY(*index));
    //     this->nodePortWidgets.push_back(widget);
    //     widget->Show();

    //     (*index)++;
    // }
}

NodeWidget* NodeContainerWidget::getNodeWidget()
{
    return &this->nodeWidget;
}

vector<NodePortWidget*> NodeContainerWidget::getPortWidgets()
{
    return this->nodePortWidgets;
}

// TODO: REMOVE
// void NodeContainerWidget::moveMe(gdouble x, gdouble y)
// {
//     this->projectArea->move(*this,
//                             this->projectArea->child_property_x(*this) + x,
//                             this->projectArea->child_property_y(*this) + y);
// }

int NodeContainerWidget::getPortY(int index)
{
    return index*(PORT_WIDTH+PAD_PORTS) + PAD_VERTICAL;
}

NodePortWidget* NodeContainerWidget::getPortWidget(int index)
{
    return this->nodePortWidgets.at(index);
}

void NodeContainerWidget::redrawProjectArea()
{
    // this->projectArea->queue_draw();
}