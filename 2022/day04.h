#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include "helpers.h"
using namespace std;

bool sets_contain_each_other(set<int> first, set<int> second)
{
    if (first == second)
        return true;

    if (includes(first.begin(), first.end(), second.begin(), second.end()))
        return true;

    if (includes(second.begin(), second.end(), first.begin(), first.end()))
        return true;

    return false;
}

bool sets_overlap(set<int> first, set<int> second)
{
    for (auto num : first)
    {
        if (second.count(num))
        {
            return true;
        }
    }

    for (auto num : second)
    {
        if (first.count(num))
        {
            return true;
        }
    }

    return false;
}

int d4_p1(vector<string> file)
{
    int overlap_count = 0;

    for (auto line : file)
    {
        set<int> first;
        set<int> second;

        vector<string> firstSplit = split(line, ",");
        vector<string> one = split(firstSplit[0], "-");
        vector<string> two = split(firstSplit[1], "-");

        for (int j = stoi(one[0]); j < stoi(one[1]) + 1; ++j)
        {
            first.insert(j);
        }

        for (int j = stoi(two[0]); j < stoi(two[1]) + 1; ++j)
        {
            second.insert(j);
        }

        if (sets_contain_each_other(first, second))
            overlap_count++;
    }

    return overlap_count;
}

int d4_p2(vector<string> file)
{
    int overlap_count = 0;

    for (auto line : file)
    {
        set<int> first;
        set<int> second;

        vector<string> firstSplit = split(line, ",");
        vector<string> one = split(firstSplit[0], "-");
        vector<string> two = split(firstSplit[1], "-");

        for (int j = stoi(one[0]); j < stoi(one[1]) + 1; ++j)
        {
            first.insert(j);
        }

        for (int j = stoi(two[0]); j < stoi(two[1]) + 1; ++j)
        {
            second.insert(j);
        }

        if (sets_overlap(first, second))
            overlap_count++;
    }

    return overlap_count;
}