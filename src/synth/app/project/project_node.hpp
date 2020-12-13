#ifndef _GALE_SYNTH_APP_PROJECT_PROJECT_NODE_H_
#define _GALE_SYNTH_APP_PROJECT_PROJECT_NODE_H_

#include <vector>

#include "synth/core/node/node.hpp"
#include "synth/core/node/port.hpp"

using namespace std;

class ProjectNode
{
public:
    ProjectNode(Gale::Node* node);
    ~ProjectNode();

    Gale::Connection* connect(const char* myPortName, ProjectNode* otherNode, const char* otherPortName);

    void setPosition(int x, int y);
    int getX();
    int getY();
    vector<Gale::Port*> getInputPorts();
    vector<Gale::Port*> getOutputPorts();
    Gale::Node* getNode();
private:
    Gale::Node* node;

    int x;
    int y;
};

#endif