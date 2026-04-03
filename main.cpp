#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <climits>
#include <algorithm>
#include "graph.h"
#include "dijkstra.h"
#include "ev_logic.h"

using namespace std;

string toLower(string s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}

map<int, Node> nodes;
map<string, int> nameToId;

void loadNodes() {
    ifstream file("data/nodes.txt");
    if (!file.is_open()) {
        cerr << "ERROR: Cannot open data/nodes.txt\n";
        return;
    }
    int id;
    string name;
    double lat, lon;
    while (file >> id >> name >> lat >> lon) {
        nodes[id] = {name, lat, lon};
        nameToId[toLower(name)] = id;
    }
}

void loadEdges(Graph &g) {
    ifstream file("data/edges.txt");
    if (!file.is_open()) {
        cerr << "ERROR: Cannot open data/edges.txt\n";
        return;
    }
    int u, v, dist;
    while (file >> u >> v >> dist) {
        g.addEdge(u, v, dist);
    }
}

void loadStations() {
    ifstream file("data/stations.txt");
    if (!file.is_open()) {
        cerr << "ERROR: Cannot open data/stations.txt\n";
        return;
    }

    string line;
    while (getline(file, line)) {
        int pos = line.find('#');
        if (pos != string::npos) line = line.substr(0, pos);

        if (line.empty()) continue;

        int x;
        stringstream ss(line);
        if (ss >> x) {
            // optional future use
        }
    }
}

vector<int> reconstructPath(const vector<int>& parent, int from, int to) {
    vector<int> path;
    int temp = to;

    while (temp != -1) {
        path.push_back(temp);
        temp = parent[temp];
    }

    reverse(path.begin(), path.end());

    if (path.empty() || path[0] != from) return {};
    return path;
}

int main() {

    loadNodes();

    if (nodes.empty()) {
        cout << "No nodes loaded.\n";
        return 1;
    }

    int maxId = 0;
    for (auto &p : nodes) {
        maxId = max(maxId, p.first);
    }

    Graph g(maxId + 1);
    loadEdges(g);
    loadStations();

    cout << "Available Locations:\n";
    for (auto &p : nodes) {
        cout << p.second.name << "\n";
    }

    string sourceName, destinationName;
    int batteryPercent;

    cout << "\nEnter source city: ";
    cin >> sourceName;

    cout << "Enter destination city: ";
    cin >> destinationName;

    sourceName = toLower(sourceName);
    destinationName = toLower(destinationName);

    if (nameToId.find(sourceName) == nameToId.end() ||
        nameToId.find(destinationName) == nameToId.end()) {
        cout << "Invalid city name!\n";
        return 1;
    }

    int source = nameToId[sourceName];
    int destination = nameToId[destinationName];

    cout << "Enter battery percentage (0-100): ";
    cin >> batteryPercent;

    int maxRange = 400;
    int battery = (batteryPercent * maxRange) / 100;

    vector<int> parent;
    vector<int> dist = dijkstra(g, source, parent);

    if (dist[destination] == INT_MAX) {
        cout << "❌ No path exists!\n";
        return 0;
    }

    vector<int> path = reconstructPath(parent, source, destination);

    cout << "\n---- SHORTEST PATH ----\n";
    for (int i = 0; i < path.size(); i++) {
        cout << nodes[path[i]].name;
        if (i != path.size() - 1) cout << " -> ";
    }
    cout << "\nTotal Distance: " << dist[destination] << " km\n";

    // ✅ Clean EV simulation
    simulateEV(path, g, battery, nodes);

    return 0;
}