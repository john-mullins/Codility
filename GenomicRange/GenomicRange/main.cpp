//
//  main.cpp
//  GenomicRange
//
//  Created by John Mullins on 11/04/2018.
//  Copyright © 2018 John Mullins. All rights reserved.
//

#include <iostream>
#include "MiniTestFramework.h"

#include <vector>
using namespace std;

std::vector<int> solution1(const std::string &s, const vector<int> &P, const vector<int> &Q)
{
    struct nucleotide {
        int a;
        int c;
        int g;
        int t;
    };
    std::vector<nucleotide> counts(1 + s.size());
    int index = 1;
    for (auto ch : s)
    {
        counts[index] = counts[index - 1];
        switch (ch)
        {
            case 'A':
                counts[index].a++;
                break;
            case 'C':
                counts[index].c++;
                break;
            case 'G':
                counts[index].g++;
                break;
            case 'T':
                counts[index].t++;
                break;
        }
        ++index;
    }
    
    std::vector<int> results;
    for (size_t i = 0; i < P.size(); ++i)
    {
        nucleotide start = counts[ P[i] ];
        nucleotide end = counts[ Q[i] + 1];
        if (end.a != start.a)
            results.push_back(1);
        else if (end.c != start.c)
            results.push_back(2);
        else if (end.g != start.g)
            results.push_back(3);
        else if (end.t != start.t)
            results.push_back(4);
    }

    return results;
}

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
    return solution1(S, P, Q);
}

struct{
    std::string         sequence;
    std::vector<int>    begin;
    std::vector<int>    end;
    std::vector<int>    expected;
} tests[] =
{
    {"A", {0}, {0}, {1}},
    {"CGTA", {0}, {3}, {1}},
    {"CAGCCTA", {2, 5, 0}, {4, 5, 6}, {2, 4, 1}},
    {"CAGCCTA", {0, 1, 2}, {0, 1, 2}, {2, 1, 3}},
};

PARAM_TEST(test, tests)
{
    ASSERT_EQUALS(param.expected, solution1(param.sequence, param.begin, param.end));
}

TEST_MAIN()

