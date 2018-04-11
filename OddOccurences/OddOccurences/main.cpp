//
//  main.cpp
//  OddOccurences
//
//  Created by John Mullins on 09/04/2018.
//  Copyright © 2018 John Mullins. All rights reserved.
//


#include "MiniTestFramework.h"

#include <vector>
using namespace std;

int solution(vector<int> &A) {
    int odd_one = 0;
    for (auto i : A)
        odd_one ^= i;
    return odd_one;
}

struct{
    std::vector<int> test;
    int expected;
} tests[]
{
    {{1}, 1},
    {{2,2,4,4,9}, 9},
    {{1,2,3,4,5,4,3,2,1}, 5},
    {{1, 2, 3, 4, 4, 2, 3}, 1},
    {{1,2,3,4,5,7,1,2,3,4,5,7, 16}, 16}
};

PARAM_TEST(test, tests)
{
    auto data = param.test;
    ASSERT_EQUALS(param.expected, solution(data));
}

TEST_MAIN()


