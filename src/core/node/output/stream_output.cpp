#include "stream_output.hpp"

using namespace Gale::Core;

StreamOutput::StreamOutput() :
    Node::Node("Stream output")
{
    addPort(new Port(this, PortType::INPUT, "IN_L"));
    addPort(new Port(this, PortType::INPUT, "IN_R"));
}