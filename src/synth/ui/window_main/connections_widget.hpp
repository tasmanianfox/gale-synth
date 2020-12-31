#ifndef _GALE_SYNTH_UI_WINDOW_MAIN_CONNECTIONS_WIDGET_H_
#define _GALE_SYNTH_UI_WINDOW_MAIN_CONNECTIONS_WIDGET_H_

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "synth/ui/window_main/node_container_widget.hpp"

class ProjectArea;

/**
 * A widget which renders connections between nodes
 */
class ConnectionsWidget : public wxWindow
{
public:
    ConnectionsWidget(ProjectArea* projectArea);
private:
    ProjectArea* projectArea;

    NodeContainerWidget* getNodeContainerWidget(Gale::Node* node);

    void paintEvent(wxPaintEvent& evt);

    DECLARE_EVENT_TABLE()
};

#endif