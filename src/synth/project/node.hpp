#ifndef _GALE_SYNTH_PROJECT_NODE_H_
#define _GALE_SYNTH_PROJECT_NODE_H_

#include <vector>

#include <gdkmm/general.h> 
#include <gtkmm/widget.h>

#include "port.hpp"

using namespace std;

/**
 * Nodes: wave generators, processors, mixers, effects, etc
 */
class Node : public Gtk::Widget
{
public:
    Node();
protected:
    int m_scale;

    vector<Port> ports;
    
    Gtk::SizeRequestMode get_request_mode_vfunc() const override;
    void get_preferred_width_vfunc(int& minimum_width, int& natural_width) const override;
    void get_preferred_height_for_width_vfunc(int width, int& minimum_height, int& natural_height) const  override;
    void get_preferred_height_vfunc(int& minimum_height, int& natural_height) const override;
    void get_preferred_width_for_height_vfunc(int height, int& minimum_width, int& natural_width) const override;
    void on_size_allocate(Gtk::Allocation& allocation) override;
    virtual void on_realize();
    virtual void on_unrealize();
    bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;
    Glib::RefPtr<Gdk::Window> m_refGdkWindow;

    // void on_realize() override;
};

#endif