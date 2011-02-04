#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <sstream>

#include "repl.hpp"
using namespace ::testing;

class MockInterpreter : public Interpreter {
    public:
        MOCK_METHOD2(gobble, ParseStatus(std::string command, std::string &message));
};

TEST(REPL, Basic) {
    MockInterpreter mock;
    EXPECT_CALL(mock, gobble(_, _))
      .Times(2)
      .WillRepeatedly(Return(Interpreter::REM));
    std::istringstream input;
    std::stringstream outstream;
    input.str("REM Hello World\nREM Bye World\n");
    REPL repl(mock, input, outstream);
    repl.run();
}

