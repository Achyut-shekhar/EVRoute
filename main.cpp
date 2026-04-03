#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include "graph.h"
#include "ev_logic.h"

using namespace std;

map<int, Node> nodes;
map<string, int> nameToId;
map<int, vector<string>> cityStations;

void loadStations() {
    ifstream file("data/stations.txt");

    int cityId;
    string line;

    while (file >> cityId) {
        vector<string> stations;

        getline(file, line);
        stringstream ss(line);

        string station;
        while (ss >> station) {
            stations.push_back(station);
        }

        cityStations[cityId] = stations;
    }
}

string toLower(string s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}

void loadData(Graph &g) {

    vector<string> cityNames = {
        "Delhi","Mumbai","Bangalore","Chennai","Kolkata",
        "Hyderabad","Pune","Ahmedabad","Jaipur","Lucknow",
        "Chandigarh","Bhopal","Indore","Nagpur","Surat",
        "Patna","Ranchi","Guwahati","Kochi","Thiruvananthapuram",
        "Coimbatore","Nashik","Agra","Varanasi","Kanpur",
        "Amritsar","Jodhpur","Udaipur","Raipur","Bhubaneswar",
        "Dehradun","Shimla","Goa","Mysore","Visakhapatnam",
        "Vijayawada","Madurai","Tiruchirappalli","Gwalior",
        "Jhansi","Kota","Bareilly","Aligarh","Noida",
        "Gurugram","Faridabad","Dhanbad","Siliguri",
        "Imphal","Aizawl"
    };

    for (int i = 0; i < cityNames.size(); i++) {
        nodes[i] = {cityNames[i], 0, 0};
        nameToId[toLower(cityNames[i])] = i;
    }
}

int main() {

    Graph g(50);
    loadData(g);

    loadStations(); 

    cout << "Available Locations:\n";
    for (auto &p : nodes)
        cout << p.second.name << "\n";

    string city;
    int batteryPercent;

    cout << "\nEnter current city: ";
    cin >> city;

    city = toLower(city);

    if (nameToId.find(city) == nameToId.end()) {
        cout << "Invalid city!\n";
        return 0;
    }

    int source = nameToId[city]; 

    cout << "Enter battery %: ";
    cin >> batteryPercent;

    int battery = (batteryPercent * 400) / 100;

    cout << "\n Searching nearest charging stations...\n";

    // UPDATED FUNCTION CALL
    findBestStations(source, battery, g, cityStations, nodes);

    return 0;
}