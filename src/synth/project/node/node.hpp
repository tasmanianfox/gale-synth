#ifndef _GALE_SYNTH_PROJECT_NODE_NODE_H_
#define _GALE_SYNTH_PROJECT_NODE_NODE_H_

#include <algorithm>
#include <string>
#include <vector>

#include <gdkmm/general.h> 
#include <gtkmm/widget.h>

#include "port.hpp"

using namespace std;

struct node_draw_context
{
    const Cairo::RefPtr<Cairo::Context>& cr;
    const int width;
    const int height;
};


/**
 * Nodes: wave generators, processors, mixers, effects, etc
 */
class Node : public Gtk::Widget
{
public:
    Node(const char* name);
    ~Node();

    void setPosition(int x, int y);
    Port* getPort(const char* name);
    vector<Port*> getOutputPorts();

    int x;
    int y;
protected:
    vector<Port*> ports;
    vector<Port*> inputPorts;
    vector<Port*> outputPorts;
    string name;
    
    bool on_button_pressed(GdkEventButton* button_event);
    bool on_button_released(GdkEventButton* release_event);

    void get_preferred_width_vfunc(int& minimum_width, int& natural_width) const override;
    void get_preferred_height_vfunc(int& minimum_height, int& natural_height) const override;
    void on_realize();
    void on_unrealize();
    bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;
    Glib::RefPtr<Gdk::Window> m_refGdkWindow;

    void addPort(Port* p);
private:
    Glib::RefPtr<Pango::Layout> labelName;

    void draw_name(node_draw_context* context);
    void draw_ports(node_draw_context* context);
    void draw_outer_box(node_draw_context* context);
};

#endif