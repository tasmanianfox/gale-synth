#include "node_widget.hpp"
#include "node_container_widget.hpp"

wxPoint dragStart;

NodeWidget::NodeWidget(NodeContainerWidget* container, ProjectNode* node) :
    wxWindow(container, wxID_ANY),
    container(container),
    node(node)
{
    this->SetSize(this->calculateSize());
}

NodeWidget::~NodeWidget()
{
    delete this->node;
}

void NodeWidget::paintEvent(wxPaintEvent& evt)
{
    // Border
    wxSize size = calculateSize();
    wxPaintDC dc(this);
    dc.SetPen(*wxBLACK_PEN);
    dc.SetBrush(*wxTRANSPARENT_BRUSH);
    dc.DrawRectangle(wxRect(0, 0, size.x, size.y));

    // Name
    wxCoord w, h;
    wxFont font(8, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
    dc.GetTextExtent(this->node->getNode()->getName(), &w, &h, NULL, NULL, &font);
    dc.SetFont(font);
    dc.DrawText(this->node->getNode()->getName(), wxPoint((this->GetSize().x - w) / 2, 5));
}

wxSize NodeWidget::calculateSize()
{
    int maxPorts = max(this->node->getInputPorts().size(), this->node->getOutputPorts().size());
    return wxSize(NAME_MARGIN_HORIZONTAL * 2 + 100,
                  2 * PAD_VERTICAL + maxPorts * PORT_HEIGHT + (maxPorts-1) * PAD_PORTS);
}

void NodeWidget::onMouseMove(wxMouseEvent& evt)
{
  if (evt.LeftIsDown())
  {
    this->container->moveMe(wxPoint(evt.m_x, evt.m_y) - dragStart);
  }
}

void NodeWidget::onMouseLeftDown(wxMouseEvent& evt)
{
    dragStart = wxPoint(evt.m_x, evt.m_y);
}

ProjectNode* NodeWidget::getNode()
{
    return this->node;
}

Gale::Connection* NodeWidget::connect(const char* myPortName, NodeWidget* otherNode, const char* otherPortName)
{
    return this->getNode()->connect(myPortName, otherNode->getNode(), otherPortName);
}

BEGIN_EVENT_TABLE(NodeWidget, wxControl)
    EVT_LEFT_DOWN(NodeWidget::onMouseLeftDown)
    EVT_MOTION(NodeWidget::onMouseMove)
    EVT_PAINT(NodeWidget::paintEvent)
END_EVENT_TABLE()