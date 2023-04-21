#include "Graph.h"
#include "priorityQueue.h"
#include <iostream>
#include <queue>
using std::make_pair;

AdjancentMatrixGraph::AdjancentMatrixGraph(int v_count)
{
    g.resize(v_count);
    for (int i = 0; i < v_count; ++i)
        g[i].resize(v_count);
    this->v_count = v_count;
}

AdjancentMatrixGraph::~AdjancentMatrixGraph() {
    clear();
}

void AdjancentMatrixGraph::insert(int v, int w, int weight)
{
    if (v >= v_count || w >= v_count)
    {
        v_count = (v > w ? v : w) + 1;
        g.resize(v_count);
        for (int i = 0; i < v_count; ++i)
            g[i].resize(v_count);
    }
    g[v][w] = weight;
    g[w][v] = weight;
}

void AdjancentMatrixGraph::remove(int v, int w) {
    if (v >= v_count || w >= v_count) {
        return;
    }
    g[v][w] = 0;
    g[w][v] = 0;
}

void AdjancentMatrixGraph::clear() {
    for (int i = 0; i < v_count; i++) {
        g[i].clear();
    }
    g.clear();
    v_count = 0;
}

vector<pair<int, int>> AdjancentMatrixGraph::adjacent_vertices(int v) {
    vector<pair<int, int>> vec;
    if (v >= v_count)
        return vec;

    for (int i = 0; i < v_count; ++i) {
        if (g[v][i] != 0) {
            vec.push_back(make_pair(i, g[v][i]));
        }
    }
    return vec;
}

int AdjancentMatrixGraph::getSize() {
    return v_count;
}

void AdjancentMatrixGraph::print()
{
    for (int i = 1; i < v_count; ++i) {
        for (int j = 1; j < v_count; ++j)
            std::cout << g[i][j] << " ";
        std::cout << std::endl;
    }
}

void AdjancentMatrixGraph::print_adj_vert(int v)
{
    vector<pair<int, int>> vec = adjacent_vertices(v);
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i].first << "," << vec[i].second << " ";
    }
}

vector<int> AdjancentMatrixGraph::isReachable(int src, int dest)
{
    vector<int> a;
    // �������� ����� ���������� ����� � Graph
    int n = v_count;

    // ����� �����������, ������� ������� ��� ���
    vector<bool> discovered(n);

    // ������� queue ��� ���������� BFS
    std::queue<int> q;

    // �������� �������� ������� ��� ������������
    discovered[src] = true;

    // ��������� �������� ������� � queue
    q.push(src);

    // ���� �� ��� ���, ���� queue �� ������ ������
    while (!q.empty())
    {
        // ������� �������� ���� �� ������� � �������� ���
        int v = q.front();
        a.push_back(q.front());
        q.pop();

        // ���� ������� ������� �������
        if (v == dest) {
            return a;
        }

        // ������ ��� ������� ����� (v, u)
        for (int i = 1; i < v_count; i++)
        {
            if (!discovered[i])
            {
                // �������� ��� ��� ������������ � ������ � queue
                discovered[i] = true;
                q.push(i);
            }
        }
    }

    return a;
}

void AdjancentMatrixGraph::print_vec(vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
}

vector<int>  AdjancentMatrixGraph::prim(){
vector<int> visited(v_count, 0); 
PriorityQueue pq; 
vector<int> result; 

visited[0] = 1;

// ��������� ��� �����, ��������� �� ������� 0, � ������������ �������
for (int i = 0; i < v_count; i++) {
    if (g[0][i] != 0) {
        pq.push(g[0][i]);
    }
}

// ���� ������������ ������� �� �����
while (!pq.is_empty()) {
    // ��������� ����� � ���������� �����
    int edge = pq.top();
    pq.pop();
    // ������� �������, ����������� ���� ������
    int u = -1, v = -1;
    for (int i = 0; i < v_count; i++) {
        for (int j = i + 1; j < v_count; j++) {
            if (g[i][j] == edge) {
                u = i;
                v = j;
                break;
            }
        }
        if (u != -1 && v != -1)
            break;
    }
    // ���� �������, ��������������� ����� �����, �� ���� ��������
    if (visited[v] == 0) {
        // ��������� �� � visited � ��������� ��� ��������� �� ��� ����� � ������������ �������
        visited[v] = 1;
        result.push_back(v);
        for (int i = 0; i < v_count; i++) {
            if (g[v][i] != 0 && visited[i] == 0) {
                pq.push(g[v][i]);
            }
        }
    }
}
// ��������� ��������� ������� � ���������
result.insert(result.begin(), 0);

return result;
}
