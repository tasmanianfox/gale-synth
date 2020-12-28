#include "node_container_widget.hpp"
#include "project_area.hpp"

NodeContainerWidget::NodeContainerWidget(ProjectArea *projectArea, const wxPoint& pos, ProjectNode* node) :
    wxWindow(projectArea, wxID_ANY, pos),
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

// TODO: REMOVE
// void NodeContainerWidget::moveMe(gdouble x, gdouble y)
// {
//     this->projectArea->move(*this,
//                             this->projectArea->child_property_x(*this) + x,
//                             this->projectArea->child_property_y(*this) + y);
// }

NodePortWidget* NodeContainerWidget::getPortWidget(int index)
{
    return this->nodePortWidgets.at(index);
}

void NodeContainerWidget::redrawProjectArea()
{
    this->projectArea->Update();
}

void NodeContainerWidget::paintEvent(wxPaintEvent& evt)
{

}

BEGIN_EVENT_TABLE(NodeContainerWidget, wxControl)
    EVT_PAINT(NodeContainerWidget::paintEvent)
END_EVENT_TABLE()
