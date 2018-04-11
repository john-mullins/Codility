//
//  main.cpp
//  PassingCars
//
//  Created by John Mullins on 10/04/2018.
//  Copyright © 2018 John Mullins. All rights reserved.
//

#include <iostream>
#include "MiniTestFramework.h"

#include <vector>
using namespace std;

int solution1(const std::vector<int>& a)
{
    int westbound = 0;
    int passed = 0;
    
    for (auto i : a)
    {
        if (i == 0)
            ++westbound;
        else
            passed += westbound;
        
        if (passed > 1000000000)
            return -1;
    }
    return passed;
}

int solution(vector<int>& A) {
    return solution1(A);
}

struct{
    std::vector<int> directions;
    int     expected;
} tests[] =
{
    {{}, 0},
    {{1}, 0},
    {{0, 1,}, 1},
    {{0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1}, 28},
    {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, 13},
    {{0, 1, 0, 1, 1}, 5},
    {{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 0}
};

PARAM_TEST(test, tests)
{
    ASSERT_EQUALS(param.expected, solution1(param.directions));
}

TEST_MAIN()

