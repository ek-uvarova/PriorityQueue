#include "priorityQueue.h"
#include <iostream>

PriorityQueue::PriorityQueue() = default;

PriorityQueue::~PriorityQueue() {
    clear();
}

void PriorityQueue::shift_up(int pos) {
    if (elements.size() > 1) {
        int i = pos;
        int parent = (i - 1) / 2;
        while (elements[i] < elements[parent]) {
            std::swap(elements[i], elements[parent]);
            i = parent;
            parent = (i - 1) / 2;
        }
    }
}

bool PriorityQueue::is_empty()
{
    return elements.empty();
}

void PriorityQueue::push(int elem) {
    elements.push_back(elem);
    shift_up(elements.size() - 1);

}

void PriorityQueue::shift_down(int pos) {
 
    int left_child = 2 * pos + 1;
    int right_child = 2 * pos + 2;
    int i = pos;
    int min_child = i;
    while (i < elements.size()) {
        
        if (left_child < elements.size() && elements[left_child] < elements[min_child]) {
            min_child = left_child;
        }
        if (right_child < elements.size() && elements[right_child] < elements[min_child]) {
            min_child = right_child;
        }

        if (min_child != i) {
            std::swap(elements[i], elements[min_child]);
            i = min_child;
            left_child = 2 * i + 1;
            right_child = 2 * i + 2;
        }
        else {
           break;
        }
    }
}

void PriorityQueue::pop() {
    if (!elements.empty()) {
        std::swap( elements[elements.size()-1], elements[0]);
        elements.pop_back();
        shift_down(0);
    }
}

int PriorityQueue::top() {
    if (!elements.empty())
        return elements[0];
}

void PriorityQueue::clear() {
    elements.clear();
}

void PriorityQueue::printAsArray() {
    PriorityQueue q;
    for (int i = 0; i < elements.size(); i++)
        q.push(elements[i]);
    for (int i = 0; i < elements.size(); i++) {
        std::cout << q.top() << " ";
        q.pop();
    }
    std::cout << std::endl;
}

void PriorityQueue::printAsTree() {
    int h = ceil(log2(elements.size())); // вычисляем высоту дерева
    int index = 0; // индекс элемента в векторе
    for (int i = 1; i <= h; i++) { // для каждого уровня дерева
        for (int j = 1; j <= pow(2, i - 1); j++) { // для каждого элемента на уровне
            if (index >= elements.size()) {
                break;
            }
            std::cout << elements[index] << " ";
            index++;
        }
        std::cout << std::endl;
    }
}