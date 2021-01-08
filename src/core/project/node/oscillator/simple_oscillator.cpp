#include "simple_oscillator.hpp"

using namespace Gale::Core;

SimpleOscillator::SimpleOscillator() :
    Node::Node("Simple oscillator")
{
    addPort(new Port(this, PortType::OUTPUT, "OUT"));
}