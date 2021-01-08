#ifndef _GALE_GUI_WINDOWS_WINDOW_MAIN_NEW_CONNECTION_WIDGET_H_
#define _GALE_GUI_WINDOWS_WINDOW_MAIN_NEW_CONNECTION_WIDGET_H_

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "gui/windows/window_main/node_port_widget.hpp"

class ProjectArea;

/**
 * Renders a new connection for Drag and Drop operation on port
 * Implemented as a separate widget to avoid refreshing of all connections on mouse move
 */
class NewConnectionWidget : public wxWindow
{
public:
    NewConnectionWidget(ProjectArea* projectArea);

    void setClickedPort(NodePortWidget* widget);
    NodePortWidget* getClickedPort();
private:
    ProjectArea* projectArea;

    NodePortWidget* clickedPort;
    wxPen penNewLine;

    void paintEvent(wxPaintEvent& evt);

    DECLARE_EVENT_TABLE()
};

#endif