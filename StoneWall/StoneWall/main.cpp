//
//  main.cpp
//  StoneWall
//
//  Created by John Mullins on 13/04/2018.
//  Copyright © 2018 John Mullins. All rights reserved.
//
#include <algorithm>
#include <vector>
#include "MiniTestFramework.h"

#include <iostream>
#include <stack>

int solution1(const std::vector<int> &Q)
{
    std::stack<size_t> starts;
    
    size_t bricks = 0;
    for (size_t i = 0; i < Q.size(); ++i)
    {
        while (!starts.empty() && Q[i] < Q[starts.top()])
        {
            starts.pop();
            bricks++;
        }
        if (starts.empty() || Q[i] != Q[starts.top()])
            starts.push(i);
    }
    
    return static_cast<int>(bricks + starts.size());
}

int solution(std::vector<int> &Q) {
    return solution1(Q);
}

struct{
    std::vector<int>    heights;
    int                 total;
} tests[] =
{
    {{8}, 1},
    {{8, 6}, 2},
    {{8, 8, 5, 7, 9, 8, 7, 4, 8}, 7},
    {{1, 1, 1, 3, 1, 1}, 2},
    {{1, 2, 3, 2, 1}, 3},
    {{1, 2, 1, 1, 2, 1}, 3}
};

PARAM_TEST(test, tests)
{
    ASSERT_EQUALS(param.total, solution1(param.heights));
}

TEST_MAIN()

