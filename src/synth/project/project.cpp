#include "project.hpp"

#include "synth/project/node/output/stream_output.hpp" // temporary
#include "synth/project/node/oscillator/simple_oscillator.hpp" // temporary

void Project::reset()
{
    for (int i = 0; i < this->nodes.size(); i++) {
        delete this->nodes.at(i);
    }

    // temporary. Just for demo
    Node* node1 = new SimpleOscillator();
    node1->setPosition(50, 300);
    this->nodes.push_back(node1);

    Node* node2 = new StreamOutput();
    node2->setPosition(300, 300);
    this->nodes.push_back(node2);

    Port* oscOut = node1->getPort("OUT");
    Port* in1 = node2->getPort("IN_L");
    Port* in2 = node2->getPort("IN_R");

    oscOut->connect(in1);
    oscOut->connect(in2);

}