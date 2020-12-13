#include "stream_output.hpp"

using namespace Gale;

StreamOutput::StreamOutput() :
    // Glib::ObjectBase("output_stream_output_widget"),
    Node::Node("Stream output")
{
    addPort(new Port(this, PortType::INPUT, "IN_L"));
    addPort(new Port(this, PortType::INPUT, "IN_R"));
}