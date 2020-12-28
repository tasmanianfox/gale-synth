#include "node_container_widget.hpp"

wxColour darkGreen(0, 128, 0);
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
  dc.SetPen(wxPen(darkGreen));
  dc.SetBrush(wxBrush(darkGreen));
  int portMargin = 3 + PORT_WIDTH;
  int textWithMargin = this->textWidth + portMargin;
  dc.DrawRectangle(wxRect(this->getPinX(), 0, PORT_WIDTH, PORT_HEIGHT));

  // Port name
  dc.SetFont(fontNodePortName);
  int left = this->port->isInput() ? PORT_WIDTH+3 : this->GetSize().x - textWithMargin;
  dc.DrawText(this->port->getName(), wxPoint(left, 0));
}

// TODO: REMOVE
// bool NodePortWidget::on_button_pressed(GdkEventButton* button_event)
// {
//   if (3 == button_event->button && this->port->isInput() && this->port->getConnectionsCount() > 0)
//   {
//     Gale::Connection* connection = this->port->getConnection(0);
//     delete connection;
//     this->container->redrawProjectArea();
//   }

//   return true; 
// }

Gale::Port* NodePortWidget::getPort()
{
  return this->port;
}

int NodePortWidget::getPinCenterX()
{
  return this->getPinX() + PORT_WIDTH / 2;
}

int NodePortWidget::getPinCenterY()
{
  return PORT_HEIGHT / 2;
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

int NodePortWidget::getPortY()
{
    return this->index*(PORT_WIDTH+PAD_PORTS) + PAD_VERTICAL;
}

BEGIN_EVENT_TABLE(NodePortWidget, wxWindow)
    EVT_PAINT(NodePortWidget::paintEvent)
END_EVENT_TABLE()