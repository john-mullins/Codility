//
//  main.cpp
//  Traingle
//
//  Created by John Mullins on 11/04/2018.
//  Copyright © 2018 John Mullins. All rights reserved.
//

#include <iostream>
#include <limits>
#include "MiniTestFramework.h"

#include <vector>
using namespace std;

#include <algorithm>
int solution1(const vector<int> &P)
{
    std::vector<int> p(P);
    if (p.size() < 3)
        return 0;
    std::sort(p.begin(), p.end());
    for (size_t i = 0; i < p.size() - 2; ++i )
    {
        if (p[i + 2] - p[i + 1] < p[i])
            return 1;
    }
    return 0;
}

int solution(vector<int> &P) {
    return solution1(P);
}

struct{
    std::vector<int>    points;
    int                exists;
} tests[] =
{
    {{}, 0},
    {{1}, 0},
    {{1, 2}, 0},
    {{1, 2, 3}, 0},
    {{2, 2, 3}, 1},
    {{2, 1, 1}, 0},
    {{10, 2, 5, 1, 8, 20}, 1},
    {{0x7fffffff, 0x7fffff00, 0x7ffffff0}, 1}
};

PARAM_TEST(test, tests)
{
    ASSERT_EQUALS(param.exists, solution1(param.points));
}

TEST_MAIN()

