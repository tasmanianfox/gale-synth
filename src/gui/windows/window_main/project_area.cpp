#include "project_area.hpp"

ProjectArea::ProjectArea(wxWindow *parent, Project *project) :
    wxControl(parent, wxID_ANY),
    project(project),
    clickedPort(nullptr)
{
    this->SetSize(parent->GetClientSize());
    this->SetBackgroundColour(wxColour(200, 200, 200));

    // Can't be placed to initializer since size is not known yet
    this->connectionsWidget = new ConnectionsWidget(this);
    this->connectionsWidget->Show();
}

void ProjectArea::addNode(ProjectNode* node)
{
    NodeContainerWidget* widget = new NodeContainerWidget(this, node);
    this->nodes.push_back(widget);
    widget->Show();
}

NodePortWidget* ProjectArea::getClickedPort()
{
    return this->clickedPort;
}

ConnectionsWidget* ProjectArea::getConnectionsWidget()
{
    return this->connectionsWidget;
}

vector<NodeContainerWidget*> ProjectArea::getNodes()
{
    return this->nodes;
}

void ProjectArea::setClickedPort(NodePortWidget* widget)
{
    this->clickedPort = widget;
}

ProjectArea::~ProjectArea()
{
    delete this->connectionsWidget;
    delete this->newConnectionWidget;
}