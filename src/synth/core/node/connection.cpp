#include "connection.hpp"

using namespace Gale;

Connection::Connection(Port* output, Port* input)
{
    this->output = output;
    this->input = input;
}

Port* Connection::getInput()
{
    return this->input;
}