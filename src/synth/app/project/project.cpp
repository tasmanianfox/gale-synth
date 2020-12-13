#include "project.hpp"

#include "synth/core/node/output/stream_output.hpp" // temporary
#include "synth/core/node/oscillator/simple_oscillator.hpp" // temporary
#include <iostream> // TODO: REMOVEME


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
    Gale::Node* n1 = new Gale::SimpleOscillator();
    ProjectNode* node1 = new ProjectNode(n1);
    node1->setPosition(50, 300);
    this->addNode(node1);

    Gale::Node *n2 = new Gale::StreamOutput();
    ProjectNode* node2 = new ProjectNode(n2);
    node2->setPosition(300, 300);
    this->addNode(node2);

    Gale::Port* oscOut = n1->getPort("OUT");
    Gale::Port* in1 = n2->getPort("IN_L");
    Gale::Port* in2 = n2->getPort("IN_R");

    oscOut->connect(in1);
    oscOut->connect(in2);

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