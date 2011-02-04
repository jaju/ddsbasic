#pragma once
#include "localdefs.hpp"
#include "interpreter.hpp"
#include <iostream>

class REPL {

    private:
        std::istream &instream;
        std::ostream &outstream;
        std::string m_prompt;
        Interpreter &m_interpreter;

    public:
        REPL(Interpreter &i, std::istream &instream = std::cin, std::ostream &outstream = std::cout);
        virtual ~REPL();

    public:
        virtual int run();
        void setPrompt(std::string m_prompt);
};
