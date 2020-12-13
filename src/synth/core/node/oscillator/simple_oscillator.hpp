#ifndef _GALE_SYNTH_CORE_NODE_OSCILLATOR_SIMPLE_OSCILLATOR_H_
#define _GALE_SYNTH_CORE_NODE_OSCILLATOR_SIMPLE_OSCILLATOR_H_

#include "synth/core/node/node.hpp"

namespace Gale
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
