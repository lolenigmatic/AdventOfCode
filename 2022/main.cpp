#include "day10.h"
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
    string text = "";
    ifstream MyReadFile("input.txt");
    vector<string> file;

    while(std::getline(MyReadFile, text)){
        file.push_back(text);
    }

    cout<<d10_p1(file)<<endl;

    return 0;
}