//
//  main.cpp
//  MaxProfit
//
//  Created by John Mullins on 27/04/2018.
//  Copyright © 2018 John Mullins. All rights reserved.
//

#include <vector>

int solution1(const std::vector<int>& a)
{
    if (a.empty())
        return 0;
    int max_profit = 0;
    int max_ending = 0;
    int last = a[0];
    for (auto i : a)
    {
        max_ending = std::max(0, max_ending + i - last);
        max_profit = std::max(max_profit, max_ending);
        last = i;
    }
    return max_profit;
}

int solution(std::vector<int>& a)
{
    return solution1(a);
}

#include "MiniTestFramework.h"

struct
{
    std::vector<int> data;
    int             max_profit;
} tests [] =
{
    {{}, 0},
    {{2000}, 0},
    {{2000, 2010}, 10},
    {{23171, 21011, 21123, 21366, 21013, 21367}, 356},
    {{100, 90, 110, 120, 119, 119}, 30}
};

PARAM_TEST(test, tests)
{
    int actual = solution1(args.data);
    ASSERT_EQUALS(args.max_profit, actual);
}

TEST_MAIN()

