#ifndef _GALE_CORE_PROJECT_NODE_PORT_H_
#define _GALE_CORE_PROJECT_NODE_PORT_H_

#include <string>
#include <vector>

#include "connection.hpp"

using namespace std;

namespace Gale::Core
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
    bool isOutput();
    void _addConnection(Connection* connection);
    // invoked from connection. Should NOT call a destructor for connection
    void _removeConnection(Connection* connection);
    vector<Connection*> getConnections();
    Connection* getConnection(int index);
    void deleteConnection(int index);
    unsigned short int getConnectionsCount();
    Node* getNode();
    float getValue();
    void setOutputValue(float value); // setter for output ports
    void setInputValue(float value); // setter for input ports
protected:
    Node* node;
    PortType type;
    string name;

    float value;

    vector<Connection*> connections;
};

}

#endif