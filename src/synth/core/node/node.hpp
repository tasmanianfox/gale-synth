#ifndef _GALE_SYNTH_CORE_NODE_NODE_H_
#define _GALE_SYNTH_CORE_NODE_NODE_H_

#include <algorithm>
#include <string>
#include <vector>

#include "port.hpp"

using namespace std;

namespace Gale
{

/**
 * Nodes: wave generators, processors, mixers, effects, etc
 */
class Node
{
public:
    Node(const char* name);
    ~Node();

    Port* getPort(const char* name);
    vector<Port*> getPorts();
    vector<Port*> getInputPorts();
    vector<Port*> getOutputPorts();
    int getInputPortIndex(Port* port);
    string getName();
protected:
    vector<Port*> ports;
    vector<Port*> inputPorts;
    vector<Port*> outputPorts;
    string name;

    void addPort(Port* p);
};

}

#endif