#include "day01.h"
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
using std::string;
using std::vector;
using std::ifstream;
using std::cout;
using std::endl;

int main(){
    int retval = 0;

    string text = "";
    ifstream MyReadFile("day1input.txt");
    vector<string> file;

    while(std::getline(MyReadFile, text)){
        file.push_back(text);
    }

    cout<<highest_calories_top_three(file);
}