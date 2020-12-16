#ifndef _GALE_SYNTH_UI_WINDOW_MAIN_NODE_PORT_WIDGET_H_
#define _GALE_SYNTH_UI_WINDOW_MAIN_NODE_PORT_WIDGET_H_

#include <gdkmm/general.h>
#include <gtkmm/widget.h>

#include "synth/core/node/port.hpp"

class NodePortWidget : public Gtk::Widget
{
public:
    NodePortWidget(Gale::Port* port);
private:
    Gale::Port* port;
};

#endif