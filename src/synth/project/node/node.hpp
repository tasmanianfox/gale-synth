#ifndef _GALE_SYNTH_PROJECT_NODE_NODE_H_
#define _GALE_SYNTH_PROJECT_NODE_NODE_H_

#include <string>
#include <vector>

#include <gdkmm/general.h> 
#include <gtkmm/widget.h>

#include "port.hpp"

using namespace std;

struct node_draw_context
{
    const Cairo::RefPtr<Cairo::Context>& cr;
    const double scale_x;
    const double scale_y;
};


/**
 * Nodes: wave generators, processors, mixers, effects, etc
 */
class Node : public Gtk::Widget
{
public:
    Node(const char* name);
    ~Node();
protected:
    vector<Port*> ports;
    vector<Port*> inputPorts;
    vector<Port*> outputPorts;
    string name;
    
    void get_preferred_width_vfunc(int& minimum_width, int& natural_width) const override;
    void get_preferred_height_vfunc(int& minimum_height, int& natural_height) const override;
    void on_realize();
    void on_unrealize();
    bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;
    Glib::RefPtr<Gdk::Window> m_refGdkWindow;

    void addPort(Port* p);
private:
    void draw_name(node_draw_context* context);
    void draw_ports(node_draw_context* context);
    void draw_outer_box(node_draw_context* context);
};

#endif