#include <gtest/gtest.h>
#include <sstream>

#include "repl.hpp"
#include "mocks/interpretermock.hpp"

using namespace ::testing;

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
