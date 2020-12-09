#ifndef _GALE_SYNTH_UI_WINDOW_MAIN_NODE_WIDGET_H_
#define _GALE_SYNTH_UI_WINDOW_MAIN_NODE_WIDGET_H_

#include <string>

#include <gtkmm/widget.h>

using namespace std;

struct node_draw_context
{
    const Cairo::RefPtr<Cairo::Context>& cr;
    const int width;
    const int height;
};

class NodeWidget : public Gtk::Widget
{
public:
    NodeWidget(Node* node);
    ~NodeWidget();

    int getInputPortMiddleX(int index);
    int getInputPortMiddleY(int index);
    int getInputPortIndex(Port* port);
    int getOutputPortMiddleX(int index);
    int getOutputPortMiddleY(int index);
private:
    Node* node;
    string name;

    Glib::RefPtr<Pango::Layout> labelName;

    bool on_button_pressed(GdkEventButton* button_event);
    bool on_button_released(GdkEventButton* release_event);

    void get_preferred_width_vfunc(int& minimum_width, int& natural_width) const override;
    void get_preferred_height_vfunc(int& minimum_height, int& natural_height) const override;
    void on_realize();
    void on_unrealize();
    bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;
    Glib::RefPtr<Gdk::Window> m_refGdkWindow;

    void draw_name(node_draw_context* context);
    void draw_ports(node_draw_context* context);
    void draw_outer_box(node_draw_context* context);

    int getInputPortX(int index);
    int getInputPortY(int index);
    int getOutputPortX(int index);
    int getOutputPortY(int index);
};

#endif