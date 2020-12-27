#ifndef _GALE_SYNTH_UI_WINDOW_MAIN_NODE_PORT_WIDGET_H_
#define _GALE_SYNTH_UI_WINDOW_MAIN_NODE_PORT_WIDGET_H_

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "synth/core/node/port.hpp"
#include "synth/ui/window_main/constants.hpp"

class NodeContainerWidget;

class NodePortWidget : public wxControl
{
public:
    NodePortWidget(NodeContainerWidget* container, Gale::Port* port);

    // void get_preferred_width_vfunc(int& minimum_width, int& natural_width) const override; TODO: REMOVE
    Gale::Port* getPort();
    int getPinCenterX();
    int getPinCenterY();
private:
    NodeContainerWidget* container;
    Gale::Port* port;

    // TODO: REMOVE
    // void get_preferred_height_vfunc(int& minimum_height, int& natural_height) const override;
    // void on_realize();
    // void on_unrealize();
    // bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;
    // bool on_button_pressed(GdkEventButton* button_event);

    int getPinX();

    // TODO: REMOVE
    // Glib::RefPtr<Gdk::Window> m_refGdkWindow;
    // Glib::RefPtr<Pango::Layout> labelName;
};

#endif