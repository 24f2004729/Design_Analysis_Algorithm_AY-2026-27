#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Dijkstra's Algorithm
void dijkstra(int source,
              const vector<vector<pair<int, int>>> &graph,
              vector<int> &dist) {

    int V = graph.size();

    // Initially, distance to every vertex is infinity
    dist.assign(V, INT_MAX);

    // Distance from source to itself is 0
    dist[source] = 0;

    // Min-heap: {distance, vertex}
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    pq.push({0, source});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // Ignore outdated distance
        if (d > dist[u])
            continue;

        // Check all neighbours of u
        for (const auto &edge : graph[u]) {
            int v = edge.first;
            int w = edge.second;

            // Relaxation
            if (dist[u] != INT_MAX && dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    int V, E;

    cout << "Enter number of intersections (vertices): ";
    if (!(cin >> V)) return 0;

    cout << "Enter number of roads (edges): ";
    cin >> E;

    // Create graph with V vertices
    vector<vector<pair<int, int>>> graph(V);

    cout << "Enter edges (u v w):\n";

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        // Undirected road
        if (u >= 0 && u < V && v >= 0 && v < V) {
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }
    }

    // Ambulance starting point
    int source;
    cout << "Enter ambulance start location (source): ";
    cin >> source;

    // Number of hospitals
    int H;
    cout << "Enter number of hospitals: ";
    cin >> H;

    // Store hospital nodes
    vector<int> hospitals(H);
    cout << "Enter hospital nodes: ";
    for (int i = 0; i < H; i++) {
        cin >> hospitals[i];
    }

    // Run Dijkstra from ambulance location
    vector<int> dist;
    dijkstra(source, graph, dist);

    // Find nearest hospital
    int minTime = INT_MAX;
    int nearestHospital = -1;

    for (int h : hospitals) {
        if (h >= 0 && h < V && dist[h] < minTime) {
            minTime = dist[h];
            nearestHospital = h;
        }
    }

    // Display result
    if (nearestHospital == -1 || minTime == INT_MAX) {
        cout << "No hospital reachable.\n";
    } else {
        cout << "Nearest hospital is at node "
             << nearestHospital
             << " with travel time "
             << minTime
             << " minutes.\n";
    }

    return 0;
}
