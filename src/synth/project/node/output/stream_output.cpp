#include "stream_output.hpp"

StreamOutput::StreamOutput() :
    Glib::ObjectBase("output_stream_output_widget"),
    Node::Node()
{
    this->ports.push_back(Port(PortType::INPUT));
    this->ports.push_back(Port(PortType::INPUT));
}