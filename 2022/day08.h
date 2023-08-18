#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include "helpers.h"
using namespace std;

vector<vector<int>> convert_grid(vector<string> file) {
    vector<vector<int>> grid;

    for(auto line : file) {
        vector<int> thisLine;
        for(auto digit : line) {
            thisLine.push_back(int(digit));
        }
        grid.push_back(thisLine);
    }

    return grid;
}

bool is_visible(vector<vector<int>> grid, int row, int col) {
    //this can be cut down into a faster calculation concerning the dimensions
    if(row == 0 || col == 0 || row == grid[0].size()-1 || col == grid.size()-1)
        return true;
    
    int tree = grid[row][col];

    bool is_still_visible = true;

    for(int i = col+1; i < grid[row].size(); ++i) {
        if (grid[row][i] >= tree) {
            is_still_visible = false;
            break;
        }
    }
    if (is_still_visible) return true;

    is_still_visible = true;
    for(int i = col-1; i >= 0; --i) {
        if (grid[row][i] >= tree) {
            is_still_visible = false;
            break;   
        }
    }
    if (is_still_visible) return true;

    is_still_visible = true;
    for(int i = row+1; i < grid.size(); ++i) {
        if (grid[i][col] >= tree) {
            is_still_visible = false;
            break;
        };
    }
    if (is_still_visible) return true;

    is_still_visible = true;
    for(int i = row-1; i >= 0; --i) {
        if (grid[i][col] >= tree) {
            is_still_visible = false;
            break;
        };
    }
    return is_still_visible;
}

int scenic_score(vector<vector<int>> grid, int row, int col) {
    //this can be cut down into a faster calculation concerning the dimensions
    
    int tree = grid[row][col];

    vector<int> visible_trees(4, 0);

    for(int i = col+1; i < grid[row].size(); ++i) {
        visible_trees[0]++;
        if (grid[row][i] >= tree) break;
    }

    for(int i = col-1; i >= 0; --i) {
        visible_trees[1]++;
        if (grid[row][i] >= tree) break;
    }

    for(int i = row+1; i < grid.size(); ++i) {
        visible_trees[2]++;
        if (grid[i][col] >= tree) break;
    }

    for(int i = row-1; i >= 0; --i) {
        visible_trees[3]++;
        if (grid[i][col] >= tree) break;
    }

    int prod = 1;
    for (auto num : visible_trees) prod = prod * num;
    return prod;
}

int d8_p1(vector<string> file) {
    
    vector<vector<int>> grid = convert_grid(file);
    int count = 0;
    
    for(int i = 0; i < grid.size(); ++i) {
        for(int j = 0; j < grid[i].size(); ++j) {
            if(is_visible(grid, i, j)) count++;
        }
    }

    return count;
}

int d8_p2(vector<string> file) {
    
    vector<vector<int>> grid = convert_grid(file);
    int max = 0;
    
    for(int i = 0; i < grid.size(); ++i) {
        for(int j = 0; j < grid[i].size(); ++j) {
            int score = scenic_score(grid, i, j);
            if(score > max) max = score;
        }
    }

    return max;
}