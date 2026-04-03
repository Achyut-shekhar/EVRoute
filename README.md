EVRoute – Smart EV Charging Assistant

EVRoute is a C++ project that helps electric vehicle users find the nearest reachable charging station based on their current battery level.

Instead of planning an entire journey, this system focuses on a real-world problem:

“I’m low on battery — where should I go right now?”

What This Project Does
Takes your current city and battery percentage
Calculates how far you can travel
Finds the nearest reachable charging cities
Shows the best options (top 3)
Displays:
Optimal path
Battery left after reaching
Safety margin
Charging stations available in that city
Special Feature

If you're already in a city that has charging stations:

The system will recognize it instantly and suggest charging there instead of navigating elsewhere.

How It Works
Cities are modeled as nodes in a graph
Roads between cities are edges with distances
Dijkstra’s algorithm is used to find shortest paths
Battery constraint ensures only reachable stations are suggested
Charging Station Logic

Unlike simple models:

Each city can have multiple charging stations
Stations are loaded dynamically from a dataset
The system suggests the best city, then shows all available stations inside it
Project Structure
EVRoute/
│
├── main.cpp          # User interaction + flow control
├── graph.cpp/h       # Graph representation
├── dijkstra.cpp/h    # Shortest path logic
├── ev_logic.cpp/h    # EV-specific logic (core intelligence)
│
├── data/
│   └── stations.txt  # Charging stations per city
│
└── fetch_data.py     # Generates realistic station dataset
Example Run
Enter current city: gurugram
Enter battery %: 20

You are already at a charging station: Gurugram

Battery Before Charge: 80 km (20%)

Charging... Done!
Battery After Charge: 100% (400 km range)

Available Charging Stations:
  - Relicell_Gurugram_1
  - TataPower_Gurugram_2
Key Features
Real-world EV use case (low battery scenario)
Multi-station support per city
Battery-aware routing
Safety margin warnings
Clean and readable output
Scalable to large datasets (50+ cities)
Future Improvements
Find nearest station inside a city (using coordinates)
Map-based visualization (UI)
Charging time estimation
Live data integration (APIs)
Traffic-aware routing
Why This Project Stands Out

Most EV projects simulate full routes.

EVRoute focuses on something more practical:

Helping users make quick, safe decisions when battery is low

How to Run
g++ main.cpp graph.cpp dijkstra.cpp ev_logic.cpp -o evroute
./evroute
Author

Built as a systems + algorithm project focusing on real-world EV challenges.