#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int d3_p1(vector<string> file)
{
    int total = 0;

    for (auto line : file)
    {
        string firstComp = line.substr(0, line.length() / 2);
        string secondComp = line.substr(line.length() / 2);

        char common = 0;

        for (auto ch : firstComp)
        {
            if (secondComp.find(ch) != std::string::npos)
            {
                common = ch;
                break;
            }
        }

        if (common >= 97)
        {
            total += int(common) - 96;
        }
        else
        {
            total += int(common) - 38;
        }
    }

    return total;
}

int d3_p2(vector<string> file)
{
    int total = 0;

    for (int i = 0; i < file.size(); i += 3)
    {
        vector<string> thisGroup = {file[i], file[i + 1], file[i + 2]};

        char common = 0;
        bool shared = true;

        for (auto ch : thisGroup[0])
        {
            shared = true;

            if (thisGroup[1].find(ch) == std::string::npos)
            {
                shared = false;
            }
            if (thisGroup[2].find(ch) == std::string::npos)
            {
                shared = false;
            }

            if (shared)
            {
                common = ch;
                break;
            }
        }

        if (common >= 97)
        {
            total += int(common) - 96;
        }
        else
        {
            total += int(common) - 38;
        }
    }

    return total;
}