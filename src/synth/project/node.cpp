#include "node.hpp"

#include <iostream>
using namespace std;

Node::Node() : Gtk::Widget(), m_scale(100)
{
    cout << "Node constructor" << endl;
    this->ports = vector<Port>();
}

void Node::on_realize()
{
  set_realized();

  if(!m_refGdkWindow)
  {
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
    override_background_color(Gdk::RGBA("green"));
    override_color(Gdk::RGBA("blue"));

    //make the widget receive expose events
    m_refGdkWindow->set_user_data(gobj());
  }
}

void Node::on_unrealize()
{
  m_refGdkWindow.reset();
  Gtk::Widget::on_unrealize();
}

bool Node::on_draw(const Cairo::RefPtr<Cairo::Context>& cr)
{
    const Gtk::Allocation allocation = get_allocation();
    const double scale_x = (double)allocation.get_width() / m_scale;
    const double scale_y = (double)allocation.get_height() / m_scale;
    auto refStyleContext = get_style_context();

    // paint the background
    refStyleContext->render_background(cr,
        allocation.get_x(), allocation.get_y(),
        allocation.get_width(), allocation.get_height());

    // draw the foreground
    const auto state = refStyleContext->get_state();
    Gdk::Cairo::set_source_rgba(cr, refStyleContext->get_color(state));
    cr->move_to(0.*scale_x, 0.*scale_y);
    cr->line_to(0.*scale_x, 100.*scale_y);
    cr->line_to(100.0*scale_x, 100.*scale_y);
    cr->line_to(100.0*scale_x, 0.*scale_y);
    cr->line_to(0.*scale_x, 0.*scale_y);
    cr->stroke();

    return true;
}

Gtk::SizeRequestMode Node::get_request_mode_vfunc() const
{
  //Accept the default value supplied by the base class.
  return Gtk::Widget::get_request_mode_vfunc();
}

//Discover the total amount of minimum space and natural space needed by
//this widget.
//Let's make this simple example widget always need minimum 60 by 50 and
//natural 100 by 70.
void Node::get_preferred_width_vfunc(int& minimum_width, int& natural_width) const
{
  minimum_width = 60;
  natural_width = 100;
}

void Node::get_preferred_height_for_width_vfunc(int /* width */,
   int& minimum_height, int& natural_height) const
{
  minimum_height = 50;
  natural_height = 70;
}

void Node::get_preferred_height_vfunc(int& minimum_height, int& natural_height) const
{
  minimum_height = 50;
  natural_height = 70;
}

void Node::get_preferred_width_for_height_vfunc(int /* height */,
   int& minimum_width, int& natural_width) const
{
  minimum_width = 60;
  natural_width = 100;
}

void Node::on_size_allocate(Gtk::Allocation& allocation)
{
  //Do something with the space that we have actually been given:
  //(We will not be given heights or widths less than we have requested, though
  //we might get more)

  //Use the offered allocation for this container:
  set_allocation(allocation);

  if(m_refGdkWindow)
  {
    m_refGdkWindow->move_resize( allocation.get_x(), allocation.get_y(),
            allocation.get_width(), allocation.get_height() );
  }
}