#ifndef _GALE_SYNTH_UI_WINDOW_MAIN_NODE_PORT_WIDGET_H_
#define _GALE_SYNTH_UI_WINDOW_MAIN_NODE_PORT_WIDGET_H_

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "synth/core/node/port.hpp"
#include "synth/ui/window_main/constants.hpp"

class NodeContainerWidget;

class NodePortWidget : public wxWindow
{
public:
    NodePortWidget(NodeContainerWidget* container, int index, Gale::Port* port);

    Gale::Port* getPort();
    int getPinCenterX();
    int getPinCenterY();
private:
    NodeContainerWidget* container;
    Gale::Port* port;

    int index; // port inddex in widget input / output side
    bool areDimensionsSet; // FALSE on widget creation, TRUE after configuration
    int textWidth;

    void setDimensions(wxPaintDC* dc);

    void onRightMouseDown(wxMouseEvent& evt);
    void paintEvent(wxPaintEvent& evt);

    int getPinX();
    int getPortY();

    DECLARE_EVENT_TABLE()
};

#endif