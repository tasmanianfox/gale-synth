#include "project_node.hpp"

ProjectNode::ProjectNode(Gale::Core::Node* node) :
  x(0),
  y(0),
  node(node)
{

}

ProjectNode::~ProjectNode()
{
    delete this->node;
}

void ProjectNode::setPosition(int x, int y)
{
  this->x = x;
  this->y = y;
}

vector<Gale::Core::Port*> ProjectNode::getPorts()
{
  return this->node->getPorts();
}

vector<Gale::Core::Port*> ProjectNode::getInputPorts()
{
  return this->node->getInputPorts();
}

vector<Gale::Core::Port*> ProjectNode::getOutputPorts()
{
  return this->node->getOutputPorts();
}

int ProjectNode::getX()
{
  return this->x;
}

int ProjectNode::getY()
{
  return this->y;
}

Gale::Core::Node* ProjectNode::getNode()
{
  return this->node;
}

Gale::Core::Connection* ProjectNode::connect(const char* myPortName, ProjectNode* otherNode, const char* otherPortName)
{
    Gale::Core::Port* myPort = this->getNode()->getPort(myPortName);
    Gale::Core::Port* otherPort = otherNode->getNode()->getPort(otherPortName);

    return myPort->connect(otherPort);
}