#include "pipeline.hpp"

using namespace Gale::Core;

Pipeline::Pipeline(vector<Node*>* nodes) :
    nodes(nodes) {
}

SoundOutputData Pipeline::generateSound() {
    struct SoundOutputData result = {
        .left = { .value = 0.f },
        .right = { .value = 0.f },
    };

    // float sample = sin((gale_gui_sound_output_soundio_sound_output_seconds_offset + frame * seconds_per_frame) * radians_per_second);
    // // square
    // // sample = sample > 0 ? 1.0 : -1.0;
    // // sound
    // sample *= 0.5;

    // float *ptr;
    // // LEFT
    // ptr = (float*)(areas[0].ptr + areas[0].step * frame);
    // result.left = sample;
    // // RIGHT
    // ptr = (float*)(areas[1].ptr + areas[1].step * frame);
    // result.right = sample;

    return result;
}

// Pipeline sorting-related START

struct PipelineDepthMap {
    Node* node;
    int depth;
};

void pipelineAssignDepth(vector<struct PipelineDepthMap>* depths, vector<node_id>* usedIds, Node* node, int depth) {
    for (Port* inputPort: node->getInputPorts()) {
        for (Connection* inputConnection: inputPort->getConnections()) {
            pipelineAssignDepth(depths, usedIds, inputConnection->getOutput()->getNode(), depth + 1);
        }
    }
    if(find(usedIds->begin(), usedIds->end(), node->getId()) == usedIds->end()) {
        depths->push_back({ .node = node, .depth = depth });
        usedIds->push_back(node->getId());
    }
}

bool pipelineSortDepths(struct PipelineDepthMap a, struct PipelineDepthMap b) {
    return a.depth > b.depth;
}

// Pipeline sorting-related END

void Pipeline::build() {
    vector<struct PipelineDepthMap> depths;
    vector<node_id> usedIds;
    Node* output = nullptr;
    for (Node* node: *this->nodes) {
        if (node->is(NODE_CODE_STREAM_OUTPUT)) {
            output = node;
            break;
        }
    }
    if (nullptr == output) {
        return;
    }

    pipelineAssignDepth(&depths, &usedIds, output, 0);
    sort(depths.begin(), depths.end(), pipelineSortDepths);
    this->sortedNodes.clear();
    for (struct PipelineDepthMap depthMap: depths) {
        this->sortedNodes.push_back(depthMap.node);
    }
}