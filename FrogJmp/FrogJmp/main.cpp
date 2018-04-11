//
//  main.cpp
//  FrogJmp
//
//  Created by John Mullins on 09/04/2018.
//  Copyright © 2018 John Mullins. All rights reserved.
//

#include "MiniTestFramework.h"

#include <vector>
using namespace std;

int solution(int X, int Y, int D) {
    auto distance = Y - X;
    return (distance + D - 1)/ D;
}

struct{
    int start, end, distance,expected;
} tests[]
{
    {0, 4, 5, 1},
    {0, 5, 5, 1},
    {0, 6, 5, 2},
    {100, 200, 10, 10}
};

PARAM_TEST(test, tests)
{
    ASSERT_EQUALS(param.expected, solution(param.start, param.end, param.distance));
}

TEST_MAIN()


