#include "project_node.hpp"

ProjectNode::ProjectNode(Gale::Node* node) :
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

vector<Gale::Port*> ProjectNode::getInputPorts()
{
  return this->node->getInputPorts();
}

vector<Gale::Port*> ProjectNode::getOutputPorts()
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

Gale::Node* ProjectNode::getNode()
{
  return this->node;
}