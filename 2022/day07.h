#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include "helpers.h"
using namespace std;

//wrong
int d7_p1 (vector<string> file)
{   
    bool isInDirectory = false;
    int finalTotal = 0;
    int thisTotal = 0;

    for (int i = 0; i < file.size(); ++i){
        if (file[i] == "$ ls"){
            isInDirectory = true;
            continue;
        }

        if(isInDirectory && file[i][0] == '$') {
            isInDirectory = false;
            cout<<thisTotal<<endl;
            if (thisTotal <= 100000)  finalTotal += thisTotal;
            thisTotal = 0;
            continue;
        }

        if(!isInDirectory) continue;

        vector<string> thisLineSplit = split(file[i], " ");

        try{
            int fileSize = stoi(thisLineSplit[0]);
            thisTotal += fileSize;
        }
        catch (exception &err){
            continue;
        }

    }

    cout<<thisTotal<<endl;

    return finalTotal;
}