#ifndef _GALE_SYNTH_PROJECT_PROJECT_H_
#define _GALE_SYNTH_PROJECT_PROJECT_H_

#include <vector>

#include "synth/project/node/output/stream_output.hpp"

#include "node.hpp"

using namespace std;

/**
 * 
 */
class Project
{
public:
    void reset();

    vector<Node*> nodes;
};

#endif