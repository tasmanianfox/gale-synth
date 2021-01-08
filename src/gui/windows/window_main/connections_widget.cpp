#include "connections_widget.hpp"
#include "project_area.hpp"

ConnectionsWidget::ConnectionsWidget(ProjectArea* projectArea):
    wxWindow(projectArea, wxID_ANY),
    projectArea(projectArea)
{
    this->SetSize(this->projectArea->GetSize());
}

void ConnectionsWidget::paintEvent(wxPaintEvent & evt)
{
    wxPaintDC dc(this);
    wxPen pen;
	pen.SetColour(0, 0, 255);
	pen.SetWidth(3);
	pen.SetStyle(wxPENSTYLE_SOLID);
	dc.SetPen(pen);

    for (NodeContainerWidget* outputNodeContainer: this->projectArea->getNodes())
    {
        for (NodePortWidget* outputPortWidget: outputNodeContainer->getPortWidgets())
        {
            if (outputPortWidget->getPort()->isInput())
            {
                continue;
            }

            wxPoint outputNodePos = outputNodeContainer->GetPosition() + outputPortWidget->GetPosition();
            int outputX = outputNodePos.x + outputPortWidget->getPinCenterX();
            int outputY = outputNodePos.y + outputPortWidget->getPinCenterY();
            for (Gale::Connection* connection: outputPortWidget->getPort()->getConnections())
            {
                Gale::Port *inputPort = connection->getInput();
                Gale::Node* inputNode = inputPort->getNode();
                int inputPortIndex = inputNode->getInputPortIndex(inputPort);
                NodeContainerWidget* inputNodeContainer = this->getNodeContainerWidget(inputNode);
                NodePortWidget* inputPortWidget = inputNodeContainer->getPortWidget(inputPortIndex);

                wxPoint inputNodePos = inputNodeContainer->GetPosition() + inputPortWidget->GetPosition();
                int inputX = inputNodePos.x + inputPortWidget->getPinCenterX();
                int inputY = inputNodePos.y + inputPortWidget->getPinCenterY();

                dc.DrawLine(outputX, outputY, inputX, inputY);
            }
        }
    }

}

NodeContainerWidget* ConnectionsWidget::getNodeContainerWidget(Gale::Node* node)
{
    for (NodeContainerWidget* widget: this->projectArea->getNodes())
    {
        if (widget->getNodeWidget()->getNode()->getNode() == node)
        {
            return widget;
        }
    }
    return nullptr;
}

BEGIN_EVENT_TABLE(ConnectionsWidget, wxWindow)
    EVT_PAINT(ConnectionsWidget::paintEvent)
END_EVENT_TABLE()