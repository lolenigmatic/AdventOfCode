#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include "helpers.h"
using namespace std;

unordered_map<string, int> get_instruction_lengths() {
    unordered_map<string, int> instruction_length;
    instruction_length["noop"] = 1;
    instruction_length["addx"] = 2;
    return instruction_length;
}

int d10_p1(vector<string> file) {
    vector<int> register_at_time;
    unordered_map<string, int> instruction_length = get_instruction_lengths();
    int reg = 1;
    register_at_time.push_back(1); //element 0
    for(int i = 0; i < file.size(); ++i) {
        vector<string> args = split(file[i], " ");
        
        for(int j = 0; j < instruction_length[args[0]]; ++j) {
            register_at_time.push_back(reg);
        }

        if (args[0] == "addx") {
            reg += stoi(args[1]);
        }
    }

    register_at_time.push_back(reg);

    int sig_strength_sum = 0;

    for(int i = 20; i < register_at_time.size(); i += 40) {
        sig_strength_sum += (i * register_at_time[i]);
    }

    
    return sig_strength_sum;
}

int d10_p2(vector<string> file) {
    unordered_map<string, int> instruction_length = get_instruction_lengths();
    int reg = 1;
    int current_pos = 0;
    for(int i = 0; i < file.size(); ++i) {
        vector<string> args = split(file[i], " ");
        
        for(int j = 0; j < instruction_length[args[0]]; ++j) {
            bool drew_pixel = false;
            for(int k = reg-1; k < reg+2; ++k) {
                if(current_pos == k) {
                    cout<<"#";
                    drew_pixel = true;
                    break;
                }
            }
            if(!drew_pixel) cout<<".";
            if(current_pos == 39) {
                cout<<endl;
                current_pos = 0;
            }
            else ++current_pos;
        }

        if (args[0] == "addx") {
            reg += stoi(args[1]);
        }
    }

    return -1;
}