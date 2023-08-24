#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include "helpers.h"
using namespace std;

class Monkey {
public:
    vector<long> items;
    vector<string> operation;
    long divisible;
    vector<int> throwTo; //0 is true 1 is false
    long inspected;

    Monkey(vector<string> itemsIn, vector<string> operationIn, int divisibleIn, vector<int> throwToIn)
        : operation(operationIn), divisible(divisibleIn), throwTo(throwToIn), inspected(0){
            for(auto item : itemsIn)
                items.push_back(stol(item));
    }

    long doOperation(long old) {
        long a = operation[0] == "old" ? old : stol(operation[0]);
        long b = operation[2] == "old" ? old : stol(operation[2]);

        switch(operation[1][0]) {
            case '+':
                return a + b;
            case '-':
                return a - b;
            case '*':
                return a * b;
            case '/':
                return a / b;
        }
    }

    void turn(vector<Monkey>& monkeys) {
        auto it = items.begin();
        if (it == items.end())
            return;
        
        while(it != items.end()) {
            long result = doOperation(*it) / 3;
            if(result % divisible == 0) {
                monkeys[throwTo[0]].receiveItem(result);
            }
            else {
                monkeys[throwTo[1]].receiveItem(result);
            }
            inspected++;
            items.erase(it);
        }
    }

    void turn_p2(vector<Monkey>& monkeys, long monkeyRemainderProd) {
        auto it = items.begin();
        if (it == items.end())
            return;
        
        while(it != items.end()) {
            long result = doOperation(*it) % monkeyRemainderProd;
            if(result % divisible == 0) {
                monkeys[throwTo[0]].receiveItem(result);
            }
            else {
                monkeys[throwTo[1]].receiveItem(result);
            }
            inspected++;
            items.erase(it);
        }
    }

    void receiveItem(long item) {
        items.push_back(item);
    }

};

bool compareInterval(Monkey a, Monkey b)
{
    return (a.inspected > b.inspected);
}

int d11_p1(vector<string> file) {
    vector<Monkey> monkeys;

    for (int i = 0; i < file.size(); i += 7) {
        vector<string> items = split(file[i+1].substr(18), ", ");
        vector<string> operation = split(file[i+2].substr(19), " ");
        int divisible = stoi(file[i+3].substr(21));
        vector<int> throwTo;
        throwTo.push_back(stoi(file[i+4].substr(29)));
        throwTo.push_back(stoi(file[i+5].substr(30)));
        monkeys.push_back(Monkey(items, operation, divisible, throwTo));
    }

    for (int i = 0; i < 20; ++i) {
        for(int j = 0; j < monkeys.size(); ++j) {
            monkeys[j].turn(monkeys);
        }
    }

    for(auto monkey : monkeys) {
        cout<<monkey.inspected<<endl;
    }

    sort(monkeys.begin(), monkeys.end(), compareInterval);

    return monkeys[0].inspected * monkeys[1].inspected;
}

long d11_p2(vector<string> file) {
    vector<Monkey> monkeys;
    long monkeyRemainderProd = 1;

    for (int i = 0; i < file.size(); i += 7) {
        vector<string> items = split(file[i+1].substr(18), ", ");
        vector<string> operation = split(file[i+2].substr(19), " ");
        int divisible = stoi(file[i+3].substr(21));
        monkeyRemainderProd *= divisible;
        vector<int> throwTo;
        throwTo.push_back(stoi(file[i+4].substr(29)));
        throwTo.push_back(stoi(file[i+5].substr(30)));
        monkeys.push_back(Monkey(items, operation, divisible, throwTo));
    }

    for (int i = 0; i < 10000; ++i) {
        for(int j = 0; j < monkeys.size(); ++j) {
            monkeys[j].turn_p2(monkeys, monkeyRemainderProd);
        }
    }

    for(auto monkey : monkeys) {
        cout<<monkey.inspected<<endl;
    }

    sort(monkeys.begin(), monkeys.end(), compareInterval);

    return monkeys[0].inspected * monkeys[1].inspected;
}