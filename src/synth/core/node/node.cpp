#include "node.hpp"

using namespace Gale;

Node::Node(const char* name)
{
    this->name = string(name);
}

Node::~Node()
{
  for (int i = 0; i < this->ports.size(); i++)
  {
    delete this->ports.at(i);
  }
}

void Node::addPort(Port* p)
{
  this->ports.push_back(p);
  if (p->isInput())
  {
    this->inputPorts.push_back(p);
  } 
  else 
  {
    this->outputPorts.push_back(p);
  }
}

Port* Node::getPort(const char* name)
{
  for(Port* port: this->ports) {
      if (port->getName().compare(name) == 0)
      {
        return port;
      }
  }
  return nullptr;
}

vector<Port*> Node::getInputPorts()
{
  return this->inputPorts;
}

vector<Port*> Node::getOutputPorts()
{
  return this->outputPorts;
}

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

string Node::getName()
{
  return this->name;
}