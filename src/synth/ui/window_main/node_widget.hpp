#ifndef _GALE_SYNTH_UI_WINDOW_MAIN_NODE_WIDGET_H_
#define _GALE_SYNTH_UI_WINDOW_MAIN_NODE_WIDGET_H_

#include <string>

#include <gdkmm/general.h>
#include <gtkmm/widget.h>

#include "synth/app/project/project_node.hpp"
#include "synth/core/node/port.hpp"

using namespace std;

class ProjectArea;

struct node_draw_context
{
    const Cairo::RefPtr<Cairo::Context>& cr;
    const int width;
    const int height;
};

class NodeWidget : public Gtk::Widget
{
public:
    NodeWidget(ProjectArea *projectArea, ProjectNode* node);
    ~NodeWidget();

    int getInputPortMiddleX(int index);
    int getInputPortMiddleY(int index);
    int getInputPortIndex(Gale::Port* port);
    ProjectNode* getNode();
    int getOutputPortMiddleX(int index);
    int getOutputPortMiddleY(int index);

    Gale::Connection* connect(const char* myPortName, NodeWidget* otherNode, const char* otherPortName);
private:
    ProjectArea *projectArea;
    ProjectNode* node;

    gdouble drag_start_x;
    gdouble drag_start_y;

    Glib::RefPtr<Pango::Layout> labelName;

    bool on_button_pressed(GdkEventButton* button_event);
    bool on_button_released(GdkEventButton* release_event);
    bool on_mouse_motion(GdkEventMotion* motion_event);

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