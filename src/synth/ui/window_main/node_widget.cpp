#include "node_widget.hpp"

using namespace std;

NodeWidget::NodeWidget(Node* node) : x = 0, y = o
{
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

NodeWidget::~NodeWidget()
{
    delete this->node;
}

void NodeWidget::draw_outer_box(node_draw_context* context)
{
    context->cr->set_source_rgb(1.0, 0.0, 0.0);
    context->cr->move_to(0, 0);
    context->cr->line_to(context->width, 0);
    context->cr->line_to(context->width, context->height);
    context->cr->line_to(0, context->height);
    context->cr->line_to(0, 0);
    context->cr->stroke();
}

void NodeWidget::draw_ports(node_draw_context* context)
{   
    context->cr->set_source_rgb(0.0, 0.5, 0.0);
    Pango::FontDescription font;
    font.set_family("Monospace");
    font.set_weight(Pango::WEIGHT_BOLD);
    font.set_size(8*PANGO_SCALE);

    for(int i = 0; i < this->inputPorts.size(); i++)
    {
        int y = this->getInputPortY(i);
        context->cr->rectangle(this->getInputPortX(i), this->getInputPortY(i), PORT_WIDTH, PORT_HEIGHT);
        context->cr->fill();

        Port* port = this->inputPorts.at(i);
        Glib::RefPtr<Pango::Layout> layout = create_pango_layout(port->getName().c_str());
        layout->set_font_description(font);
        context->cr->move_to(PORT_WIDTH+3, y);
        layout->show_in_cairo_context(context->cr);
    }

    for(int i = 0; i < this->outputPorts.size(); i++)
    {
        int y = this->getOutputPortY(i);
        context->cr->rectangle(this->getOutputPortX(i), this->getOutputPortY(i), PORT_WIDTH, PORT_HEIGHT);
        context->cr->fill();

        
        Port* port = this->outputPorts.at(i);
        Glib::RefPtr<Pango::Layout> layout = create_pango_layout(port->getName().c_str());
        layout->set_font_description(font);

        int text_width;
        int text_height;
        layout->get_pixel_size(text_width, text_height);
        context->cr->move_to(context->width - PORT_WIDTH - 3 - text_width, y);
        layout->show_in_cairo_context(context->cr);
    }
}

void NodeWidget::draw_name(node_draw_context* context)
{
    context->cr->set_source_rgb(0.0, 0.0, 0.0);
    context->cr->move_to(NAME_MARGIN_HORIZONTAL, 5);
    this->labelName->show_in_cairo_context(context->cr);
}

bool NodeWidget::on_draw(const Cairo::RefPtr<Cairo::Context>& cr)
{
    const Gtk::Allocation allocation = get_allocation();
    node_draw_context context = {
        .cr = cr,
        .width = allocation.get_width(),
        .height = allocation.get_height()
    };

    Glib::RefPtr<Gtk::StyleContext> refStyleContext = get_style_context();
    const Gtk::StateFlags state = refStyleContext->get_state();
    Gdk::Cairo::set_source_rgba(cr, refStyleContext->get_color(state));

    this->draw_outer_box(&context);
    this->draw_ports(&context);
    this->draw_name(&context);

    return true;
}

void NodeWidget::on_realize()
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

void NodeWidget::on_unrealize()
{
  m_refGdkWindow.reset();
  Gtk::Widget::on_unrealize();
}

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

void NodeWidget::get_preferred_width_vfunc(int& minimum_width, int& natural_width) const
{
    int text_width;
    int text_height;
    this->labelName->get_pixel_size(text_width, text_height);

    minimum_width = natural_width = text_width + NAME_MARGIN_HORIZONTAL*2;
}

void NodeWidget::get_preferred_height_vfunc(int& minimum_height, int& natural_height) const
{
    int maxPorts = max(this->inputPorts.size(), this->outputPorts.size());
    minimum_height = natural_height = 2 * PAD_VERTICAL + maxPorts * PORT_HEIGHT + (maxPorts-1) * PAD_PORTS;
}

int NodeWidget::getInputPortX(int index)
{
    return 0;
}

int NodeWidget::getInputPortY(int index)
{
    return index*(PORT_WIDTH+PAD_PORTS) + PAD_VERTICAL;
}

int NodeWidget::getOutputPortX(int index)
{
    return this->get_allocation().get_width() - PORT_WIDTH;
}

int NodeWidget::getOutputPortY(int index)
{
    return index*(PORT_WIDTH+PAD_PORTS) + PAD_VERTICAL;
}

int NodeWidget::getInputPortMiddleX(int index)
{
    return this->getInputPortX(index) + PORT_WIDTH / 2;
}

int NodeWidget::getInputPortMiddleY(int index)
{
    return this->getInputPortY(index) + PORT_HEIGHT / 2;
}

int NodeWidget::getOutputPortMiddleX(int index)
{
    return this->getOutputPortX(index) + PORT_WIDTH / 2;
}

int NodeWidget::getOutputPortMiddleY(int index)
{
    return this->getOutputPortY(index) + PORT_HEIGHT / 2;
}