#include "project.hpp"

#include "synth/project/node/output/stream_output.hpp" // temporary

void Project::reset()
{
    for (int i = 0; i < this->nodes.size(); i++) {
        delete this->nodes.at(i);
    }
    this->nodes.push_back(new StreamOutput());  // temporary
}