#ifndef _GALE_CORE_PROJECT_NODE_CONNECTION_H_
#define _GALE_CORE_PROJECT_NODE_CONNECTION_H_

namespace Gale::Core
{

class Port;

/**
 * Connects two ports
 */
class Connection
{
public:
    Connection(Port* output, Port* input); // plugins are connected from OUTPUT to INPUT
    ~Connection();

    Port* getInput();
    Port* getOutput();
private:
    Port* input;
    Port* output;
};

}

#endif