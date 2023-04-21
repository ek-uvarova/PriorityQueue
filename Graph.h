#pragma once
#include <vector>
#include <string>
using std::vector;
using std::pair;

class AdjancentMatrixGraph {
    int v_count;
    vector<vector<int>> g;

public:
    AdjancentMatrixGraph(int v_count);
    ~AdjancentMatrixGraph();

    void insert(int v, int w, int weight);
    void remove(int v, int w);
    void clear();
    vector<pair<int, int>> adjacent_vertices(int v);
    int  getSize();
    void print();
    void print_adj_vert(int v);
    vector<int> isReachable(int src, int dest);
    void print_vec(vector<int> vec);
    vector<int> prim();
};