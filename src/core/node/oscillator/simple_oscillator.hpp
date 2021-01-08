#ifndef _GALE_CORE_NODE_OSCILLATOR_SIMPLE_OSCILLATOR_H_
#define _GALE_CORE_NODE_OSCILLATOR_SIMPLE_OSCILLATOR_H_

#include "core/node/node.hpp"

namespace Gale::Core
{

/**
 * Generates simple waveforms: sine, triangle, square, saw tooth
 */
class SimpleOscillator : public Node
{
public:
    SimpleOscillator();
};

}

#endif
