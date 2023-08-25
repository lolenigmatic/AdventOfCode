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
    bool visited;

    Node(char heightIn, vector<int> coordsIn)
        :height(heightIn), coords(coordsIn), distance(200000000), visited(false){
            if(height == 'S')
                distance = 0;
        }
};

bool node_compare(Node* a, Node* b){
    return a->distance < b->distance;
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
    deque<Node*> to_visit;
    for(int i = 0; i < file.size(); ++i) {
        vector<Node*> row;
        for(int j = 0; j < file[i].size(); ++j) {
            Node* node = new Node(file[i][j], {i, j});
            row.push_back(node);
            if(node->distance == 0) {
                to_visit.push_back(node);
                node->visited = true;
            }
        }
        mountain.push_back(row);
    }

    while(!to_visit.empty()) {
        Node* current = to_visit.front();
        vector<int> coords = current->coords;
        cout<<coords[0]<<" "<<coords[1]<<endl;
        cout<<current->distance<<endl;
        //add adjacent nodes
        for(auto delta : deltas) {
            if(check(coords[0], delta, mountain.size()) && traversable(*current, *mountain[coords[0] + delta][coords[1]]) && !mountain[coords[0] + delta][coords[1]]->visited){
                mountain[coords[0] + delta][coords[1]]->distance = current->distance + 1;
                to_visit.push_back(mountain[coords[0] + delta][coords[1]]);
                mountain[coords[0] + delta][coords[1]]->visited = true;
            }
            if(check(coords[1], delta, mountain[coords[0]].size()) && traversable(*current, *mountain[coords[0]][coords[1] + delta]) && !mountain[coords[0]][coords[1] + delta]->visited){
                mountain[coords[0]][coords[1]+delta]->distance = current->distance + 1;
                to_visit.push_back(mountain[coords[0]][coords[1]+delta]);
                mountain[coords[0]][coords[1]+delta]->visited = true;
            } 
        }
        to_visit.pop_front();
        if(current->height == 'E') {
            return current->distance;
        }
    }

    return -1;
}

int d12_p2(vector<string> file) {
    vector<vector<Node*>> mountain;
    vector<int> deltas = {-1, 1};
    vector<vector<int>> possible_starts;
    vector<int> min_distances;

    for(int i = 0; i < file.size(); ++i) {
        vector<Node*> row;
        for(int j = 0; j < file[i].size(); ++j) {
            Node* node = new Node(file[i][j], {i, j});
            row.push_back(node);
            if(node->height == 'S')
                node->height = 'a';
            if(node->height == 'a') {
                possible_starts.push_back({i, j});
            }
        }
        mountain.push_back(row);
    }
    for(auto starting_coord : possible_starts) {
        deque<Node*> to_visit;
        for(int i = 0; i < file.size(); ++i) {
            for(int j = 0; j < file[i].size(); ++j) {
                if(i == starting_coord[0] && j == starting_coord[1]){
                    to_visit.push_back(mountain[i][j]);
                    mountain[i][j]->distance = 0;
                    mountain[i][j]->visited = true;
                }
                else {
                    mountain[i][j]->distance = 200000000;
                    mountain[i][j]->visited = false;
                }
            }
        }
        while(!to_visit.empty()) {
            Node* current = to_visit.front();
            vector<int> coords = current->coords;
            //add adjacent nodes
            for(auto delta : deltas) {
                if(check(coords[0], delta, mountain.size()) && traversable(*current, *mountain[coords[0] + delta][coords[1]]) && !mountain[coords[0] + delta][coords[1]]->visited){
                    mountain[coords[0] + delta][coords[1]]->distance = current->distance + 1;
                    to_visit.push_back(mountain[coords[0] + delta][coords[1]]);
                    mountain[coords[0] + delta][coords[1]]->visited = true;
                }
                if(check(coords[1], delta, mountain[coords[0]].size()) && traversable(*current, *mountain[coords[0]][coords[1] + delta]) && !mountain[coords[0]][coords[1] + delta]->visited){
                    mountain[coords[0]][coords[1]+delta]->distance = current->distance + 1;
                    to_visit.push_back(mountain[coords[0]][coords[1]+delta]);
                    mountain[coords[0]][coords[1]+delta]->visited = true;
                } 
            }
            to_visit.pop_front();
            if(current->height == 'E') {
                min_distances.push_back(current->distance);
            }
        }
    }
    
    return *min_element(min_distances.begin(), min_distances.end());
}