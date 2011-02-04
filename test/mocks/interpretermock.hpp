#include <gmock/gmock.h>
#include <sstream>

class MockInterpreter : public Interpreter {
    public:
        MOCK_METHOD2(gobble, ParseStatus(std::string command, std::string &message));
};
