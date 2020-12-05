#include "node.hpp"

Node::Node(const char* name) : Gtk::Widget()
{
    this->ports = vector<Port>();
    this->name = string(name);
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

  //set colors
  this->override_color(Gdk::RGBA("blue"));

  //make the widget receive expose events
  m_refGdkWindow->set_user_data(gobj());
}

void Node::on_unrealize()
{
  m_refGdkWindow.reset();
  Gtk::Widget::on_unrealize();
}


void Node::addPort(Port p)
{
  this->ports.push_back(p);
}