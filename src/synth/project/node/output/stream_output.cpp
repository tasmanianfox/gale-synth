#include "stream_output.hpp"

StreamOutput::StreamOutput() :
    Glib::ObjectBase("output_stream_output_widget"),
    Node::Node()
{
    addPort(Port(PortType::INPUT, "IN_L"));
    addPort(Port(PortType::INPUT, "IN_R"));
}