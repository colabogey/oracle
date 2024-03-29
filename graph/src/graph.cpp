
#include "graph.h"
#include "sptData.h"

Graph::Graph() { 
    m_pSptData = std::make_shared<SptData>();
}
Graph::~Graph() { 
    for(auto l : m_adjLists) {
        l.clear();
    }
    m_adjLists.clear();
}

void Graph::addDirectedEdge(int src, int dst, int weight) {
    _addEdge(src, dst, weight);
}

void Graph::addEdge(int src, int dst, int weight) {
    _addEdge(src, dst, weight);
    _addEdge(dst, src, weight);
}

void Graph::_addEdge(int src, int dst, int weight) {
    GraphVertex v(dst, weight);
    if(m_adjLists.size() < (src + 1)) {
        m_adjLists.resize(src + 1);
    }
    m_adjLists[src].push_back(v);
}

