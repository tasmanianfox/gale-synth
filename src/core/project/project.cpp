#include "project.hpp"

using namespace Gale::Core;

Project::Project() :
    last_node_id(0),
    
    pipeline(Pipeline(&this->nodes)) {

}

void Project::refresh() {
    this->pipeline.build();
}

void Project::addNode(Node* node) {
    this->nodes.push_back(node);
}

Pipeline* Project::getPipelinePtr() {
    return &this->pipeline;
}

node_id Project::generateNodeId()
{
    return this->last_node_id++;
}