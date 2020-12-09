#ifndef _GALE_SYNTH_UI_WINDOW_MAIN_PROJECT_AREA_H_
#define _GALE_SYNTH_UI_WINDOW_MAIN_PROJECT_AREA_H_

#include <gtkmm.h>

#include "synth/app/project/project.hpp"

class ProjectArea : public Gtk::Fixed
{
public:
    ProjectArea();
    ProjectArea(Project *project);

    bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;
private:
    Project *project;
};

#endif