#ifndef _GALE_CORE_PROJECT_NODE_NODE_PLAY_CONTEXT_H_
#define _GALE_CORE_PROJECT_NODE_NODE_PLAY_CONTEXT_H_

namespace Gale::Core
{

struct NodePlayContext {
    int frame;
    int frame_count;
    int sample_rate;
    float seconds_offset;
};

}

#endif