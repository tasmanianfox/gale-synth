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

class NodeWidget : public wxWindow
{
public:
    NodeWidget(NodeContainerWidget* container, ProjectNode* node);
    ~NodeWidget();

    void onMouseMove(wxMouseEvent& evt);
    void onMouseLeftDown(wxMouseEvent& evt);
    void paintEvent(wxPaintEvent& evt);

    int getInputPortIndex(Gale::Port* port);
    ProjectNode* getNode();

    wxSize calculateSize();

    Gale::Connection* connect(const char* myPortName, NodeWidget* otherNode, const char* otherPortName);
private:
    NodeContainerWidget* container;
    ProjectNode* node;

    DECLARE_EVENT_TABLE()
};

#endif