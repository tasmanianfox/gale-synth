#ifndef _GALE_CORE_PROJECT_PROJECT_H_
#define _GALE_CORE_PROJECT_PROJECT_H_

#include <vector>

#include "core/project/node/node.hpp"
#include "core/project/pipeline.hpp"

using namespace std;

namespace Gale::Core
{

class Project
{
public:
    Project();

    void refresh();
    node_id generateNodeId();

    void addNode(Node* node);
    Pipeline* getPipelinePtr();
private:
    vector<Node*> nodes;
    Pipeline pipeline;
    node_id last_node_id;
};

}

#endif