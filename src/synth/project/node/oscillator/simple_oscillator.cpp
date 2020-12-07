#include "simple_oscillator.hpp"

SimpleOscillator::SimpleOscillator() :
    Glib::ObjectBase("oscillator_simple_oscillator_widget"),
    Node::Node("Simple oscillator")
{
    addPort(new Port(this, PortType::OUTPUT, "OUT"));
}