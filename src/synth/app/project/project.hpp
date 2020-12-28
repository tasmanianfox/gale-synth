#ifndef _GALE_SYNTH_APP_PROJECT_PROJECT_H_
#define _GALE_SYNTH_APP_PROJECT_PROJECT_H_

#include <vector>

#include "project_node.hpp"

#include "synth/core/project.hpp"

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
public:
    void addNode(ProjectNode* node);
    vector<ProjectNode*> getNodes();

protected:
    vector<ProjectNode*> nodes;
private:
    Gale::Project* project;
};

#endif