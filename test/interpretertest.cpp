#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <sstream>

#include "interpreter.hpp"

TEST(Interpreter, GobbleRem) {
    std::string input1 = "REM Hello.";
    std::string input2 = "BLAH Hello.";
    std::string message = "";
    Interpreter::ParseStatus s;
    Interpreter i;

    // Comment
    s = i.gobble(input1, message);
    EXPECT_NE("", message);
    ASSERT_EQ(s, Interpreter::REM);

    // Some erroneous statement
    s = i.gobble(input2, message);
    EXPECT_NE("", message);
    ASSERT_EQ(s, Interpreter::ERR);
}

