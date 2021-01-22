#ifndef _GALE_CORE_PROJECT_NODE_NODE_H_
#define _GALE_CORE_PROJECT_NODE_NODE_H_

#include <algorithm>
#include <string>
#include <vector>

#include "constants.hpp"
#include "port.hpp"
#include "core/project/node/node_play_context.hpp"

using namespace std;

namespace Gale::Core
{

typedef int node_id;

/**
 * Nodes: wave generators, processors, mixers, effects, etc
 */
class Node
{
public:
    Node(int id);
    ~Node();

    // main method for node. Reads inputs,
    // calculates values of outputs
    virtual void play(NodePlayContext* context) = 0; 

    Port* getPort(const char* name);
    vector<Port*> getPorts();
    vector<Port*> getInputPorts();
    vector<Port*> getOutputPorts();
    node_id getId();
    int getInputPortIndex(Port* port);
    virtual int getCode(); // code for internal code
    virtual const char* getName(); // displayable name
    bool is(int code);
protected:
    vector<Port*> ports;
    vector<Port*> inputPorts;
    vector<Port*> outputPorts;

    int id;

    void addPort(Port* p);
};

}

#endif