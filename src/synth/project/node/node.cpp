#include "node.hpp"

Node::Node(const char* name) : Gtk::Widget()
{
    this->ports = vector<Port*>();
    this->inputPorts = vector<Port*>();
    this->outputPorts = vector<Port*>();
    this->name = string(name);
    this->x = this->y = 0;

    Pango::FontDescription font;
    font.set_family("Monospace");
    font.set_weight(Pango::WEIGHT_BOLD);
    font.set_size(8*PANGO_SCALE);
    this->labelName = create_pango_layout(this->name.c_str());
    this->labelName->set_font_description(font);

    this->set_events(Gdk::BUTTON_PRESS_MASK | Gdk::BUTTON_RELEASE_MASK);
    this->signal_button_press_event().connect(sigc::mem_fun(this, &Node::on_button_pressed));
    this->signal_button_release_event().connect(sigc::mem_fun(this, &Node::on_button_released));
}

Node::~Node()
{
  for (int i = 0; i < this->ports.size(); i++)
  {
    delete this->ports.at(i);
  }
}

void Node::on_realize()
{
  set_realized();

  if(m_refGdkWindow)
    return;

  GdkWindowAttr attributes;
  memset(&attributes, 0, sizeof(attributes));

  Gtk::Allocation allocation = get_allocation();

  //Set initial position and size of the Gdk::Window:
  attributes.x = allocation.get_x();
  attributes.y = allocation.get_y();
  attributes.width = allocation.get_width();
  attributes.height = allocation.get_height();

  attributes.event_mask = get_events () | Gdk::EXPOSURE_MASK;
  attributes.window_type = GDK_WINDOW_CHILD;
  attributes.wclass = GDK_INPUT_OUTPUT;

  m_refGdkWindow = Gdk::Window::create(get_parent_window(), &attributes,
          GDK_WA_X | GDK_WA_Y);
  set_window(m_refGdkWindow);

  //make the widget receive expose events
  m_refGdkWindow->set_user_data(gobj());
}

void Node::on_unrealize()
{
  m_refGdkWindow.reset();
  Gtk::Widget::on_unrealize();
}


void Node::addPort(Port* p)
{
  this->ports.push_back(p);
  if (p->isInput())
  {
    this->inputPorts.push_back(p);
  } 
  else 
  {
    this->outputPorts.push_back(p);
  }
}

void Node::setPosition(int x, int y)
{
  this->x = x;
  this->y = y;
}

#include <iostream>
using namespace std;

bool Node::on_button_pressed(GdkEventButton* button_event)
{
  cout << "Clicked!" << endl;
  return true;
}

bool Node::on_button_released(GdkEventButton* release_event)
{
  cout << "Released!" << endl;
  return true;
}

Port* Node::getPort(const char* name)
{
  for(Port* port: this->ports) {
      if (port->getName().compare(name) == 0)
      {
        return port;
      }
  }
  return nullptr;
}