#include "stream_output.hpp"

StreamOutput::StreamOutput() :
    Glib::ObjectBase("output_stream_output_widget"),
    Node::Node("Stream Output")
{
    addPort(Port(PortType::INPUT, "IN_L"));
    addPort(Port(PortType::INPUT, "IN_R"));
}