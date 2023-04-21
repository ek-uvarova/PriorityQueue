#include <iostream>
#include "PriorityQueue.h"
#include "Graph.h"

int main() {
    PriorityQueue q;
    q.push(10);
    q.push(5);
    q.push(15);
    q.push(1);
    q.push(20);
    /*std::cout << q.top() << std::endl;
    q.pop();
    std::cout << q.top() << std::endl;*/
    /*q.push(25);
    q.push(11);
    q.push(12);
    q.push(4);
    q.push(2);*/
 
    q.printAsArray();
    std::cout << std::endl << std::endl;
    q.printAsTree();


   /* AdjancentMatrixGraph a(5);
    a.insert(0, 1, 3);
    a.insert(1, 2, 10);
    a.insert(2, 3, 5);
    a.insert(3, 1, 7);
    a.insert(3, 4, 8);
    a.insert(2, 4, 6);
    a.print();
    for (int i=0; i < a.prim().size(); i++) {
        std::cout << a.prim().at(i);
    }*/

    return 0;
}