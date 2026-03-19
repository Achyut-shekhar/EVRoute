#include "ev_logic.h"
#include <climits>

set<int> chargingStations;

bool canTravel(int distance, int battery) {
    return battery >= distance;
}

int findNearestStation(vector<int>& dist) {
    int minDist = INT_MAX;
    int station = -1;

    for(int s : chargingStations) {
        if(dist[s] < minDist) {
            minDist = dist[s];
            station = s;
        }
    }
    return station;
}