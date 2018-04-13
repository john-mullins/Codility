//
//  main.cpp
//  Fish
//
//  Created by John Mullins on 13/04/2018.
//  Copyright © 2018 John Mullins. All rights reserved.
//
#include "MiniTestFramework.h"

#include <vector>
#include <stack>

int solution1(const std::vector<int>& w, const std::vector<int>& d)
{
    std::stack<int> fish;
    for (int i = 0; i < w.size(); ++i)
    {
        while(!fish.empty())
        {
            if (d[i] - d[fish.top()] == -1)
            {
                if (w[fish.top()] > w[i])
                    break;
                else if (w[fish.top()] < w[i])
                    fish.pop();
            }
            else
            {
                fish.push(i);
                break;
            }
        }
        if (fish.empty())
            fish.push(i);
        
    }
    return fish.size();
}

int solution(const std::vector<int>& w, const std::vector<int>& d) {
    return solution1(w, d);
}

struct{
    std::vector<int> weights;
    std::vector<int> directions;
    int number_left;
} tests[] =
{
    {{}, {}, 0},
    {{4, 4}, {1, 1}, 2},
    {{1, 2, 3}, {0, 1, 0}, 2},
    {{3, 1, 2}, {1, 0, 0}, 1},
    {{4, 3, 2, 1, 5}, {0, 1, 0, 0, 0}, 2}
};

PARAM_TEST(test, tests)
{
    ASSERT_EQUALS(param.number_left, solution1(param.weights, param.directions));
}

TEST_MAIN()

