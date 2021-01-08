#ifndef _GALE_CORE_NODE_OUTPUT_STREAM_OTUPUT_H_
#define _GALE_CORE_NODE_OUTPUT_STREAM_OTUPUT_H_

#include <string>

#include "core/node/node.hpp"

namespace Gale::Core
{

/**
 * Outputs the sound to external device (DAW, audio editor, system sound, etc)
 */
class StreamOutput : public Node
{
public:
    StreamOutput();
};

}

#endif