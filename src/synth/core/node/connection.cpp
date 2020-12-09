#include "connection.hpp"

Connection::Connection(Port* output, Port* input)
{
    this->output = output;
    this->input = input;
}

Port* Connection::getInput()
{
    return this->input;
}