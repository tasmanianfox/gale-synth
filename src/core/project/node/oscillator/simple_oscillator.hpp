#ifndef _GALE_CORE_PROJECT_NODE_OSCILLATOR_SIMPLE_OSCILLATOR_H_
#define _GALE_CORE_PROJECT_NODE_OSCILLATOR_SIMPLE_OSCILLATOR_H_

#include "core/project/node/node.hpp"

namespace Gale::Core
{

/**
 * Generates simple waveforms: sine, triangle, square, saw tooth
 */
class SimpleOscillator : public Node
{
public:
    SimpleOscillator(node_id id);

    const char* getName() override;
};

}

#endif
