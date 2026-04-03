// #ifndef EV_LOGIC_H
// #define EV_LOGIC_H

// #include <set>
// #include <vector>
// #include "graph.h"

// using namespace std;

// extern set<int> chargingStations;

// bool canTravel(int distance, int battery);
// int findBestStation(const vector<int>& dist, int source, int battery, int destination, Graph& g, const set<int>& visited);

// #endif

#ifndef EV_LOGIC_H
#define EV_LOGIC_H

#include "graph.h"
#include <vector>
#include <map>
#include <string>

using namespace std;

struct Node {
    string name;
    double lat;
    double lon;
};

void simulateEV(const vector<int>& path, Graph& g, int battery,
                const map<int, Node>& nodes);

#endif