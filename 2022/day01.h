#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using std::string;
using std::vector;
using std::stoi;
using std::max_element;
using std::distance;
using std::cout;
using std::endl;

int d1_p1(vector<string> file){
    int total = 0;
    vector<int> elves;
    for(int i = 0; i < file.size(); ++i){
        if(file[i] != ""){
            total += stoi(file[i]);
        }
        else{
            elves.push_back(total);
            total = 0;
        }
    }
    elves.push_back(total);

    return *max_element(elves.begin(), elves.end());
}

int d1_p2(vector<string> file){
    int total = 0;
    vector<int> elves;
    for(int i = 0; i < file.size(); ++i){
        if(file[i] != ""){
            total += stoi(file[i]);
        }
        else{
            elves.push_back(total);
            total = 0;
        }
    }
    elves.push_back(total);

    int top_three_total = 0;;
    for (int i = 0; i < 3; ++i){
        top_three_total += *max_element(elves.begin(), elves.end());
        elves.erase(max_element(elves.begin(), elves.end()));
    }

    return top_three_total;
}