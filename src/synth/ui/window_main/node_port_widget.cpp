#include "node_container_widget.hpp"
#include "project_area.hpp"

wxColour darkGreen(0, 128, 0);
wxColour yellow(255, 211, 0);
wxFont fontNodePortName(8, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);

NodePortWidget::NodePortWidget(NodeContainerWidget* container, int index, Gale::Port* port) :
    wxWindow(container, wxID_ANY),
    container(container),
    index(index),
    port(port),
    areDimensionsSet(false),
    textWidth(0)
{

}

void NodePortWidget::paintEvent(wxPaintEvent & evt)
{
  wxPaintDC dc(this);
  if (!this->areDimensionsSet)
  {
    this->setDimensions(&dc);
  }
  
  // Pin
  wxColour pinColor = this->container->getProjectArea()->getClickedPort() == this ? yellow : darkGreen;
  dc.SetPen(wxPen(pinColor));
  dc.SetBrush(wxBrush(pinColor));
  int portMargin = 3 + PORT_WIDTH;
  int textWithMargin = this->textWidth + portMargin;
  dc.DrawRectangle(wxRect(this->getPinX(), 0, PORT_WIDTH, PORT_HEIGHT));

  // Port name
  dc.SetFont(fontNodePortName);
  int left = this->port->isInput() ? PORT_WIDTH+3 : this->GetSize().x - textWithMargin;
  dc.SetTextForeground(wxColour(0, 0, 0));
  dc.DrawText(this->port->getName(), wxPoint(left, 0));
}

void NodePortWidget::onLeftMouseDown(wxMouseEvent& evt)
{
  NodePortWidget* prevClickedPort = this->container->getProjectArea()->getClickedPort();
  NodePortWidget* newClickedPort = nullptr == prevClickedPort ? this : nullptr;
  if (nullptr != prevClickedPort) {
    prevClickedPort->getPort()->connect(this->getPort());
    this->container->getProjectArea()->getConnectionsWidget()->Refresh();
  }
  this->container->getProjectArea()->setClickedPort(newClickedPort);
  this->Refresh();
}

void NodePortWidget::onRightMouseDown(wxMouseEvent& evt)
{
  if(!(this->port->isInput() && this->port->getConnectionsCount() > 0))
  {
    return;
  }

  this->port->deleteConnection(0);
  this->container->getProjectArea()->getConnectionsWidget()->Refresh();
}

Gale::Port* NodePortWidget::getPort()
{
  return this->port;
}

NodeContainerWidget* NodePortWidget::getContainer()
{
  return this->container;
}

int NodePortWidget::getPinCenterX()
{
  return this->getPinX() + PORT_WIDTH / 2;
}

int NodePortWidget::getPinCenterY()
{
  return PORT_HEIGHT / 2;
}

wxPoint NodePortWidget::getPinCenter()
{
  return wxPoint(this->getPinCenterX(), this->getPinCenterY());
}

int NodePortWidget::getPinX()
{
  return this->port->isInput() ? 0 : this->GetSize().x - PORT_WIDTH;
}

void NodePortWidget::setDimensions(wxPaintDC* dc)
{
  wxCoord w, h;
  dc->GetTextExtent(this->port->getName(), &w, &h, NULL, NULL, &fontNodePortName);
  this->textWidth = w;
  int totalWidth = PORT_WIDTH + 3 + this->textWidth;
  this->SetSize(wxSize(totalWidth, PORT_HEIGHT));

  this->SetPosition(wxPoint(port->isInput() ? 0 : this->container->GetSize().x - totalWidth,
                            this->getPortY()));

  this->areDimensionsSet = true;
}

void NodePortWidget::onMouseMove(wxMouseEvent& evt)
{
  // NewConnectionWidget* widget = this->container->getProjectArea()->getNewConnectionWidget();
  // if (widget->getClickedPort() == nullptr)
  // {
  //     return;
  // }

  // widget->Refresh();
}

int NodePortWidget::getPortY()
{
    return this->index*(PORT_WIDTH+PAD_PORTS) + PAD_VERTICAL;
}

BEGIN_EVENT_TABLE(NodePortWidget, wxWindow)
  EVT_PAINT(NodePortWidget::paintEvent)
  EVT_LEFT_DOWN(NodePortWidget::onLeftMouseDown)
  EVT_MOTION(NodePortWidget::onMouseMove)
  EVT_RIGHT_DOWN(NodePortWidget::onRightMouseDown)
END_EVENT_TABLE()