//
//  main.cpp
//  Dominator
//
//  Created by John Mullins on 14/04/2018.
//  Copyright © 2018 John Mullins. All rights reserved.
//
#include "MiniTestFramework.h"

static int find_instances(const std::vector<int> &a, int value) {
    int count = 0;
    for (auto i : a)
    {
        if (i == value)
            ++count;
    }
    return count;
}

std::pair<bool, int> find_dominator(const std::vector<int>& a)
{
    int size = 0;
    int value = 0;
    for (auto i : a)
    {
        if (!size)
        {
            value = i;
            size = 1;
        }
        else if (i != value)
            size -= 1;
        else
            size += 1;
    }
    return {size && find_instances(a, value) > a.size() / 2, value};
}

int solution1(const std::vector<int>& a)
{
    auto result = find_dominator(a);
    if (result.first)
    {
        for (int i = 0; i < a.size(); ++i)
            if (a[i] == result.second)
                return i;
    }
    return -1;
}

int solution(std::vector<int>& s) {
    return solution1(s);
}


struct{
    std::vector<int>    data;
    int                 dominator;
} tests[] =
{
    {{}, -1},
    {{2}, 0},
    {{1, 2, 2}, 1},
    {{0, 0, 0, 1, 1, 1, 2, 0, 2 ,2 ,2 ,2, 2, 2, 2, 2, 2 }, 6},
    {{0,0,0,1,1,1,2,2,2,3,3,3}, -1},
    {{3, 4, 3, 2, 3, -1, 3, 3}, 0}
};

PARAM_TEST(test, tests)
{
    ASSERT_EQUALS(param.dominator, solution1(param.data));
}

TEST_MAIN()

