#ifndef _GALE_GUI_APP_PROJECT_PROJECT_NODE_H_
#define _GALE_GUI_APP_PROJECT_PROJECT_NODE_H_

#include <vector>

#include "core/project/node/node.hpp"
#include "core/project/node/port.hpp"

using namespace std;

class ProjectNode
{
public:
    ProjectNode(Gale::Core::Node* node);
    ~ProjectNode();

    Gale::Core::Connection* connect(const char* myPortName, ProjectNode* otherNode, const char* otherPortName);

    void setPosition(int x, int y);
    int getX();
    int getY();
    vector<Gale::Core::Port*> getPorts();
    vector<Gale::Core::Port*> getInputPorts();
    vector<Gale::Core::Port*> getOutputPorts();
    Gale::Core::Node* getNode();
private:
    Gale::Core::Node* node;

    int x;
    int y;
};

#endif