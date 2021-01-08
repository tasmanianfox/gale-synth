#ifndef _GALE_GUI_WINDOWS_WINDOW_MAIN_NODE_WIDGET_H_
#define _GALE_GUI_WINDOWS_WINDOW_MAIN_NODE_WIDGET_H_

#include <string>

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "gui/app/project/project_node.hpp"
#include "core/project/node/port.hpp"

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

    int getInputPortIndex(Gale::Core::Port* port);
    ProjectNode* getNode();

    wxSize calculateSize();

    Gale::Core::Connection* connect(const char* myPortName, NodeWidget* otherNode, const char* otherPortName);
private:
    NodeContainerWidget* container;
    ProjectNode* node;

    DECLARE_EVENT_TABLE()
};

#endif