//
//  main.cpp
//  Nesting
//
//  Created by John Mullins on 14/04/2018.
//  Copyright © 2018 John Mullins. All rights reserved.
//
#include "MiniTestFramework.h"

#include <string>

int solution1(const std::string& s)
{
    int open = 0;
    for (auto ch : s)
    {
        if (ch == ')')
            --open;
        else if (ch == '(')
            ++open;
        if (open < 0)
            return 0;
    }
    return open == 0;
}

int solution(std::string& s) {
    return solution1(s);
}


struct{
    std::string s;
    int         balanced;
} tests[] =
{
    {"", 1},
    {"(", 0},
    {")", 0},
    {"()", 1},
    {")(", 0},
    {"((()))()()(())", 1}
    
};

PARAM_TEST(test, tests)
{
    ASSERT_EQUALS(param.balanced, solution1(param.s));
}

TEST_MAIN()

