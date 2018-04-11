//
//  main.cpp
//  MissingInteger
//
//  Created by John Mullins on 10/04/2018.
//  Copyright © 2018 John Mullins. All rights reserved.
//

#include "MiniTestFramework.h"

#include <vector>
#include <iostream>
using namespace std;

std::vector<int> count_entries(const std::vector<int>& in)
{
    std::vector<int> counts (in.size(), 0);
    
    for (auto i : in)
    {
        if (0 < i && i <= static_cast<int>(in.size()))
            counts[i - 1]++;
    }
    
    return counts;
}

int solution(vector<int> &A) {
    std::vector<int> counts = count_entries(A);
    
    for (int i = 0; i < static_cast<int>(counts.size()); ++i)
    {
        if (!counts[i])
            return i + 1;
    }
    return static_cast<int>(1 + A.size());
}

struct{
    std::vector<int>    values;
    int                 expected;
} tests[] =
{
    {{}, 1},
    {{1}, 2},
    {{2}, 1},
    {{10, 8, 7, 6, 5, 4, 3, 2, 1, 0}, 9}
};

PARAM_TEST(test, tests)
{
    auto values = param.values;
    ASSERT_EQUALS(param.expected, solution(values));
    
}

TEST_MAIN()


