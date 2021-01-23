#include "pipeline.hpp"

using namespace Gale::Core;

Pipeline::Pipeline(vector<Node*>* nodes) :
    nodes(nodes) {
}

SoundOutputData Pipeline::generateSound(NodePlayContext* context) {
    struct SoundOutputData result = {
        .left = { .value = 0.f },
        .right = { .value = 0.f },
    };

    Node* output = this->getOutputNode();
    if (nullptr == output) {
        return result;
    }

    for (Node* node: this->sortedNodes) {
        node->play(context);
    }

    Port* leftPort = output->getPort("IN_L");
    if (leftPort != nullptr) {
        result.left.value = leftPort->getValue();
    }
    Port* rightPort = output->getPort("IN_R");
    if (rightPort != nullptr) {
        result.right.value = rightPort->getValue();
    }

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
    Node* output = this->getOutputNode();
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

Node* Pipeline::getOutputNode() {
    for (Node* node: *this->nodes) {
        if (node->is(NODE_CODE_STREAM_OUTPUT)) {
            return node;
        }
    }
    return nullptr;
}