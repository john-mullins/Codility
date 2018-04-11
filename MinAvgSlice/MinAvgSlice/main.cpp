//
//  main.cpp
//  MinAvgSlice
//
//  Created by John Mullins on 11/04/2018.
//  Copyright © 2018 John Mullins. All rights reserved.
//

#include <iostream>
#include <limits>
#include "MiniTestFramework.h"

#include <vector>
using namespace std;

double avg(int a, int b)
{
    return (a + b) / 2.0;
}

double avg(int a, int b, int c)
{
    return (a + b + c) / 3.0;
}

int solution1(const vector<int> &P)
{
    size_t min_idx = std::numeric_limits<int>::max();
    double min_avg = std::numeric_limits<double>::max();
    for (size_t i = 0; i != P.size() - 1; ++i)
    {
        double avg2 = avg(P[i], P[i + 1]);
        if (avg2 < min_avg)
        {
            min_avg = avg2;
            min_idx = i;
        }
        if (i < P.size() - 2)
        {
            double avg3 = avg(P[i], P[i + 1], P[i + 2]);
            if (avg3 < min_avg)
            {
                min_avg = avg3;
                min_idx = i;
            }
        }
    }
    return static_cast<int>(min_idx);
}

int solution(vector<int> &P) {
    return solution1(P);
}

struct{
    std::vector<int> sequence;
    int avg;
} tests[] =
{
    {{1, 1}, 0},
    {{2, 2}, 0},
    {{6, 6, 6, 1, 6, 6}, 2},
    {{2, 2, 1, 2, 2, 1, 1}, 5},
    {{-3, -5, -8, -4, -10}, 2},
    {{4, 2, 2, 5, 1, 5, 8}, 1}
};

PARAM_TEST(test, tests)
{
    ASSERT_EQUALS(param.avg, solution1(param.sequence));
}

TEST_MAIN()

