#ifndef _GALE_CORE_PROJECT_PIPELINE_H_
#define _GALE_CORE_PROJECT_PIPELINE_H_

#include <vector>

#include "core/project/node/constants.hpp"
#include "core/project/node/node.hpp"
#include "core/sound/sound_data.hpp"

namespace Gale::Core {

/**
 * Sound generation pipeline
 */
class Pipeline {
public:
    Pipeline(vector<Node*>* nodes);

    void build();
    SoundOutputData generateSound();
private:
    vector<Node*>* nodes; // input from project
    vector<Node*> sortedNodes;
};

}

#endif