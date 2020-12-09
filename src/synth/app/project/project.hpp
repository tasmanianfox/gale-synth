#ifndef _GALE_SYNTH_APP_PROJECT_PROJECT_H_
#define _GALE_SYNTH_APP_PROJECT_PROJECT_H_

#include <vector>

#include "project_node.hpp"

#include "synth/core/project.hpp" // TODO: REMOVEME
#include "synth/core/node/node.hpp" // TODO: REMOVEME

using namespace std;

/**
 * 
 */
class Project
{
public:
    Project();
    ~Project();
    void reset();

    vector<ProjectNode*> nodes;
private:
    Gale::Project* project;
};

#endif