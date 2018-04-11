//
//  main.cpp
//  FrogRiverOne
//
//  Created by John Mullins on 09/04/2018.
//  Copyright © 2018 John Mullins. All rights reserved.
//

#include "MiniTestFramework.h"

#include <vector>
#include <iostream>
using namespace std;

#include <unordered_set>

#include <unordered_set>

int solution(int X, vector<int> &A) {
    std::unordered_set<int> set;
    
    for (int i = 0; i < static_cast<int>(A.size()); ++i)
    {
        if (A[i] - 1 < X)
        {
            set.insert(A[i] - 1);
            if (X == static_cast<int>(set.size()))
                return i;
        }
    }
    return -1;
}

struct{
    std::vector<int>    leaves;
    int                 distance;
    int                 time;
} tests[] = 
{
    {{}, 5, -1},
    {{5}, 5, -1},
    {{5, 4, 3, 2, 1}, 5, 4},
    {{1, 3, 1, 4, 2, 3, 5, 4}, 5, 6}
    
};

PARAM_TEST(test, tests)
{
    auto leaves = param.leaves;
    int time = solution(param.distance,leaves);
    ASSERT_EQUALS(param.time, time);
    //ASSERT_EQUALS(time, solution(param.distance, leaves));
}

TEST_MAIN()


