#include "project.hpp"

#include "synth/core/node/output/stream_output.hpp" // temporary
#include "synth/core/node/oscillator/simple_oscillator.hpp" // temporary

Project::Project() :
    project(new Gale::Project())
{
    
}

Project::~Project()
{
    if (this->project != nullptr)
    {
        delete this->project;
    }
}

void Project::reset() // Temporary. Should be a clean project
{
    if (this->project != nullptr)
    {
        delete project;
    }
    this->project = new Gale::Project();

    for (int i = 0; i < this->nodes.size(); i++) {
        delete this->nodes.at(i);
    }

    // temporary. Just for demo
    ProjectNode* node1 = new ProjectNode(new Gale::SimpleOscillator());
    node1->setPosition(50, 300);
    this->addNode(node1);
    ProjectNode* node2 = new ProjectNode(new Gale::StreamOutput());
    node2->setPosition(300, 300);
    this->addNode(node2);

    node1->connect("OUT", node2, "IN_L");
    node1->connect("OUT", node2, "IN_R");
}

void Project::addNode(ProjectNode* node)
{
    this->project->addNode(node->getNode());
    this->nodes.push_back(node);
}

vector<ProjectNode*> Project::getNodes()
{
    return this->nodes;
}