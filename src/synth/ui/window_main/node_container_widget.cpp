#include "node_container_widget.hpp"

NodeContainerWidget::NodeContainerWidget(ProjectArea *projectArea, ProjectNode* node) :
    projectArea(projectArea),
    node(node),
    nodeWidget(this, node),
    Gtk::Fixed()
{
    this->put(this->nodeWidget, 0, 0);
    this->nodeWidget.show();
}

NodeWidget* NodeContainerWidget::getNodeWidget()
{
    return &this->nodeWidget;
}

#include "project_area.hpp"

void NodeContainerWidget::moveMe(gdouble x, gdouble y)
{
    this->projectArea->move(*this,
                            this->projectArea->child_property_x(*this) + x,
                            this->projectArea->child_property_y(*this) + y);
}