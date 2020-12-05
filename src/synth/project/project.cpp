#include "project.hpp"

#include "synth/project/node/output/stream_output.hpp" // temporary
#include "synth/project/node/oscillator/simple_oscillator.hpp" // temporary

void Project::reset()
{
    for (int i = 0; i < this->nodes.size(); i++) {
        delete this->nodes.at(i);
    }

    // temporary. Just for demo
    Node* node = new SimpleOscillator();
    node->setPosition(50, 300);
    this->nodes.push_back(node);

    node = new StreamOutput();
    node->setPosition(300, 300);
    this->nodes.push_back(node);


}