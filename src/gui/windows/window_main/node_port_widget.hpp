#ifndef _GALE_GUI_WINDOWS_WINDOW_MAIN_NODE_PORT_WIDGET_H_
#define _GALE_GUI_WINDOWS_WINDOW_MAIN_NODE_PORT_WIDGET_H_

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "core/node/port.hpp"
#include "gui/windows/window_main/constants.hpp"

class NodeContainerWidget;

class NodePortWidget : public wxWindow
{
public:
    NodePortWidget(NodeContainerWidget* container, int index, Gale::Port* port);

    Gale::Port* getPort();
    NodeContainerWidget* getContainer();
    int getPinCenterX();
    int getPinCenterY();
    wxPoint getPinCenter();
private:
    NodeContainerWidget* container;
    Gale::Port* port;

    int index; // port inddex in widget input / output side
    bool areDimensionsSet; // FALSE on widget creation, TRUE after configuration
    int textWidth;

    void setDimensions(wxPaintDC* dc);

    void onLeftMouseDown(wxMouseEvent& evt);
    void onMouseMove(wxMouseEvent& evt);
    void onRightMouseDown(wxMouseEvent& evt);
    void paintEvent(wxPaintEvent& evt);

    int getPinX();
    int getPortY();

    DECLARE_EVENT_TABLE()
};

#endif