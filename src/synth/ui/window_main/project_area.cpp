#include "project_area.hpp"

ProjectArea::ProjectArea(wxWindow *parent, Project *project) :
    wxControl(parent, wxID_ANY),
    project(project)
{
    this->SetSize(parent->GetClientSize());
    this->SetBackgroundColour(wxColour(200, 200, 200));

    // Can't be placed to initializer since size is not known yet
    this->connectionsWidget = new ConnectionsWidget(this);
    this->connectionsWidget->Show();
    this->newConnectionWidget = new NewConnectionWidget(this);
    this->newConnectionWidget->Show();
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

NewConnectionWidget* ProjectArea::getNewConnectionWidget()
{
    return this->newConnectionWidget;
}

ProjectArea::~ProjectArea()
{
    delete this->connectionsWidget;
    delete this->newConnectionWidget;
}