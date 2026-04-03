#include "dijkstra.h"
#include <queue>
#include <climits>

using namespace std;

vector<int> dijkstra(Graph &g, int src, vector<int> &parent) {
    vector<int> dist(g.V, INT_MAX);
    parent.assign(g.V, -1);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto edge : g.adj[u]) {
            int v = edge.to;
            int w = edge.weight;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}