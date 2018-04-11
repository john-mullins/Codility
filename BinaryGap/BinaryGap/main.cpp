//
//  main.cpp
//  BinaryGap
//
//  Created by John Mullins on 09/04/2018.
//  Copyright © 2018 John Mullins. All rights reserved.
//

#include "MiniTestFramework.h"

int solution(int N) {
    int best = 0;
    int count = std::numeric_limits<int>::min();
    
    while(N)
    {
        if ((N & 1) == 1)
        {
            best = std::max(best, count);
            count = -1;
        }
        ++count;
        N >>= 1;
    }
    
    return best;
}

struct
{
    int in;
    int out;
} tests[]=
{
    {0, 0},
    {0x40000001, 29},
    {0x40010001, 15},
    {0x40010101, 13},
    {0x7fffffff, 0},
};

PARAM_TEST(test, tests)
{
    ASSERT_EQUALS(param.out, solution(param.in));
}

TEST_MAIN()




