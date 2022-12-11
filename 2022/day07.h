#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include "helpers.h"
using namespace std;

class Node {
public:
    bool isFolder;
    long size;
    vector<Node*> children;
    Node* parent;
    string name;

    Node(bool isFolderIn, long sizeIn, Node* parentIn, string nameIn)
        : isFolder(isFolderIn), size(sizeIn), parent(parentIn), name(nameIn){
    }

    void addChild(Node* child) {
        children.push_back(child);
    }

    long getSizeP1(long & p1Total) {
        long totalSize = 0;

        for (auto child : children) {
            if (child->isFolder) {
                totalSize += child->getSizeP1(p1Total);
            }
            else {
                totalSize += child->size;
            }
        }

        if (totalSize <= 100000) p1Total += totalSize;

        return totalSize;
    }

    long getSizeP2(long & lowest, const long neededAmount) {

        long totalSize = 0;

        for (auto child : children) {
            if (child->isFolder) {
                totalSize += child->getSizeP2(lowest, neededAmount);
            }
            else {
                totalSize += child->size;
            }
        }

        if(totalSize >= neededAmount) {
            lowest = min(lowest, totalSize);
        }

        return totalSize;
    }

};

Node* makeFileSystem(vector<string> file) {
    Node* root = new Node(true, 0, nullptr, "/");
    Node* currentDir = root;
    bool displayingDir = false;


    for(auto line : file) {
        vector<string> args = split(line, " ");

        if(line == "$ cd /") continue;

        if(args[1] == "ls") {
            displayingDir = true;
            continue;
        }

        if(args[1] == "cd") {
            displayingDir = false;

            if (args[2] == "..") {
                currentDir = currentDir->parent;
                continue;
            }
            
            for(auto child : currentDir->children) {
                if (child->name == args[2]) {
                    currentDir = child;
                    break;
                }
            }

            continue;
        }

        if(args[0] == "dir") {
            Node * newFolder = new Node(true, 0, currentDir, args[1]);
            currentDir->addChild(newFolder);
            continue;
        }

        Node* newFile = new Node(false, stol(args[0]), currentDir, args[1]);
        currentDir->addChild(newFile);
    }

    return root;
}

int d7_p1(vector<string> file) {
    
    Node * root = makeFileSystem(file);
    long p1Total = 0;
    root->getSizeP1(p1Total);

    return p1Total;
}

int d7_p2(vector<string> file) {
    long lowestPossible = 1410065407;
    long dummy = 0;

    Node * root = makeFileSystem(file);

    long totalSize = root->getSizeP1(dummy);
    const long neededAmount = 30000000 - (70000000 - totalSize);

    root->getSizeP2(lowestPossible, neededAmount);

    return lowestPossible;
}