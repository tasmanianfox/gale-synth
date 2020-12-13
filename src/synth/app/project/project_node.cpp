#include "project_node.hpp"

ProjectNode::ProjectNode(Node* node) :
  x(0),
  y(0)
{
    this->node = node;
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

vector<Port*> ProjectNode::getInputPorts()
{
  return this->node->getInputPorts();
}

vector<Port*> ProjectNode::getOutputPorts()
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

Node* ProjectNode::getNode()
{
  return this->node;
}