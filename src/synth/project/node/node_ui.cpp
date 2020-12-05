#include "node.hpp"

const int PAD_VERTICAL = 25;
const int PAD_PORTS = 10;
const int PORT_WIDTH = 10;
const int PORT_HEIGHT = 10;
const int NAME_MARGIN_HORIZONTAL = 10;

#include <iostream>

void Node::draw_outer_box(node_draw_context* context)
{
    context->cr->set_source_rgb(1.0, 0.0, 0.0);
    context->cr->move_to(0, 0);
    context->cr->line_to(context->width, 0);
    context->cr->line_to(context->width, context->height);
    context->cr->line_to(0, context->height);
    context->cr->line_to(0, 0);
    context->cr->stroke();
}

void Node::draw_ports(node_draw_context* context)
{   
    context->cr->set_source_rgb(0.0, 0.5, 0.0);
    Pango::FontDescription font;
    font.set_family("Monospace");
    font.set_weight(Pango::WEIGHT_BOLD);
    font.set_size(8*PANGO_SCALE);

    for(int i = 0; i < this->inputPorts.size(); i++)
    {
        int y = i*(PORT_WIDTH+PAD_PORTS) + PAD_VERTICAL;
        context->cr->rectangle(.0, y, PORT_WIDTH, PORT_HEIGHT);
        context->cr->fill();

        Port* port = this->inputPorts.at(i);
        Glib::RefPtr<Pango::Layout> layout = create_pango_layout(port->getName().c_str());
        layout->set_font_description(font);
        context->cr->move_to(PORT_WIDTH+3, y);
        layout->show_in_cairo_context(context->cr);
    }

    for(int i = 0; i < this->outputPorts.size(); i++)
    {
        int y = i*(PORT_WIDTH+PAD_PORTS) + PAD_VERTICAL;
        context->cr->rectangle(context->width - PORT_WIDTH, y, PORT_WIDTH, PORT_HEIGHT);
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

void Node::draw_name(node_draw_context* context)
{
    context->cr->set_source_rgb(0.0, 0.0, 0.0);
    context->cr->move_to(NAME_MARGIN_HORIZONTAL, 5);
    this->labelName->show_in_cairo_context(context->cr);
}

bool Node::on_draw(const Cairo::RefPtr<Cairo::Context>& cr)
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

void Node::get_preferred_width_vfunc(int& minimum_width, int& natural_width) const
{
    int text_width;
    int text_height;
    this->labelName->get_pixel_size(text_width, text_height);

    minimum_width = natural_width = text_width + NAME_MARGIN_HORIZONTAL*2;
}

void Node::get_preferred_height_vfunc(int& minimum_height, int& natural_height) const
{
    int maxPorts = max(this->inputPorts.size(), this->outputPorts.size());
    minimum_height = natural_height = 2 * PAD_VERTICAL + maxPorts * PORT_HEIGHT + (maxPorts-1) * PAD_PORTS;
}