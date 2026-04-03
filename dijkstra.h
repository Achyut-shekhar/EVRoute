#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "graph.h"
#include <vector>

vector<int> dijkstra(Graph &g, int src, std::vector<int> &parent);

#endif