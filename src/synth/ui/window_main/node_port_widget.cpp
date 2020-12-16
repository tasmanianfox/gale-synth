#include "node_container_widget.hpp"

const int PORT_WIDTH = 10;
const int PORT_HEIGHT = 10;
const int NAME_MARGIN_HORIZONTAL = 10;

NodePortWidget::NodePortWidget(Gale::Port* port) :
    Gtk::Widget(),
    Glib::ObjectBase("gale_node_port"),
    port(port)
{
    Pango::FontDescription font;
    font.set_family("Monospace");
    font.set_weight(Pango::WEIGHT_BOLD);
    font.set_size(8*PANGO_SCALE);
    this->labelName = create_pango_layout(this->port->getName().c_str());
    this->labelName->set_font_description(font);
}

bool NodePortWidget::on_draw(const Cairo::RefPtr<Cairo::Context>& cr)
{
    const Gtk::Allocation allocation = get_allocation();
    cr->set_source_rgb(0.0, 0.5, 0.0);

    int text_width;
    int text_height;
    this->labelName->get_pixel_size(text_width, text_height);

    int leftLabel = this->port->isInput() ? 0 : allocation.get_width() - PORT_WIDTH;
    int leftPort = this->port->isInput() ? PORT_WIDTH+3 : allocation.get_width() - text_width - 3 - PORT_WIDTH;

    cr->rectangle(leftLabel, 0, PORT_WIDTH, PORT_HEIGHT);
    cr->fill();

    Pango::FontDescription font;
    font.set_family("Monospace");
    font.set_weight(Pango::WEIGHT_BOLD);
    font.set_size(8*PANGO_SCALE);
    Glib::RefPtr<Pango::Layout> layout = create_pango_layout(this->port->getName().c_str());
    layout->set_font_description(font);
    cr->move_to(leftPort, 0);
    layout->show_in_cairo_context(cr);

    return true;
}

void NodePortWidget::on_realize()
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

void NodePortWidget::on_unrealize()
{
  m_refGdkWindow.reset();
  Gtk::Widget::on_unrealize();
}

void NodePortWidget::get_preferred_width_vfunc(int& minimum_width, int& natural_width) const
{
    int text_width;
    int text_height;
    this->labelName->get_pixel_size(text_width, text_height);

    minimum_width = natural_width = text_width + NAME_MARGIN_HORIZONTAL*2;
}

void NodePortWidget::get_preferred_height_vfunc(int& minimum_height, int& natural_height) const
{
    minimum_height = natural_height = PORT_HEIGHT;
}