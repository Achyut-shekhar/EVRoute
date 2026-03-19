#include "graph.h"

Graph::Graph(int v) {
    V = v;
    adj.resize(V);
}

void Graph::addEdge(int u, int v, int dist) {
    adj[u].push_back({v, dist});
    adj[v].push_back({u, dist});
}