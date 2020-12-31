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

// TODO: REMOVE. Connections are rendered in dedicated class
void ProjectArea::paintEvent(wxPaintEvent & evt)
{
    wxPaintDC dc(this);
    dc.SetBrush(wxBrush(wxColour(0, 0, 255, 128)));

    for (NodeContainerWidget* outputNodeContainer: this->nodes)
    {
        for (NodePortWidget* outputPortWidget: outputNodeContainer->getPortWidgets())
        {
        }
    }
}

// TODO: REMOVE
// bool ProjectArea::on_draw(const Cairo::RefPtr<Cairo::Context>& cr) TODO: REMOVE
// {
//     cr->set_line_width(10.0);
//     cr->set_source_rgba(0.0, 0.0, 1.0, 0.5);

//     for (NodeContainerWidget* outputNodeContainer: this->nodes)
//     {
//         for (NodePortWidget* outputPortWidget: outputNodeContainer->getPortWidgets())
//         {
//             int outputX = this->child_property_x(*outputNodeContainer) +
//                 outputNodeContainer->child_property_x(*outputPortWidget) +
//                 outputPortWidget->getPinCenterX();
//             int outputY = this->child_property_y(*outputNodeContainer) +
//                 outputNodeContainer->child_property_y(*outputPortWidget) +
//                 outputPortWidget->getPinCenterY();
//             for (Gale::Connection* connection: outputPortWidget->getPort()->getConnections())
//             {
//                 Gale::Port *inputPort = connection->getInput();
//                 Gale::Node* inputNode = inputPort->getNode();
//                 int inputPortIndex = inputNode->getInputPortIndex(inputPort);
//                 NodeContainerWidget* inputNodeContainer = this->getNodeContainerWidget(inputNode);
//                 NodePortWidget* inputPortWidget = inputNodeContainer->getPortWidget(inputPortIndex);

//                 int inputX = this->child_property_x(*inputNodeContainer) +
//                     inputNodeContainer->child_property_x(*inputPortWidget) +
//                     inputPortWidget->getPinCenterX();
//                 int inputY = this->child_property_y(*inputNodeContainer) +
//                     inputNodeContainer->child_property_y(*inputPortWidget) +
//                     inputPortWidget->getPinCenterY();

//                 cr->move_to(outputX, outputY);
//                 cr->line_to(inputX, inputY);
//                 cr->stroke();
//             }
//         }
//     }

//     cr->set_line_width(1.0);
//     Gtk::Fixed::on_draw(cr);

//     return true;
// }

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

BEGIN_EVENT_TABLE(ProjectArea, wxControl)
    EVT_PAINT(ProjectArea::paintEvent)
END_EVENT_TABLE()