#include "project.hpp"

#include "synth/core/node/output/stream_output.hpp" // temporary
#include "synth/core/node/oscillator/simple_oscillator.hpp" // temporary

Project::Project()
{
    this->project = new Gale::Project();
}

Project::~Project()
{
    delete this->project;
}

void Project::reset() // Temporary. Should be a clean project
{
    delete this->project;
    this->project = new Gale::Project();

    for (int i = 0; i < this->nodes.size(); i++) {
        delete this->nodes.at(i);
    }

    // temporary. Just for demo
    Node* n1 = new SimpleOscillator();
    ProjectNode* node1 = new ProjectNode(n1);
    node1->setPosition(50, 300);
    this->nodes.push_back(node1);

    Node *n2 = new StreamOutput();
    ProjectNode* node2 = new ProjectNode(n2);
    node2->setPosition(300, 300);
    this->nodes.push_back(node2);

    Port* oscOut = n1->getPort("OUT");
    Port* in1 = n2->getPort("IN_L");
    Port* in2 = n2->getPort("IN_R");

    oscOut->connect(in1);
    oscOut->connect(in2);

}