//
//  main.cpp
//  PermCheck
//
//  Created by John Mullins on 09/04/2018.
//  Copyright © 2018 John Mullins. All rights reserved.
//

#include "MiniTestFramework.h"

#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> &A) {
    std::vector<int> counts(A.size(), 0);
    
    for (auto i : A)
    {
        if (i && i <= A.size())
        {
            if (counts[i - 1])
                return false;
            counts[i - 1]++;
        }
        else
        {
            return false;
        }
    }
    return true;
}

struct{
    std::vector<int>    perm;
    bool                valid;
} tests[]
{
    {{1}, true},
    {{2}, false},
    {{2,1}, true},
    {{3,2}, false},
    {{1,2,3,4,5,6,7,8,9,11}, false},
    {{1,2,3,4,5,6,7,8,9,10}, true},
    {{1,2,3,4,5,6,7,8,9,1}, false},

};

PARAM_TEST(test, tests)
{
    auto data = param.perm;
    ASSERT_EQUALS(param.valid, solution(data));
}

TEST_MAIN()


