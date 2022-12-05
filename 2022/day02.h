#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int d2_p1(vector<string> file){
    int total = 0;

    for(auto line : file){
        vector<int> thisLineConverted = {int(line[0]) - 65, int(line[2]) - 88};
        total += thisLineConverted[1] + 1;
        if(thisLineConverted[0] == thisLineConverted[1]) total += 3;
        else if((thisLineConverted[0] + 1) % 3 == thisLineConverted[1]) total += 6;
    }

    return total;
}

int d2_p2(vector<string> file){
    int total = 0;

    for(auto line : file){
        vector<int> thisLineConverted = {int(line[0]) - 65, int(line[2]) - 88};
        total += thisLineConverted[1] * 3;
        if(thisLineConverted[1] == 1){
            total += thisLineConverted[0] + 1;
        }
        else if(thisLineConverted[1] == 2){
            total += (thisLineConverted[0] + 1) % 3 + 1;
        }
        else{
            total += (thisLineConverted[0] + 2) % 3 + 1;
        }
    }

    return total;
}

/*
x = lose
y = tie
z = win
*/

/*
Same: 0 points
1 - 1 = 0
1 - 2 = -1 lose
1 - 3 = -2 win
2 - 1 = 1 win
2 - 2 = 0 
2 - 3 = -1 lose
3 - 1 = 2 lose
3 - 2 = 1 win
3 - 3 = 0 

x = me
y = opponent

convert all rocks to 1, scissors to 2, papers to 3
total += num

if((x + 2)%3 == y) then win 
if((x+1)%3 == y) then lose
else tie*/