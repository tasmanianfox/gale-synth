#include "node.hpp"

const int PAD_VERTICAL = 25;
const int PAD_PORTS = 10;
const int PORT_WIDTH = 10;
const int PORT_HEIGHT = 10;
const int NAME_MARGIN_HORIZONTAL = 10;

#include <iostream>


int Node::getInputPortIndex(Port* port)
{
    for(int i = 0; i < this->inputPorts.size(); i++)
    {
        Port *p = this->inputPorts.at(i);
        if (p->getName() == port->getName())
        {
            return i;
        }
    }

    return -1;
}