#include "node.hpp"

#include <iostream> // REMOVEME
using namespace std;

struct draw_context
{
    const Cairo::RefPtr<Cairo::Context>& cr;
    const double scale_x;
    const double scale_y;
    Node* node;
};


void draw_outer_box(draw_context* context)
{
    context->cr->move_to(0, 0);
    context->cr->line_to(context->scale_x, 0);
    context->cr->line_to(context->scale_x, context->scale_y);
    context->cr->line_to(0, context->scale_y);
    context->cr->line_to(0, 0);
    context->cr->stroke();
}

void draw_ports(draw_context* context)
{
    vector<Port>* ports = context->node->getPorts();
    vector<Port> inputs;
    vector<Port> outputs;
    for(int i = 0; i < context->node->getPorts()->size(); i++)
    {
        Port port = ports->at(i);
        if (port.getType() == PortType::INPUT)
        {
            cout << "Input!" << endl;
            inputs.push_back(port);
        }
        else
        {
            cout << "Output!" << endl;
            outputs.push_back(port);
        }
        
    }

    if (inputs.size())
    {
        cout << "Rendering Input!" << endl;
        context->cr->move_to(context->scale_x*0.1, 0);
        context->cr->line_to(context->scale_x*0.1, context->scale_y);
        context->cr->stroke();

        for(int i = 0; i < inputs.size(); i++)
        {
            context->cr->rectangle(.0, i*20. + 10., context->scale_x*0.1, 10.0);
            context->cr->fill();
            context->cr->stroke();
        }
        
    }
}

bool Node::on_draw(const Cairo::RefPtr<Cairo::Context>& cr)
{
    const Gtk::Allocation allocation = get_allocation();
    const double scale_x = (double)allocation.get_width();
    const double scale_y = (double)allocation.get_height();

    draw_context context = {
        .cr = cr,
        .scale_x = scale_x,
        .scale_y = scale_y,
        .node = this
    };

    Glib::RefPtr<Gtk::StyleContext> refStyleContext = get_style_context();
    const Gtk::StateFlags state = refStyleContext->get_state();
    Gdk::Cairo::set_source_rgba(cr, refStyleContext->get_color(state));

    draw_outer_box(&context);
    draw_ports(&context);

    return true;
}