#ifndef _GALE_SYNTH_UI_WINDOW_MAIN_NODE_CONTAINER_WIDGET_H_
#define _GALE_SYNTH_UI_WINDOW_MAIN_NODE_CONTAINER_WIDGET_H_

#include <vector>

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "synth/app/project/project_node.hpp"
#include "node_port_widget.hpp"
#include "node_widget.hpp"

using namespace std;

class ProjectArea;

class NodeContainerWidget : public wxWindow
{
public:
    NodeContainerWidget(ProjectArea *projectArea, ProjectNode* node);

    void moveMe(wxPoint point);
    void redrawProjectArea();

    vector<NodePortWidget*> getPortWidgets();
    NodePortWidget* getPortWidget(int index);
    NodeWidget* getNodeWidget();
private:
    ProjectNode* node;
    ProjectArea *projectArea;

    NodeWidget nodeWidget;
    vector<NodePortWidget*> nodePortWidgets;
};

#endif