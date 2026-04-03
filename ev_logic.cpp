#include "ev_logic.h"
#include <iostream>
using namespace std;

int getDistance(int u, int v, Graph &g) {
    for (auto &edge : g.adj[u]) {
        if (edge.to == v)
            return edge.weight;
    }
    return -1;
}

void simulateEV(const vector<int>& path, Graph& g, int battery,
                const map<int, Node>& nodes) {

    int maxRange = 400;
    int remainingBattery = battery;

    cout << "\n---- EV ROUTE ----\n";

    for (int i = 1; i < path.size(); i++) {

        int u = path[i - 1];
        int v = path[i];

        int d = -1;

        for (auto &edge : g.adj[u]) {
            if (edge.to == v) {
                d = edge.weight;
                break;
            }
        }

        if (d == -1) {
            cout << "ERROR: Edge not found\n";
            return;
        }

        cout << "\n----------------------------------\n";
        cout << "From: " << nodes.at(u).name << "\n";
        cout << "To: " << nodes.at(v).name << "\n";
        cout << "Distance: " << d << " km\n";

        int percentBefore = (remainingBattery * 100) / maxRange;

        cout << "Battery Before Travel: "
             << remainingBattery << " km (" << percentBefore << "%)\n";

        //  Impossible case
        if (d > maxRange) {
            cout << " Cannot travel this segment (too long)\n";
            return;
        }

        //  Charge if needed
        if (remainingBattery < d) {

            cout << "\nCharging... Done!\n";

            remainingBattery = maxRange;

            cout << "Battery After Charge: 100% (400 km range)\n";
        }

        // Travel
        remainingBattery -= d;

        int percentAfter = (remainingBattery * 100) / maxRange;

        cout << "Arrived at: " << nodes.at(v).name << "\n";
        cout << "Battery After Arrival: "
             << remainingBattery << " km (" << percentAfter << "%)\n";
    }

    cout << "\n----------------------------------\n";
    cout << " Destination reached successfully!\n";
}