#ifndef _GALE_CORE_PROJECT_NODE_OSCILLATOR_SIMPLE_OSCILLATOR_H_
#define _GALE_CORE_PROJECT_NODE_OSCILLATOR_SIMPLE_OSCILLATOR_H_

#include <math.h>

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

    void play(NodePlayContext* context) override;

    const char* getName() override;
private:
    Port* outputPort;
};

}

#endif
