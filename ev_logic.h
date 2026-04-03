#ifndef EV_LOGIC_H
#define EV_LOGIC_H

#include "graph.h"
#include <set>
#include <map>
#include <vector>
#include <string>

using namespace std;

struct Node {
    string name;
    double lat;
    double lon;
};

vector<int> reconstructPath(const vector<int>& parent, int src, int dest);

void findBestStations(int source, int battery, Graph& g,
                      const map<int, vector<string>>& cityStations,
                      const map<int, Node>& nodes);

#endif