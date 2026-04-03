#include "ev_logic.h"
#include "dijkstra.h"
#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

vector<int> reconstructPath(const vector<int>& parent, int src, int dest) {
    vector<int> path;
    for (int v = dest; v != -1; v = parent[v])
        path.push_back(v);

    reverse(path.begin(), path.end());
    if (path.empty() || path[0] != src) return {};
    return path;
}

void findBestStations(int source, int battery, Graph& g,
                      const map<int, vector<string>>& cityStations,
                      const map<int, Node>& nodes) {

    vector<int> parent;
    vector<int> dist = dijkstra(g, source, parent);

    vector<pair<int,int>> candidates;

    //  iterate over cities instead of stations
    for (auto &entry : cityStations) {
        int city = entry.first;

        if (dist[city] != INT_MAX && dist[city] <= battery) {
            candidates.push_back({dist[city], city});
        }
    }

    if (candidates.empty()) {
        cout << "\n No reachable charging cities!\n";
        return;
    }

    sort(candidates.begin(), candidates.end());

    cout << "\n TOP CHARGING OPTIONS:\n";

    int limit = min(3, (int)candidates.size());

    for (int i = 0; i < limit; i++) {


        int d = candidates[i].first;
        int city = candidates[i].second;

        vector<int> path = reconstructPath(parent, source, city);

        cout << "\nOption " << i+1 << ": " << nodes.at(city).name << "\n";
        cout << "Distance: " << d << " km\n";

        cout << "Path: ";
        for (int j = 0; j < path.size(); j++) {
            cout << nodes.at(path[j]).name;
            if (j != path.size() - 1) cout << " -> ";
        }
        cout << "\n";

        int remaining = battery - d;
        int percent = (remaining * 100) / 400;

        cout << "Battery Left After Arrival: "
            << remaining << " km (" << percent << "%)\n";

        if (battery - d < 20)
            cout << " Low safety margin!\n";
        else
            cout << " Safe to reach\n";

        //  NEW: show stations inside city
        cout << "Available Charging Stations:\n";

        const vector<string>& stations = cityStations.at(city);

        for (int k = 0; k < stations.size(); k++) {
            cout << "  - " << stations[k] << "\n";
        }
    }

    cout << "\n BEST OPTION: " << nodes.at(candidates[0].second).name << "\n";
}