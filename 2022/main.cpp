#include "day07.h"
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

    cout<<d7_p2(file);

    return 0;
}