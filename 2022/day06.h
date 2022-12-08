#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include "helpers.h"
using namespace std;

int d6_p1(vector<string> file){
    int markerPos = 0;

    for(int i = 0; i < file[0].length(); ++i){
        string thisSubString = file[0].substr(i, 4);
        set<char> stringSet(thisSubString.begin(), thisSubString.end());
        
        if (stringSet.size() == 4)
        {
            markerPos = i + 4;
            break;
        }
    }

    return markerPos;
}

int d6_p2(vector<string> file){
    int markerPos = 0;

    for(int i = 0; i < file[0].length(); ++i){
        string thisSubString = file[0].substr(i, 14);
        set<char> stringSet(thisSubString.begin(), thisSubString.end());
        
        if (stringSet.size() == 14)
        {
            markerPos = i + 14;
            break;
        }
    }

    return markerPos;
}