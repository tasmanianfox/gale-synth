#ifndef _GALE_SYNTH_PROJECT_NODE_CONNECTION_H_
#define _GALE_SYNTH_PROJECT_NODE_CONNECTION_H_

class Port;

/**
 * Connects two ports
 */
class Connection
{
private:
    Port* firstPort;
    Port* secondPort;
};

#endif