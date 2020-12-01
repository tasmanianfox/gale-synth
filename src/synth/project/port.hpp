#ifndef _GALE_SYNTH_PROJECT_PORT_H_
#define _GALE_SYNTH_PROJECT_PORT_H_

#include <vector>

// #include "connection.hpp"

using namespace std;

enum PortType { INPUT, OUTPUT };

/**
 * Either an input or output of node
 */
class Port
{
public:
    Port(PortType type);
protected:
    PortType type;
};

#endif