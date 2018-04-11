//
//  main.cpp
//  CyclicRotation
//
//  Created by John Mullins on 09/04/2018.
//  Copyright © 2018 John Mullins. All rights reserved.
//

#include "MiniTestFramework.h"

#include <vector>
using namespace std;

vector<int> solution(vector<int> &A, int K) {
    // write your code in C++14 (g++ 6.2.0)
    if (A.size() < 2)
        return A;
    int rotate = K % A.size();
    if (!rotate)
        return A;
    
    int start = static_cast<int>(A.size() - rotate);
    std::vector<int> result(A.begin() + start, A.end());
    result.insert(result.end(), A.begin(), A.begin() + start);
    
    return result;
}

struct{
    int num_rotations;
    std::vector<int> original;
    std::vector<int> expected;
} tests[]
{
    {0, {}, {}},
    {5, {}, {}},
    {0, {1}, {1}},
    {1, {1}, {1}},
    {1, {0, 1}, {1, 0}},
    {2, {0, 1}, {0, 1}},
    {7, {0, 1}, {1, 0}},
    {1, {3, 8, 9, 7, 6}, {6, 3, 8, 9, 7}},
    {2, {3, 8, 9, 7, 6}, {7, 6, 3, 8, 9}},
    {3, {3, 8, 9, 7, 6}, {9, 7, 6, 3, 8}},
};

PARAM_TEST(test, tests)
{
    auto original = param.original;
    int rotations = param.num_rotations;
    auto result = solution(original, rotations);
    
    ASSERT_EQUALS(result.size(), param.expected.size());
    for (int i = 0; i < result.size(); ++i)
        ASSERT_EQUALS(result[i], param.expected[i]);
}

TEST_MAIN()

