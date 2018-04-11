//
//  main.cpp
//  MaxCounters
//
//  Created by John Mullins on 10/04/2018.
//  Copyright © 2018 John Mullins. All rights reserved.
//

#include "MiniTestFramework.h"

#include <vector>
using namespace std;

vector<int> solution1(int n, const vector<int>& a)
{
    int current_max = 0;
    int last_max = 0;
    std::vector<int> results(n, 0);
    const int max_size = static_cast<int>(1 + results.size());
    for (auto i : a)
    {
        if (0 < i && i < max_size)
        {
            int a = results[i - 1];
            results[i - 1] = a < last_max ? last_max + 1: a + 1;
            current_max = std::max(results[i - 1], current_max);
        }
        else if (i == max_size)
        {
            last_max = current_max;
        }
    }
    
    for (auto&& i : results)
        if (i < last_max)
            i = last_max;
    
    return results;
}

vector<int> solution(int N, vector<int> &A) {
    return solution1(N, A);
}

struct{
    std::vector<int> values;
    int num_counters;
    std::vector<int> counters;
} tests[]
{
    {{}, 1, {0}},
    {{1, 2, 3}, 4, {1, 1, 1, 0}},
    {{1, 2, 3, 3, 3, 5, 1}, 4, {4, 3, 3, 3}},
    {{1, 1, 2, 2, 5, 3, 1, 1}, 4, {4, 2, 3, 2}},
    {{3, 4, 4, 6, 1, 4, 4}, 5, {3, 2, 2, 4, 2}}
};

PARAM_TEST(test, tests)
{
    auto counters = solution1(param.num_counters, param.values);
    ASSERT_EQUALS(param.counters.size(), counters.size());
    
    for (int i = 0; i < counters.size(); ++i)
    {
        ASSERT_EQUALS(param.counters[i], counters[i]);
    }
}

TEST_MAIN()


