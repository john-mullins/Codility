//
//  main.cpp
//  Distinct
//
//  Created by John Mullins on 11/04/2018.
//  Copyright © 2018 John Mullins. All rights reserved.
//
#include <algorithm>
#include <vector>
#include "MiniTestFramework.h"

int solution1(const std::vector<int> &Q)
{
    if (Q.size() == 0)
        return 0;
    auto v(Q);
    std::sort(v.begin(), v.end());
    int count = 1;
    for (size_t i = 1; i != v.size(); ++i)
    {
        if (v[i] != v[i-1])
            ++count;
    }
    return count;
}

int solution(std::vector<int> &Q) {
    return solution1(Q);
}

struct{
    std::vector<int>    data;
    int                 num_unique;
} tests[] =
{
    {{}, 0},
    {{0}, 1},
    {{0, 0, 0}, 1},
    {{0, 1, 2, 3, 3, 4, 4, 5, 5, 5, 5}, 6},
    {{0, 5, 4, 2, 4, 5, 5, 5, 1, 3, 3}, 6},
    {{2, 1, 1, 2, 3, 1}, 3}
};

PARAM_TEST(test, tests)
{
    ASSERT_EQUALS(param.num_unique, solution1(param.data));
}

TEST_MAIN()

