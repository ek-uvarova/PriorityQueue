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
    // получаем общее количество узлов в Graph
    int n = v_count;

    // чтобы отслеживать, открыта вершина или нет
    vector<bool> discovered(n);

    // создаем queue для выполнения BFS
    std::queue<int> q;

    // помечаем исходную вершину как обнаруженную
    discovered[src] = true;

    // поставить исходную вершину в queue
    q.push(src);

    // цикл до тех пор, пока queue не станет пустой
    while (!q.empty())
    {
        // удаляем передний узел из очереди и печатаем его
        int v = q.front();
        a.push_back(q.front());
        q.pop();

        // если целевая вершина найдена
        if (v == dest) {
            return a;
        }

        // делаем для каждого ребра (v, u)
        for (int i = 1; i < v_count; i++)
        {
            if (!discovered[i])
            {
                // помечаем его как обнаруженный и ставим в queue
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

// добавляем все ребра, выходящие из вершины 0, в приоритетную очередь
for (int i = 0; i < v_count; i++) {
    if (g[0][i] != 0) {
        pq.push(g[0][i]);
    }
}

// пока приоритетная очередь не пуста
while (!pq.is_empty()) {
    // извлекаем ребро с наименьшим весом
    int edge = pq.top();
    pq.pop();
    // находим вершины, соединяемые этим ребром
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
    // если вершина, соответствующая концу ребра, не была посещена
    if (visited[v] == 0) {
        // добавляем ее в visited и добавляем все выходящие из нее ребра в приоритетную очередь
        visited[v] = 1;
        result.push_back(v);
        for (int i = 0; i < v_count; i++) {
            if (g[v][i] != 0 && visited[i] == 0) {
                pq.push(g[v][i]);
            }
        }
    }
}
// добавляем начальную вершину в результат
result.insert(result.begin(), 0);

return result;
}
