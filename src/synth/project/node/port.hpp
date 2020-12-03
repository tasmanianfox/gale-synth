#ifndef _GALE_SYNTH_PROJECT_NODE_PORT_H_
#define _GALE_SYNTH_PROJECT_NODE_PORT_H_

#include <string>
#include <vector>

using namespace std;

enum PortType { INPUT, OUTPUT };

/**
 * Either an input or output of node
 */
class Port
{
public:
    Port(PortType type, const char* name);
    PortType getType();
protected:
    PortType type;
    string name;
};

#endif