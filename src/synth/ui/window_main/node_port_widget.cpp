#include "node_container_widget.hpp"

NodePortWidget::NodePortWidget(NodeContainerWidget* container, Gale::Port* port) :
    wxControl(),
    container(container),
    port(port)
{
    // TODO: REMOVE
    // Pango::FontDescription font;
    // font.set_family("Monospace");
    // font.set_weight(Pango::WEIGHT_BOLD);
    // font.set_size(8*PANGO_SCALE);
    // this->labelName = create_pango_layout(this->port->getName().c_str());
    // this->labelName->set_font_description(font);

    // this->set_events(Gdk::BUTTON_PRESS_MASK);
    // this->signal_button_press_event().connect(sigc::mem_fun(this, &NodePortWidget::on_button_pressed));
}

// TODO: REMOVE
// bool NodePortWidget::on_draw(const Cairo::RefPtr<Cairo::Context>& cr)
// {
//     const Gtk::Allocation allocation = get_allocation();
//     cr->set_source_rgb(0.0, 0.5, 0.0);

//     int text_width;
//     int text_height;
//     this->labelName->get_pixel_size(text_width, text_height);

//     int leftLabel = this->port->isInput() ? PORT_WIDTH+3 : allocation.get_width() - text_width - 3 - PORT_WIDTH;

//     cr->rectangle(this->getPinX(), 0, PORT_WIDTH, PORT_HEIGHT);
//     cr->fill();

//     Pango::FontDescription font;
//     font.set_family("Monospace");
//     font.set_weight(Pango::WEIGHT_BOLD);
//     font.set_size(8*PANGO_SCALE);
//     Glib::RefPtr<Pango::Layout> layout = create_pango_layout(this->port->getName().c_str());
//     layout->set_font_description(font);
//     cr->move_to(leftLabel, 0);
//     layout->show_in_cairo_context(cr);

//     return true;
// }

// void NodePortWidget::on_realize()
// {
//   set_realized();

//   if(m_refGdkWindow)
//     return;

//   GdkWindowAttr attributes;
//   memset(&attributes, 0, sizeof(attributes));

//   Gtk::Allocation allocation = get_allocation();

//   //Set initial position and size of the Gdk::Window:
//   attributes.x = allocation.get_x();
//   attributes.y = allocation.get_y();
//   attributes.width = allocation.get_width();
//   attributes.height = allocation.get_height();

//   attributes.event_mask = get_events () | Gdk::EXPOSURE_MASK;
//   attributes.window_type = GDK_WINDOW_CHILD;
//   attributes.wclass = GDK_INPUT_OUTPUT;

//   m_refGdkWindow = Gdk::Window::create(get_parent_window(), &attributes,
//           GDK_WA_X | GDK_WA_Y);
//   set_window(m_refGdkWindow);

//   //make the widget receive expose events
//   m_refGdkWindow->set_user_data(gobj());
// }

// void NodePortWidget::on_unrealize()
// {
//   m_refGdkWindow.reset();
//   Gtk::Widget::on_unrealize();
// }

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

// void NodePortWidget::get_preferred_width_vfunc(int& minimum_width, int& natural_width) const
// {
//   int text_width;
//   int text_height;
//   this->labelName->get_pixel_size(text_width, text_height);

//   minimum_width = natural_width = text_width + NAME_MARGIN_HORIZONTAL*2;
// }

// void NodePortWidget::get_preferred_height_vfunc(int& minimum_height, int& natural_height) const
// {
//   minimum_height = natural_height = PORT_HEIGHT;
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
  return 0;
  //return this->port->isInput() ? 0 : get_allocation().get_width() - PORT_WIDTH; TODO: REMOVE
}