#ifndef _GALE_SYNTH_PROJECT_NODE_PORT_H_
#define _GALE_SYNTH_PROJECT_NODE_PORT_H_

#include <string>
#include <vector>

#include "connection.hpp"

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
    string getName();

    bool isInput();

    void _addConnection(Connection* connection);
    Connection* connect(Port* otherPort);
    unsigned short int getConnectionsCount();
protected:
    PortType type;
    string name;

    vector<Connection*> connections;
};

#endif