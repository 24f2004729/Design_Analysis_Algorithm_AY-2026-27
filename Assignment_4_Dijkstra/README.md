# Assignment 4: Dijkstra's Algorithm for Emergency Vehicle Routing

## Problem
A smart city traffic system must route ambulances to the nearest hospital
in the shortest possible time, over a road network where travel times
(edge weights) can change dynamically due to traffic congestion.

## Files
- `dijkstra.cpp` — Dijkstra's algorithm (binary heap / priority queue based)
  from a source to all nodes, with a `nearestHospital` helper to compare
  multiple hospital destinations, and support for dynamic edge-weight
  updates to simulate real-time traffic changes.

## How to Run
```bash
g++ -std=c++17 -O2 -o dijkstra dijkstra.cpp
./dijkstra
```
The example graph and a simulated traffic-congestion update are hard-coded
in `main()` for demonstration — edit the graph there to model a different
city layout.

## Complexity Summary
| Operation                          | Complexity        |
|-------------------------------------|--------------------|
| Dijkstra (binary heap)              | O((V + E) log V)  |
| Dynamic weight update on one edge   | O(degree(u))      |
| Space                                | O(V + E)          |

For very large city graphs with frequent real-time updates, consider a
bidirectional search, A*, or a dynamic shortest-path data structure to
scale further.

## Future Additions (placeholder)
- Visualization of the route (map/diagram)
- Report / write-up
- Larger real-world road network datasets
