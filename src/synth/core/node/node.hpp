#ifndef _GALE_SYNTH_CORE_NODE_NODE_H_
#define _GALE_SYNTH_CORE_NODE_NODE_H_

#include <algorithm>
#include <string>
#include <vector>

#include <gdkmm/general.h> 
#include <gtkmm/widget.h>

#include "port.hpp"

using namespace std;

/**
 * Nodes: wave generators, processors, mixers, effects, etc
 */
class Node : public Gtk::Widget
{
public:
    Node(const char* name);
    ~Node();

    Port* getPort(const char* name);
    vector<Port*> getOutputPorts();
protected:
    vector<Port*> ports;
    vector<Port*> inputPorts;
    vector<Port*> outputPorts;
    string name;

    void addPort(Port* p);
};

#endif