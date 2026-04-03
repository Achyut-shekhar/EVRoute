#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "graph.h"
#include <vector>

using namespace std;

vector<int> dijkstra(Graph &g, int src, vector<int> &parent);

#endif