#pragma once
#include "localdefs.hpp"
#include <string>

class Interpreter {
    public:
        typedef enum {
            ERR,
            REM,
            OK
        } ParseStatus;

    public:
        Interpreter();
        virtual ~Interpreter();

    public:
        virtual ParseStatus gobble(std::string command, std::string &message /*out*/);

    private:
        virtual ParseStatus parse(std::string command);
        static std::string messageForStatus(ParseStatus status);
};
