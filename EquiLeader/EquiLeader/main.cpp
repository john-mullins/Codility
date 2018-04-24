//
//  main.cpp
//  EquiLeader
//
//  Created by John Mullins on 24/04/2018.
//  Copyright © 2018 John Mullins. All rights reserved.
//

#include "MiniTestFramework.h"

#include <tuple>
#include <vector>

static int find_instances(const std::vector<int> &a, int value)
{
    int count = 0;
    for (auto i : a)
    {
        if (i == value)
            ++count;
    }
    return count;
}

std::tuple<bool, int, int> find_dominator(const std::vector<int>& a)
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
    auto instances = find_instances(a, value);
    return {size && instances > static_cast<int>(a.size()) / 2, value, instances};
}

int solution(std::vector<int>& data)
{
    auto equi_leaders = 0;
    auto dominator_details = find_dominator(data);
    if (std::get<0>(dominator_details))
    {
        auto dominator = std::get<1>(dominator_details);
        auto num_doms_right = std::get<2>(dominator_details);
        auto num_doms_left = 0;
        int upper = data.size() - 1;
        for (size_t i = 0; i < data.size(); ++i)
        {
            if (data[i] == dominator)
            {
                num_doms_left += 1;
                num_doms_right -= 1;
            }
            const int left_size = i + 1;
            const int right_size = upper - i;
            if (num_doms_left > left_size / 2 && num_doms_right > right_size / 2)
                ++equi_leaders;
        }
    }
    
    return equi_leaders;
}

struct{
    std::vector<int>    data;
    int                 expected;
} tests[] =
{
    {{}, 0},
    {{2}, 0},
    {{2, 2}, 1},
    {{1, 2, 2, 2}, 1},
    {{4, 3, 4, 4, 4, 2}, 2},
    {{4, 4, 2, 5, 3, 4, 4, 4}, 3}
};

PARAM_TEST(test, tests)
{
    auto data = param.data;
    ASSERT_EQUALS(param.expected, solution(data));
}

TEST_MAIN()

