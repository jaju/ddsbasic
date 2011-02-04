#include "repl.hpp"

#define REPL_PROMPT "REPL> "

REPL::REPL(Interpreter &i, std::istream &instream, std::ostream &outstream) :
    m_interpreter(i),
    instream(instream),
    outstream(outstream)
{
  m_prompt = REPL_PROMPT;
}

REPL::~REPL() {
}

void REPL::setPrompt(std::string prompt) { m_prompt = prompt; }

int REPL::run() {
    char instring[1024] = {0};
    std::string message = "";
    while (instream.getline(instring, 1024)) {
        std::cout << instring << std::endl;
        outstream << m_prompt << instring << std::endl;
        Interpreter::ParseStatus status =
          m_interpreter.gobble(std::string(instring), message);
        if (status == Interpreter::ERR) {
            outstream << "ERROR: " << message << std::endl;
        }
    }
    return 0;
}
