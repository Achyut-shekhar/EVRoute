import math

# Load nodes
nodes = {}

with open("data/nodes.txt") as f:
    for line in f:
        parts = line.split()
        id = int(parts[0])
        lat = float(parts[2])
        lon = float(parts[3])
        nodes[id] = (lat, lon)

def distance(a, b):
    return int(math.sqrt((a[0]-b[0])**2 + (a[1]-b[1])**2) * 111)

edges = []

for i in nodes:
    for j in nodes:
        if i < j:
            d = distance(nodes[i], nodes[j])

            # connect only nearby cities
            if d < 600:
                edges.append((i, j, d))

with open("data/edges.txt", "w") as f:
    for u, v, d in edges:
        f.write(f"{u} {v} {d}\n")

print("✅ edges.txt generated!")