//
//  main.cpp
//  NumberOfDiscIntersections
//
//  Created by John Mullins on 13/04/2018.
//  Copyright © 2018 John Mullins. All rights reserved.
//
#include <algorithm>
#include <vector>
#include "MiniTestFramework.h"

#include <iostream>
int solution1(const std::vector<int> &Q)
{
    if (Q.size() < 2)
        return 0;
    std::vector<int> low(Q.size());
    std::vector<int> high(Q.size());
    
    int size = static_cast<int>(Q.size());
    
    for (int i = 0; i < size; ++i)
    {
        int a = (i - Q[i]) > 0 ?  i - Q[i] :  0;
        low[a]++;
        long long b = Q[i] + i;
        if (0 <= b && b < size)
            high[Q[i] + i]++;
    }
    
    long long disks_active = low[0] - high[0];
    long long total_pairs = disks_active ? disks_active * (disks_active - 1) / 2 : 0;
    
    for (int i = 1;i < size; ++i)
    {
        // These new disks intersect with those already active
        long long new_intersections = disks_active * low[i];
        total_pairs += new_intersections;
        // These new disks also intersect with themselves
        if (low[i])
            total_pairs += low[i] * (low[i] - 1) / 2;
        //  We need to remove the the ones
        disks_active += low[i];
        disks_active -= high[i];
        
        if (total_pairs > 10000000)
            return -1;
    }
    return static_cast<int>(total_pairs);
}

int solution(std::vector<int> &Q) {
    return solution1(Q);
}

struct{
    std::vector<int>    discs;
    int                 intersects;
} tests[] =
{
    {{}, 0},
    {{1}, 0},
    {{1, 2}, 1},
    {{1, 5, 2}, 3},
    {{1, 5, 2, 1}, 5},
    {{1, 5, 2, 1, 4, 0}, 11},
    {std::vector<int>(100000, 0), 0}
};

PARAM_TEST(test, tests)
{
    ASSERT_EQUALS(param.intersects, solution1(param.discs));
}

TEST_MAIN()

