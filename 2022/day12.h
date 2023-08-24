#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include "helpers.h"
using namespace std;

class Node {
public:
    char height;
    vector<int> coords;
    int distance;

    Node(char heightIn, vector<int> coordsIn)
        :height(heightIn), coords(coordsIn), distance(2147483647){
            if(height == 'S')
                distance = 0;
        }
};

bool node_compare(Node* a, Node* b){
    return a->distance < b->distance;
}

void set_new_dist(int currentDist, Node& node) {
    if(++currentDist < node.distance)
        node.distance = currentDist;
}

bool check(int coords, int delta, int range) {
    return coords + delta >= 0 && coords + delta < range;
}

bool traversable(Node a, Node b) {
    int real_a = a.height == 'E' ? 'z' : a.height == 'S' ? 'a' : a.height;
    int real_b = b.height == 'E' ? 'z' : b.height == 'S' ? 'a' : b.height;
    if(real_b <= real_a + 1) return true;
    return false;
}

int d12_p1(vector<string> file) {
    vector<vector<Node*>> mountain;
    vector<int> deltas = {-1, 1};
    vector<Node*> to_visit;
    for(int i = 0; i < file.size(); ++i) {
        vector<Node*> row;
        for(int j = 0; j < file[i].size(); ++j) {
            Node* node = new Node(file[i][j], {i, j});
            row.push_back(node);
            to_visit.push_back(node);
        }
        mountain.push_back(row);
    }

    while(!to_visit.empty()) {
        sort(to_visit.begin(), to_visit.end(), node_compare);
        Node* current = to_visit[0];
        vector<int> coords = current->coords;
        //add adjacent nodes
        for(auto delta : deltas) {
            if(check(coords[0], delta, mountain.size()) && traversable(*current, *mountain[coords[0] + delta][coords[1]])){
                set_new_dist(current->distance, *mountain[coords[0] + delta][coords[1]]);
            }
            if(check(coords[1], delta, mountain[coords[0]].size()) && traversable(*current, *mountain[coords[0]][coords[1] + delta])){
                set_new_dist(current->distance, *mountain[coords[0]][coords[1]+delta]);
            } 
        }

        to_visit.erase(to_visit.begin());
        if(current->height == 'E') {
            return current->distance;
        }
    }

    return -1;
}