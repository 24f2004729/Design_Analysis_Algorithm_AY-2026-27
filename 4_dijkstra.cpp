// Assignment No. 4
// Smart Traffic Management for Emergency Vehicles
// Dijkstra's algorithm: shortest path from ambulance source S to all hospitals,
// with support for dynamic edge-weight updates (changing traffic conditions).

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <unordered_set>
#include <algorithm>
using namespace std;

struct Edge {
    int to;
    int weight; // travel time in minutes
};

class TrafficGraph {
private:
    int numNodes;
    vector<vector<Edge>> adj;

public:
    TrafficGraph(int n) : numNodes(n), adj(n) {}

    void addRoad(int u, int v, int travelTime, bool bidirectional = true) {
        adj[u].push_back({v, travelTime});
        if (bidirectional) adj[v].push_back({u, travelTime});
    }

    // Dynamically update the travel time of a specific road (u -> v)
    // Simulates real-time traffic congestion changes.
    void updateTraffic(int u, int v, int newTravelTime, bool bidirectional = true) {
        for (auto &e : adj[u]) {
            if (e.to == v) { e.weight = newTravelTime; break; }
        }
        if (bidirectional) {
            for (auto &e : adj[v]) {
                if (e.to == u) { e.weight = newTravelTime; break; }
            }
        }
    }

    // Standard Dijkstra using a min-heap: O((V + E) log V)
    vector<int> shortestPaths(int source, vector<int> &parent) {
        vector<int> dist(numNodes, INT_MAX);
        parent.assign(numNodes, -1);
        dist[source] = 0;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        pq.push({0, source});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (d > dist[u]) continue; // stale entry, skip

            for (const auto &edge : adj[u]) {
                int v = edge.to;
                int newDist = dist[u] + edge.weight;
                if (newDist < dist[v]) {
                    dist[v] = newDist;
                    parent[v] = u;
                    pq.push({newDist, v});
                }
            }
        }
        return dist;
    }

    // Find the nearest hospital among a given set of hospital node IDs
    int nearestHospital(int source, const vector<int> &hospitals, vector<int> &pathOut) {
        vector<int> parent;
        vector<int> dist = shortestPaths(source, parent);

        int best = -1, bestDist = INT_MAX;
        for (int h : hospitals) {
            if (dist[h] < bestDist) {
                bestDist = dist[h];
                best = h;
            }
        }

        // Reconstruct path from source to best hospital
        pathOut.clear();
        if (best != -1 && dist[best] != INT_MAX) {
            for (int cur = best; cur != -1; cur = parent[cur])
                pathOut.push_back(cur);
            reverse(pathOut.begin(), pathOut.end());
        }
        return bestDist;
    }
};

void printPath(const vector<int> &path) {
    for (size_t i = 0; i < path.size(); i++) {
        cout << path[i];
        if (i + 1 < path.size()) cout << " -> ";
    }
    cout << "\n";
}

int main() {
    // Example city graph: 8 intersections (0-7), node 5 and 7 are hospitals
    int n = 8;
    TrafficGraph city(n);

    city.addRoad(0, 1, 4);
    city.addRoad(0, 2, 2);
    city.addRoad(1, 3, 5);
    city.addRoad(2, 3, 8);
    city.addRoad(2, 4, 10);
    city.addRoad(3, 5, 6);   // hospital at 5
    city.addRoad(4, 6, 3);
    city.addRoad(6, 7, 2);   // hospital at 7
    city.addRoad(3, 6, 7);

    vector<int> hospitals = {5, 7};
    int source = 0; // ambulance location

    vector<int> path;
    int timeToNearest = city.nearestHospital(source, hospitals, path);

    cout << "--- Initial Traffic Conditions ---\n";
    cout << "Ambulance at node " << source << ". Nearest hospital reachable in "
         << timeToNearest << " minutes.\n";
    cout << "Route: ";
    printPath(path);

    // Simulate a dynamic traffic change: road (3 -> 5) gets congested
    cout << "\n--- Traffic congestion detected on road 3 -> 5, updating weight ---\n";
    city.updateTraffic(3, 5, 20); // travel time jumps from 6 to 20 minutes

    path.clear();
    timeToNearest = city.nearestHospital(source, hospitals, path);
    cout << "Recalculated: nearest hospital reachable in " << timeToNearest << " minutes.\n";
    cout << "Updated route: ";
    printPath(path);

    cout << "\n--- Complexity Analysis ---\n";
    cout << "Dijkstra with binary heap: O((V + E) log V) per query\n";
    cout << "Space: O(V + E) for adjacency list and heap\n";
    cout << "Dynamic weight updates are O(degree(u)) and require rerunning Dijkstra\n";
    cout << "from the source; for very large city graphs (thousands of nodes) with\n";
    cout << "frequent updates, consider a bidirectional or A* search for speed,\n";
    cout << "or a fully dynamic shortest-path data structure for further scaling.\n";

    return 0;
}
