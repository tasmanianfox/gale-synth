#include "stream_output.hpp"

using namespace Gale::Core;

StreamOutput::StreamOutput(node_id id) :
    Node::Node(id)
{
    this->leftPort = new Port(this, PortType::INPUT, "IN_L");
    this->rightPort = new Port(this, PortType::INPUT, "IN_R");

    addPort(leftPort);
    addPort(rightPort);
}

int StreamOutput::getCode() {
  return NODE_CODE_STREAM_OUTPUT;
}

const char* StreamOutput::getName()
{
    return "Stream output";
}

void StreamOutput::play(NodePlayContext* context) {
    if (this->leftPort->getConnections().size() == 0) {
        this->leftPort->setInputValue(0.0);
    }
    if (this->rightPort->getConnections().size() == 0) {
        this->rightPort->setInputValue(0.0);
    }
}