#ifndef _GALE_SYNTH_CORE_NODE_PORT_H_
#define _GALE_SYNTH_CORE_NODE_PORT_H_

#include <string>
#include <vector>

#include "connection.hpp"

using namespace std;

namespace Gale
{

class Node;

enum PortType { INPUT, OUTPUT };

/**
 * Either an input or output of node
 */
class Port
{
public:
    Port(Node* node, PortType type, const char* name);
    
    Connection* connect(Port* otherPort);

    PortType getType();
    string getName();
    bool isInput();
    void _addConnection(Connection* connection);
    // invoked from connection. Should NOT call a destructor for connection
    void _removeConnection(Connection* connection);
    vector<Connection*> getConnections();
    Connection* getConnection(int index);
    unsigned short int getConnectionsCount();
    Node* getNode();
protected:
    Node* node;
    PortType type;
    string name;

    vector<Connection*> connections;
};

}

#endif