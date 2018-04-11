//
//  main.cpp
//  PermMissingElement
//
//  Created by John Mullins on 09/04/2018.
//  Copyright © 2018 John Mullins. All rights reserved.
//

#include "MiniTestFramework.h"

#include <vector>
using namespace std;
#include <numeric>

int solution(vector<int> &A) {
    int pairs_total = static_cast<int>(A.size() + 2);
    int count = (A.size() & 1) == 0 ? static_cast<int>(A.size() + 2) / 2 : 0;

    for (auto i : A)
    {
        count += i;
        if (count >= pairs_total)
            count -= pairs_total;
    }
    
    return pairs_total - count;
}


struct{
    std::vector<int>    data;
    int                 missing;
} tests[]
{
    {{1}, 2},
    {{2}, 1},
    {{2, 3, 1, 5}, 4},
    {{1,2,3, 4,5,6,7,8,9,10,12}, 11}
};

PARAM_TEST(test, tests)
{
    auto data = param.data;
    ASSERT_EQUALS(param.missing, solution1(data));
}

TEST_MAIN()


