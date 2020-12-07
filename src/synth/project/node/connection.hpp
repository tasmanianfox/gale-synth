#ifndef _GALE_SYNTH_PROJECT_NODE_CONNECTION_H_
#define _GALE_SYNTH_PROJECT_NODE_CONNECTION_H_

class Port;

/**
 * Connects two ports
 */
class Connection
{
public:
    Connection(Port* output, Port* input); // plugins are connected from OUTPUT to INPUT
private:
    Port* input;
    Port* output;
};

#endif