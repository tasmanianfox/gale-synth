#include "project_area.hpp"

ProjectArea::ProjectArea(wxWindow *parent, Project *project) :
    wxControl(parent, wxID_ANY),
    project(project)
{
    this->SetSize(parent->GetClientSize());
    this->SetBackgroundColour(wxColour(200, 200, 200));

    this->connectionsWidget = new ConnectionsWidget(this);
    this->connectionsWidget->Show();
}

void ProjectArea::addNode(ProjectNode* node)
{
    NodeContainerWidget* widget = new NodeContainerWidget(this, node);
    this->nodes.push_back(widget);
    widget->Show();
}

vector<NodeContainerWidget*> ProjectArea::getNodes()
{
    return this->nodes;
}

ConnectionsWidget* ProjectArea::getConnectionsWidget()
{
    return this->connectionsWidget;
}

ProjectArea::~ProjectArea()
{
    delete this->connectionsWidget;
}