#ifndef _GALE_SYNTH_APP_PROJECT_PROJECT_NODE_H_
#define _GALE_SYNTH_APP_PROJECT_PROJECT_NODE_H_

#include <vector>

#include "synth/core/node/node.hpp"
#include "synth/core/node/port.hpp"

using namespace std;

class ProjectNode
{
public:
    ProjectNode(Node* node);
    ~ProjectNode();

    void setPosition(int x, int y);
    vector<Port*> getOutputPorts();
private:
    Node* node;

    int x;
    int y;
};

#endif