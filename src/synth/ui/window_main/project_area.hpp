#ifndef _GALE_SYNTH_UI_WINDOW_MAIN_PROJECT_AREA_H_
#define _GALE_SYNTH_UI_WINDOW_MAIN_PROJECT_AREA_H_

#include <vector>

#include <gtkmm.h>

#include "synth/app/project/project.hpp"
#include "synth/app/project/project_node.hpp"
#include "synth/ui/window_main/constants.hpp"
#include "synth/ui/window_main/node_container_widget.hpp"

using namespace std;

class ProjectArea : public Gtk::Fixed
{
public:
    ProjectArea(Project *project);

    void addNode(ProjectNode* node);

    bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;
private:
    Project *project;
    vector<NodeContainerWidget*> nodes;

    NodeContainerWidget* getNodeContainerWidget(Gale::Node* node);
};

#endif