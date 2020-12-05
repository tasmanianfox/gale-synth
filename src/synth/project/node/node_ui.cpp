#include "node.hpp"

const float PAD_VERTICAL = 25.;
const float PAD_PORTS = 10.;
const float PORT_WIDTH = 10.;
const float PORT_HEIGHT = 10.;

void Node::draw_outer_box(node_draw_context* context)
{
    context->cr->move_to(0, 0);
    context->cr->line_to(context->scale_x, 0);
    context->cr->line_to(context->scale_x, context->scale_y);
    context->cr->line_to(0, context->scale_y);
    context->cr->line_to(0, 0);
    context->cr->stroke();
}

void Node::draw_ports(node_draw_context* context)
{;
    vector<Port> inputs;
    vector<Port> outputs;
    for(int i = 0; i < this->ports.size(); i++)
    {
        Port port = this->ports.at(i);
        if (port.getType() == PortType::INPUT)
        {
            inputs.push_back(port);
        }
        else
        {
            outputs.push_back(port);
        }
        
    }

    if (inputs.size())
    {
        for(int i = 0; i < inputs.size(); i++)
        {
            context->cr->rectangle(.0, i*(PORT_WIDTH+PAD_PORTS) + PAD_VERTICAL, PORT_WIDTH, PORT_HEIGHT);
            context->cr->fill();
            context->cr->stroke();
        }
        
    }
}

void Node::draw_name(node_draw_context* context)
{
  Pango::FontDescription font;
  font.set_family("Monospace");
  font.set_weight(Pango::WEIGHT_BOLD);
  font.set_size(8*PANGO_SCALE);
  Glib::RefPtr<Pango::Layout> layout = create_pango_layout(this->name.c_str());
  layout->set_font_description(font);

  context->cr->move_to(context->scale_x*0.15, 5);

  layout->show_in_cairo_context(context->cr);
}

bool Node::on_draw(const Cairo::RefPtr<Cairo::Context>& cr)
{
    const Gtk::Allocation allocation = get_allocation();
    const double scale_x = (double)allocation.get_width();
    const double scale_y = (double)allocation.get_height();

    node_draw_context context = {
        .cr = cr,
        .scale_x = scale_x,
        .scale_y = scale_y
    };

    Glib::RefPtr<Gtk::StyleContext> refStyleContext = get_style_context();
    const Gtk::StateFlags state = refStyleContext->get_state();
    Gdk::Cairo::set_source_rgba(cr, refStyleContext->get_color(state));

    this->draw_outer_box(&context);
    this->draw_ports(&context);
    this->draw_name(&context);

    return true;
}

void Node::get_preferred_width_vfunc(int& minimum_width, int& natural_width) const
{
  minimum_width = 140;
  natural_width = 140;
}

void Node::get_preferred_height_vfunc(int& minimum_height, int& natural_height) const
{
  minimum_height = 50;
  natural_height = 50;
}