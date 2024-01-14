#pragma once

#include "graphVertex.h"
#include <list>
#include <string>
#include <deque>
#include <vector>

class Graph {
  public:
    Graph() = default;
    Graph(int vtx);
    ~Graph() = default;
    Graph &operator=(Graph &other) { return *this; };
    Graph(Graph &other){};

    void addEdge(int, int, int);
    void BFS(int);
    void bfsSay(int, std::list<int> &);

    int main();
    void printShortestDistance(std::vector<int>[], int, int, int);
    bool shortestPath(std::vector<int>[], int, int, int, int[], int[]);
    void add_edge(std::vector<int>[], int, int);

    void spUnweighted(int, int);

  private:
    void _showSp(int, int, std::deque<int>, std::deque<int>);
    std::deque<std::list<GraphVertex>> m_adjLists;
};
