#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include "helpers.h"
using namespace std;

vector<vector<string>> parse_input(vector<string> file) {
    vector<vector<string>> parse;
    for(auto line : file) {
        parse.push_back(split(line, " "));
    }
    return parse;
}

void tail_move(vector<vector<int>> &tail_positions, vector<int> &head_position){
    vector<int> current_tail_pos = tail_positions.back();
    int x_delta = head_position[0] - current_tail_pos[0];
    int y_delta = head_position[1] - current_tail_pos[1];
    if(abs(y_delta) > 1) {
        tail_positions.push_back({head_position[0], head_position[1] - (y_delta/2)});
        cout<<head_position[0]<<" "<<head_position[1] - (y_delta/2)<<endl;
    }
    if(abs(x_delta) > 1) {
        tail_positions.push_back({head_position[0] - (x_delta/2), head_position[1]});
        cout<<head_position[0] - (x_delta/2)<<" "<<head_position[1]<<endl;
    }
}

vector<int> tail_move_p2(vector<int> back, vector<int> front){
    int x_delta = front[0] - back[0];
    int y_delta = front[1] - back[1];
    if(abs(y_delta) > 1 && abs(x_delta) > 1) {
        return vector<int>({back[0] + (x_delta/2), back[1] + (y_delta/2)});
    }
    if(abs(y_delta) > 1) {
        return vector<int>({front[0], back[1] + (y_delta/2)});
    }
    if(abs(x_delta) > 1) {
        return vector<int>({back[0] + (x_delta/2), front[1]});
    }
    return back;
}

int d9_p1(vector<string> file) {
    vector<vector<string>> input = parse_input(file);
    vector<vector<int>> tail_positions;
    vector<int> head_position(2, 0);
    tail_positions.push_back(head_position);
    for (auto move : input) {
        vector<int> head_delta(2, 0);
        switch(move[0][0]) {
            case 'L':
                --head_delta[0];
                break;
            case 'R':
                ++head_delta[0];
                break;
            case 'D':
                --head_delta[1];
                break;
            case 'U':
                ++head_delta[1];
                break;
        }

        for(int i = 0; i < stoi(move[1]); ++i) {
            head_position[0] += head_delta[0];
            head_position[1] += head_delta[1];

            tail_move(tail_positions, head_position);
        }
    }

    int unique_positions = set<vector<int>>(tail_positions.begin(), tail_positions.end()).size();
    return unique_positions;
}

int d9_p2(vector<string> file) {
    vector<vector<string>> input = parse_input(file);
    vector<vector<int>> tail_positions;
    vector<vector<int>> rope(10, {0, 0});
    tail_positions.push_back(rope[0]);
    int count = 0;
    for (auto move : input) {
        vector<int> head_delta(2, 0);
        switch(move[0][0]) {
            case 'L':
                --head_delta[0];
                break;
            case 'R':
                ++head_delta[0];
                break;
            case 'D':
                --head_delta[1];
                break;
            case 'U':
                ++head_delta[1];
                break;
        }

        for(int i = 0; i < stoi(move[1]); ++i) {
            rope[0][0] += head_delta[0];
            rope[0][1] += head_delta[1];

            for (int j = 0; j < rope.size() - 1; ++j) {
                vector<int> new_position = tail_move_p2(rope[j+1], rope[j]);
                rope[j+1] = new_position;
                if(j+1 == rope.size()-1)
                    tail_positions.push_back(rope[j+1]);
            }
        }
    }

    int unique_positions = set<vector<int>>(tail_positions.begin(), tail_positions.end()).size();
    return unique_positions;
}