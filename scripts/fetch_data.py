import json

print("Fetching charging stations (offline fallback)...")

# Simulated API response (based on real data)
data = []

data = [
    {"AddressInfo": {"Town": "Delhi"}},
    {"AddressInfo": {"Town": "Gurugram"}},
    {"AddressInfo": {"Town": "Noida"}},
    {"AddressInfo": {"Town": "Jaipur"}},
    {"AddressInfo": {"Town": "Agra"}},
    {"AddressInfo": {"Town": "Lucknow"}},
    {"AddressInfo": {"Town": "Chandigarh"}},
    {"AddressInfo": {"Town": "Amritsar"}},

    {"AddressInfo": {"Town": "Ahmedabad"}},
    {"AddressInfo": {"Town": "Udaipur"}},
    {"AddressInfo": {"Town": "Jodhpur"}},
    {"AddressInfo": {"Town": "Surat"}},
    {"AddressInfo": {"Town": "Mumbai"}},
    {"AddressInfo": {"Town": "Nashik"}},
    {"AddressInfo": {"Town": "Pune"}},

    {"AddressInfo": {"Town": "Indore"}},
    {"AddressInfo": {"Town": "Bhopal"}},
    {"AddressInfo": {"Town": "Nagpur"}},
    {"AddressInfo": {"Town": "Raipur"}},

    {"AddressInfo": {"Town": "Hyderabad"}},
    {"AddressInfo": {"Town": "Bangalore"}},
    {"AddressInfo": {"Town": "Mysore"}},
    {"AddressInfo": {"Town": "Chennai"}},
    {"AddressInfo": {"Town": "Coimbatore"}},
    {"AddressInfo": {"Town": "Madurai"}},
    {"AddressInfo": {"Town": "Tiruchirappalli"}},
    {"AddressInfo": {"Town": "Kochi"}},
    {"AddressInfo": {"Town": "Thiruvananthapuram"}},

    {"AddressInfo": {"Town": "Kolkata"}},
    {"AddressInfo": {"Town": "Bhubaneswar"}},
    {"AddressInfo": {"Town": "Patna"}},
    {"AddressInfo": {"Town": "Ranchi"}},
    {"AddressInfo": {"Town": "Dhanbad"}},
    {"AddressInfo": {"Town": "Guwahati"}},
    {"AddressInfo": {"Town": "Siliguri"}},

    {"AddressInfo": {"Town": "Gwalior"}},
    {"AddressInfo": {"Town": "Jhansi"}},
    {"AddressInfo": {"Town": "Kota"}},
    {"AddressInfo": {"Town": "Bareilly"}},
    {"AddressInfo": {"Town": "Aligarh"}},

    {"AddressInfo": {"Town": "Dehradun"}},
    {"AddressInfo": {"Town": "Shimla"}},
    {"AddressInfo": {"Town": "Goa"}},
    {"AddressInfo": {"Town": "Visakhapatnam"}},
    {"AddressInfo": {"Town": "Vijayawada"}}
]

city_to_id = {
    "Delhi": 0,
    "Mumbai": 1,
    "Bangalore": 2,
    "Chennai": 3,
    "Kolkata": 4,
    "Hyderabad": 5,
    "Pune": 6,
    "Ahmedabad": 7,
    "Jaipur": 8,
    "Lucknow": 9,
    "Chandigarh": 10,
    "Bhopal": 11,
    "Indore": 12,
    "Nagpur": 13,
    "Surat": 14,
    "Patna": 15,
    "Ranchi": 16,
    "Guwahati": 17,
    "Kochi": 18,
    "Thiruvananthapuram": 19,

    "Coimbatore": 20,
    "Nashik": 21,
    "Agra": 22,
    "Varanasi": 23,
    "Kanpur": 24,
    "Amritsar": 25,
    "Jodhpur": 26,
    "Udaipur": 27,
    "Raipur": 28,
    "Bhubaneswar": 29,
    "Dehradun": 30,
    "Shimla": 31,
    "Goa": 32,
    "Mysore": 33,
    "Visakhapatnam": 34,
    "Vijayawada": 35,
    "Madurai": 36,
    "Tiruchirappalli": 37,
    "Gwalior": 38,
    "Jhansi": 39,
    "Kota": 40,
    "Bareilly": 41,
    "Aligarh": 42,
    "Noida": 43,
    "Gurugram": 44,
    "Faridabad": 45,
    "Dhanbad": 46,
    "Siliguri": 47,
    "Imphal": 48,
    "Aizawl": 49
}

stations = set()

for item in data:
    city = item["AddressInfo"]["Town"]

    if city in city_to_id:
        stations.add(city_to_id[city])

# write to file
with open("data/stations.txt", "w") as f:
    for s in sorted(stations):
        f.write(str(s) + "\n")

print("✅ stations.txt updated!")
print("Stations:", stations)