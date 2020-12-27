#ifndef _GALE_SYNTH_UI_WINDOW_MAIN_NODE_WIDGET_H_
#define _GALE_SYNTH_UI_WINDOW_MAIN_NODE_WIDGET_H_

#include <string>

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "synth/app/project/project_node.hpp"
#include "synth/core/node/port.hpp"

using namespace std;

class NodeContainerWidget;

class NodeWidget : public wxControl
{
public:
    NodeWidget(NodeContainerWidget* container, ProjectNode* node);
    ~NodeWidget();

    int getInputPortIndex(Gale::Port* port);
    ProjectNode* getNode();
    // void get_preferred_width_vfunc(int& minimum_width, int& natural_width) const override; TODO:REMOVE

    Gale::Connection* connect(const char* myPortName, NodeWidget* otherNode, const char* otherPortName);
private:
    NodeContainerWidget* container;
    ProjectNode* node;

    // gdouble drag_start_x; TODO: REMOVE
    // gdouble drag_start_y;

    // TODO: REMOVE
    // Glib::RefPtr<Pango::Layout> labelName;

    // bool on_button_pressed(GdkEventButton* button_event);
    // bool on_button_released(GdkEventButton* release_event);
    // bool on_mouse_motion(GdkEventMotion* motion_event);

    // void get_preferred_height_vfunc(int& minimum_height, int& natural_height) const override;
    // void on_realize();
    // void on_unrealize();
    // bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;
    // Glib::RefPtr<Gdk::Window> m_refGdkWindow;

    // void draw_name(node_draw_context* context);
    // void draw_outer_box(node_draw_context* context);
};

#endif