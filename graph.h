#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
using namespace std;

struct Edge {
    int to;
    int weight;
};

class Graph {
public:
    int V;
    vector<vector<Edge>> adj;

    Graph(int v);
    void addEdge(int u, int v, int dist);
};

#endif