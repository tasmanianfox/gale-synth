#include "project.hpp"

using namespace Gale::Core;

void Project::addNode(Node* node)
{
    this->nodes.push_back(node);
}