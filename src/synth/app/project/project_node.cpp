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

vector<Port*> ProjectNode::getOutputPorts()
{
  return this->node->getOutputPorts();
}