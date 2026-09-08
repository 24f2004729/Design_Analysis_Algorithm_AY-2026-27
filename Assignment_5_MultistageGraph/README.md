# Assignment 5: Multistage Graph for SwiftCargo Delivery Routing

## Problem
SwiftCargo delivers packages across multiple cities via a staged network
(warehouses → transit hubs → final delivery points). Find the most
cost-efficient route from source to destination through the predefined
stages, at a scale of thousands of cities and routes, while accounting for
real-time constraints (traffic, weather, road closures).

## Files
- `multistage_graph.cpp` — Dynamic Programming solution to the multistage
  graph shortest-path problem (backward DP from destination to source),
  plus notes on falling back to Dijkstra for non-staged / dynamically
  changing graphs.

## How to Run
```bash
g++ -std=c++17 -O2 -o multistage_graph multistage_graph.cpp
./multistage_graph
```
The example network (4 stages: warehouse → 2 regional hubs → 3 transit
hubs → delivery point) is hard-coded in `main()` — edit it to model a
different stage/route structure.

## Complexity Summary
| Operation                    | Complexity |
|--------------------------------|------------|
| Backward DP shortest path      | O(V + E)   |
| Space                          | O(V + E)   |

For static, cleanly-staged networks this scales well to thousands of
cities/routes since each edge is examined once. For real-time constraint
changes that break the clean staging, re-run the DP after updating edge
weights, or use Dijkstra's algorithm for general dynamic-weight graphs.
Batch requests sharing a destination can reuse the same precomputed DP
cost table for O(1) lookups per new source.

## Future Additions (placeholder)
- Report / write-up
- Larger multi-city network datasets
- Batch-processing test cases
