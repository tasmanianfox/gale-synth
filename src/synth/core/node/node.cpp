#include "node.hpp"

Node::Node(const char* name) : Gtk::Widget()
{
    // this->ports = vector<Port*>();
    // this->inputPorts = vector<Port*>();
    // this->outputPorts = vector<Port*>();
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

vector<Port*> Node::getOutputPorts()
{
  return this->outputPorts;
}