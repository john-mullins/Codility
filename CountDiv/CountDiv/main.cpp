//
//  main.cpp
//  CountDiv
//
//  Created by John Mullins on 10/04/2018.
//  Copyright © 2018 John Mullins. All rights reserved.
//

#include <iostream>
#include "MiniTestFramework.h"

#include <vector>
using namespace std;

int solution1(int a, int b, int k)
{
    int lower = a / k;
    int upper = b / k;
    return ((a % k) == 0) + upper - lower;
}

int solution(int A, int B, int K) {
    return solution1(A, B, K);
}

struct{
    int lower;
    int upper;
    int divisor;
    int expected;
} tests[]
{
    {0, 0, 1, 1},
    {0, 2, 2, 2},
    {2, 4, 2, 2},
    {17, 34, 17, 2},
    {18, 50, 17, 1},
    {17, 50, 17, 2},
    {17, 51, 17, 3},
    {6, 11, 2, 3},
    {0, 0, 11, 1},
    {1, 1, 11, 0}
};

PARAM_TEST(test, tests)
{
    ASSERT_EQUALS(param.expected, solution1(param.lower, param.upper, param.divisor));
}

TEST_MAIN()

