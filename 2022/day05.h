#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <stack>
#include <deque>
#include "helpers.h"
using namespace std;

/*
move 1 from 2 to 1
move 3 from 1 to 3
move 2 from 2 to 1
move 1 from 1 to 2
 1   2   3
 */
void move(int numToMove, int from, int to, vector<stack<char>> &stacks)
{
    for (int i = 0; i < numToMove; ++i)
    {
        stacks[to - 1].push(stacks[from - 1].top());
        stacks[from - 1].pop();
    }
}

void move_new(int numToMove, int from, int to, vector<stack<char>> &stacks)
{
    vector<char> toMove;

    for (int i = 0; i < numToMove; ++i)
    {
        toMove.push_back(stacks[from - 1].top());
        stacks[from - 1].pop();
    }
    reverse(toMove.begin(), toMove.end());

    for (auto c : toMove)
    {
        stacks[to - 1].push(c);
    }
}

string d5_p1(vector<string> file)
{
    // Iterate through each column
    const int COLUMNS = 9;
    const int MAX_HEIGHT = 8;
    vector<stack<char>> stacks;

    for (int i = 1; i < 1 + (4 * COLUMNS); i += 4)
    {
        int currentRow = MAX_HEIGHT - 1;
        stack<char> thisColumn;

        while (currentRow != -1 && file[currentRow][i] != ' ')
        {
            thisColumn.push(file[currentRow][i]);
            currentRow--;
        }

        stacks.push_back(thisColumn);
    }

    for (int i = MAX_HEIGHT + 2; i < file.size(); ++i)
    {
        vector<string> lineParse = split(file[i], " ");

        move(stoi(lineParse[1]), stoi(lineParse[3]), stoi(lineParse[5]), stacks);
    }

    string resultString = "";

    for (auto s : stacks)
    {
        resultString += s.top();
    }

    return resultString;
}

string d5_p2(vector<string> file)
{
    // Iterate through each column
    const int COLUMNS = 9;
    const int MAX_HEIGHT = 8;
    vector<stack<char>> stacks;

    for (int i = 1; i < 1 + (4 * COLUMNS); i += 4)
    {
        int currentRow = MAX_HEIGHT - 1;
        stack<char> thisColumn;

        while (currentRow != -1 && file[currentRow][i] != ' ')
        {
            thisColumn.push(file[currentRow][i]);
            currentRow--;
        }

        stacks.push_back(thisColumn);
    }

    for (int i = MAX_HEIGHT + 2; i < file.size(); ++i)
    {
        vector<string> lineParse = split(file[i], " ");

        move_new(stoi(lineParse[1]), stoi(lineParse[3]), stoi(lineParse[5]), stacks);
    }

    string resultString = "";

    for (auto s : stacks)
    {
        resultString += s.top();
    }

    return resultString;
}