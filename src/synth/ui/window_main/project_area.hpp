#ifndef _GALE_SYNTH_UI_WINDOW_MAIN_PROJECT_AREA_H_
#define _GALE_SYNTH_UI_WINDOW_MAIN_PROJECT_AREA_H_

#include <vector>

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "synth/app/project/project.hpp"
#include "synth/app/project/project_node.hpp"
#include "synth/ui/window_main/connections_widget.hpp"
#include "synth/ui/window_main/constants.hpp"
#include "synth/ui/window_main/node_container_widget.hpp"

using namespace std;

class ProjectArea : public wxControl
{
public:
    ProjectArea(wxWindow *parent, Project *project);
    ~ProjectArea();

    void addNode(ProjectNode* node);
    vector<NodeContainerWidget*> getNodes();
    ConnectionsWidget* getConnectionsWidget();
private:
    Project *project;
    vector<NodeContainerWidget*> nodes;
    ConnectionsWidget* connectionsWidget;
};

#endif