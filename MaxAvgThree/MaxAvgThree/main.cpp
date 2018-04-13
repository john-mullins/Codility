//
//  main.cpp
//  MaxAvgThree
//
//  Created by John Mullins on 13/04/2018.
//  Copyright © 2018 John Mullins. All rights reserved.
//
#include <algorithm>
#include <vector>
#include "MiniTestFramework.h"

int solution1(const std::vector<int> &Q)
{
    //  Note : This can be done in linear (O(N)) time
    auto v(Q);
    std::sort(v.begin(), v.end());
    auto a = v.size() - 3;
    return std::max(v[a] * v[a + 1] * v[a + 2], v[0] * v[1] * v[a + 2]);
}

int solution(std::vector<int> &Q) {
    return solution1(Q);
}

struct{
    std::vector<int>    data;
    int                 max_avg;
} tests[] =
{
    {{0, 0, 0}, 0},
    {{1, 2, 3 }, 6},
    {{1, 0, 2, 0, 3, 0, 0, 0, 1 }, 6},
    {{1, 0, 2, 0, 3, 0, -4 }, 6},
    {{1, 0, 2, 0, 3, 0, -4, -1 }, 12},

};

PARAM_TEST(test, tests)
{
    ASSERT_EQUALS(param.max_avg, solution1(param.data));
}

TEST_MAIN()

