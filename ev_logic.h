#ifndef EV_LOGIC_H
#define EV_LOGIC_H

#include <set>
#include <vector>

using namespace std;

extern set<int> chargingStations;

bool canTravel(int distance, int battery);
int findNearestStation(vector<int>& dist);

#endif