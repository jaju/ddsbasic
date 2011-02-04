#include "interpreter.hpp"
#include <iostream>
#include <cassert>

Interpreter::Interpreter() {}
Interpreter::~Interpreter() {}

Interpreter::ParseStatus Interpreter::gobble(std::string command, std::string &message) {
    Interpreter::ParseStatus retval = parse(command);
    message = messageForStatus(retval);
    return retval;
}

Interpreter::ParseStatus Interpreter::parse(std::string command) {
    if (command.find("REM ") == 0)
      return REM;
    return ERR;
}

std::string Interpreter::messageForStatus(ParseStatus status) {
    switch(status) {
        case REM:
            return "COMMENT";
        case OK:
            return "OK";
        case ERR:
            return "ERROR";
        default:
            // Should not be reached!
            assert(0);
    }
}
