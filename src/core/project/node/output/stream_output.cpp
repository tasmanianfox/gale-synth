#include "stream_output.hpp"

using namespace Gale::Core;

StreamOutput::StreamOutput(node_id id) :
    Node::Node(id)
{
    addPort(new Port(this, PortType::INPUT, "IN_L"));
    addPort(new Port(this, PortType::INPUT, "IN_R"));
}

int StreamOutput::getCode() {
  return NODE_CODE_STREAM_OUTPUT;
}

const char* StreamOutput::getName()
{
    return "Stream output";
}

void StreamOutput::play(NodePlayContext* context) {
    
}