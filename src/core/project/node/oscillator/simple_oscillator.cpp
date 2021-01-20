#include "simple_oscillator.hpp"

using namespace Gale::Core;

SimpleOscillator::SimpleOscillator(node_id id) :
    Node::Node(id)
{
    addPort(new Port(this, PortType::OUTPUT, "OUT"));
}

const char* SimpleOscillator::getName()
{
  return "Simple oscillator";
}