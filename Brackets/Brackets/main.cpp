//
//  main.cpp
//  Brackets
//
//  Created by John Mullins on 13/04/2018.
//  Copyright © 2018 John Mullins. All rights reserved.
//

#include <algorithm>
#include <vector>
#include "MiniTestFramework.h"

#include <iostream>
#include <stack>

bool is_opening_brace(char ch)
{
    return ch == '(' || ch == '{' || ch == '[';
}

bool is_closing_brace(char ch)
{
    return ch == ')' || ch == '}' || ch == ']';
}

bool matches_stack_top(char ch, const std::stack<char>& last)
{
    if (!last.empty())
    {
        if (ch == ')' && last.top() == '(')
            return true;
        if (ch == '}' && last.top() == '{')
            return true;
        if (ch == ']' && last.top() == '[')
            return true;
    }
    return false;
}

int solution1(const std::string& s)
{
    std::stack<char> last_brace;
    
    for (auto ch : s)
    {
        if (is_opening_brace(ch))
            last_brace.push(ch);
        else if (matches_stack_top(ch, last_brace))
            last_brace.pop();
        else if (is_closing_brace(ch))
            return false;
    }
    return last_brace.empty();
}

int solution(std::string &Q) {
    return solution1(Q);
}

struct{
    std::string s;
    int         balanced;
} tests[] =
{
    {"", 1},
    {"(", 0},
    {"({[]})", 1},
    {"({[()[]{}]})", 1},
    {"]", 0},
    {"([)()]", 0}
};

PARAM_TEST(test, tests)
{
    ASSERT_EQUALS(param.balanced, solution1(param.s));
}

TEST_MAIN()

