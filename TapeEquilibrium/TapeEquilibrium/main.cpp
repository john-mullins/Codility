//
//  main.cpp
//  TapeEquilibrium
//
//  Created by John Mullins on 09/04/2018.
//  Copyright © 2018 John Mullins. All rights reserved.
//



#include "MiniTestFramework.h"

#include <vector>
using namespace std;

#include <numeric>

int solution(vector<int> &A) {
    int a = std::accumulate(A.begin() + 1, A.end(), 0);
    int b = A[0];
    int min_diff = std::abs(a - b);
    
    for (int i = 1; i != static_cast<int>(A.size() - 1); ++i)
    {
        b += A[i];
        a -= A[i];
        int new_diff = std::abs(b - a);
        min_diff = std::min(new_diff, min_diff);
    }
    return min_diff;
}

struct{
    std::vector<int> test;
    int             expected;
} tests[]
{
    {{1000, -1000}, 2000},
    {{3, 1, 2, 4, 3}, 1},
    {{0, 100}, 100},
    {{100, 0}, 100},
};

PARAM_TEST(test, tests)
{
    auto test = param.test;
    ASSERT_EQUALS(param.expected, solution(test));
}

TEST_MAIN()


