#pragma once
#include <vector>
using std::vector;

class PriorityQueue {
private:
    vector<int> elements;
    void shift_up(int pos);
    void shift_down(int pos);

public:

    PriorityQueue();
    ~PriorityQueue();

    bool is_empty();
    void push(int pos);
    void pop();
    int top();
    void clear();
    void printAsArray();
    void printAsTree();
};