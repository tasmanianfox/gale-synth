#include "node_container_widget.hpp"
#include "project_area.hpp"

NodeContainerWidget::NodeContainerWidget(ProjectArea *projectArea, ProjectNode* node) :
    wxWindow(projectArea, wxID_ANY, wxPoint(node->getX(), node->getY())),
    projectArea(projectArea),
    node(node),
    nodeWidget(this, node)
{
    this->nodeWidget.Show();
    wxSize nodeWidgetSize = this->nodeWidget.calculateSize();

    this->SetSize(nodeWidgetSize);

    int inputIndex = 0, outputIndex = 0;
    for(Gale::Port* port: node->getNode()->getPorts())
    {
        int* index = port->isInput() ? &inputIndex : &outputIndex;
        NodePortWidget* widget = new NodePortWidget(this, *index, port);
        this->nodePortWidgets.push_back(widget);
        widget->Show();
        (*index)++;
    }
}

NodeWidget* NodeContainerWidget::getNodeWidget()
{
    return &this->nodeWidget;
}

vector<NodePortWidget*> NodeContainerWidget::getPortWidgets()
{
    return this->nodePortWidgets;
}

void NodeContainerWidget::moveMe(wxPoint point)
{
    this->Move(point + this->GetPosition());
}

NodePortWidget* NodeContainerWidget::getPortWidget(int index)
{
    return this->nodePortWidgets.at(index);
}

void NodeContainerWidget::redrawProjectArea()
{
    this->projectArea->Update();
}