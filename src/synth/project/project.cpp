#include "project.hpp"

void Project::reset()
{
    for (int i = 0; i < this->nodes.size(); i++) {
        delete this->nodes.at(i);
    }
    this->nodes.push_back(new StreamOutput());
}