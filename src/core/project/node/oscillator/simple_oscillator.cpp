#include "simple_oscillator.hpp"

using namespace Gale::Core;

SimpleOscillator::SimpleOscillator(node_id id) :
    Node::Node(id)
{
  this->outputPort = new Port(this, PortType::OUTPUT, "OUT");
  addPort(this->outputPort);
}

const char* SimpleOscillator::getName()
{
  return "Simple oscillator";
}

void SimpleOscillator::play(NodePlayContext* context) {
  float pitch = 440.0f;
  float radians_per_second = pitch * 2.0f * M_PI;

  float float_sample_rate = context->sample_rate;
  float seconds_per_frame = 1.0f / float_sample_rate;
  
  float sample = sin((context->seconds_offset + context->frame * seconds_per_frame) * radians_per_second);
  this->outputPort->setOutputValue(sample);
}