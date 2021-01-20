#include "node.hpp"

using namespace Gale::Core;

Node::Node(int id) :
  id(id) {}

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

vector<Port*> Node::getPorts()
{
  return this->ports;
}

node_id Node::getId() {
  return this->id;
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

int Node::getCode() {
  return NODE_CODE_MISC;
}

const char* Node::getName() {
  return "undefined";
}

bool Node::is(int code) {
  return code == this->getCode();
}