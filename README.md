# Design and Analysis of Algorithms Laboratory (AY 2026-27)

Contains the lab assignments for Design & Analysis of Algorithms (DAA) Laboratory with Problem Statements (PS), C++ implementations, and Expected Outputs.

## 📁 Repository Structure

```
├── Assignment-1/
│   ├── assignment-1.cpp
│   ├── ecommerce_dataset_+1m.csv
│   └── output.png
├── Assignment-2/
│   ├── assignment-2.cpp
│   ├── CarPrice_Assignment.csv
│   └── output2.png
├── Assignment-3/
│   ├── assignment-3.cpp
│   ├── o1.png
│   └── o2.png
├── Assignment-4/
│   ├── assignment-4.cpp
│   ├── O1.png
│   └── O2.png
├── Assignment-5/
│   ├── assignment-5.cpp
│   └── O5.png
├── Assignment-6/
│   ├── assignment6.cpp
│   └── O6.png
├── Assignment-7/
│   ├── assignment7.cpp
│   └── O7.png
├── Assignment-8/
│   ├── assignment8.cpp
│   └── O8.png
└── README.md
```

## 📚 Assignments Overview

| # | Assignment Title | Paradigm | Algorithm | Directory | Output Screenshot |
|---|------------------|----------|-----------|-----------|-------------------|
| **1** | Customer Order Sorting | Divide & Conquer | **Merge Sort** | [`Assignment-1`](./Assignment-1/) | [`output.png`](./Assignment-1/output.png) |
| **2** | Car Price Sorting | Divide & Conquer | **Quick Sort** | [`Assignment-2`](./Assignment-2/) | [`output2.png`](./Assignment-2/output2.png) |
| **3** | Emergency Relief Supply Distribution | Greedy Technique | **Fractional Knapsack** (Priority-based) | [`Assignment-3`](./Assignment-3/) | [`o1.png`](./Assignment-3/o1.png), [`o2.png`](./Assignment-3/o2.png) |
| **4** | Smart Traffic Management for Emergency Ambulance | Graph / Greedy | **Dijkstra's Algorithm** | [`Assignment-4`](./Assignment-4/) | [`O1.png`](./Assignment-4/O1.png), [`O2.png`](./Assignment-4/O2.png) |
| **5** | SwiftCargo Route Optimization | Dynamic Programming | **Multistage Graph** (Dynamic Updates) | [`Assignment-5`](./Assignment-5/) | [`O5.png`](./Assignment-5/O5.png) |
| **6** | Multi-Truck Relief Supply Allocation | Dynamic Programming | **0/1 Knapsack** (Multiple Trucks + Priority) | [`Assignment-6`](./Assignment-6/) | [`O6.png`](./Assignment-6/O6.png) |
| **7** | Exam Timetable & Room Allocation | Greedy / Backtracking | **Graph Coloring** | [`Assignment-7`](./Assignment-7/) | [`O7.png`](./Assignment-7/O7.png) |
| **8** | Traveling Salesperson Problem (TSP) | Branch & Bound | **Least Cost Branch & Bound** (Reduced Matrix) | [`Assignment-8`](./Assignment-8/) | [`O8.png`](./Assignment-8/O8.png) |

---

### Detailed Problem Statements & Complexities

#### Assignment 1: Customer Order Sorting (Merge Sort)
- **Problem Statement**: An e-commerce platform processes millions of customer orders with timestamps. Sort all orders chronologically using Merge Sort to maintain order processing sequences.
- **Dataset**: `ecommerce_dataset_+1m.csv` (`orderID`, `orderDate`).
- **Time Complexity**: $O(n \log n)$ across all cases (Best, Average, Worst).
- **Space Complexity**: $O(n)$ auxiliary space for merge sub-arrays.

#### Assignment 2: Car Price Sorting (Quick Sort)
- **Problem Statement**: Given automotive pricing data containing car attributes (fuel type, body style, horsepower, city MPG, highway MPG, price), sort cars in descending order of price to rank premium vehicles.
- **Dataset**: `CarPrice_Assignment.csv`.
- **Time Complexity**: $O(n \log n)$ average case, $O(n^2)$ worst case.
- **Space Complexity**: $O(\log n)$ recursive call stack.

#### Assignment 3: Emergency Relief Supply Distribution (Fractional Knapsack)
- **Problem Statement**: A rescue boat with a maximum weight capacity must transport emergency relief items to flood-affected areas. Items have weight, utility value, priority level (1 = High, 2 = Medium, 3 = Low), and divisibility flags (divisible vs. indivisible).
- **Strategy**: Sort items primarily by Priority (ascending), and secondarily by Value-to-Weight ratio (descending). Greedily allocate items within the boat's capacity.
- **Time Complexity**: $O(n \log n)$ for sorting.
- **Space Complexity**: $O(n)$.

#### Assignment 4: Smart Traffic Management for Emergency Ambulance (Dijkstra's Algorithm)
- **Problem Statement**: An ambulance needs to reach the nearest hospital in minimal travel time through a road network modeled as an undirected weighted graph of intersections and road segments.
- **Strategy**: Apply Dijkstra's shortest path algorithm using a min-heap priority queue from the ambulance starting intersection, then query all hospital nodes to identify the closest reachable facility.
- **Time Complexity**: $O((V + E) \log V)$ using min-priority queue.
- **Space Complexity**: $O(V + E)$ for adjacency list and distance array.

#### Assignment 5: SwiftCargo Route Optimization (Multistage Graph)
- **Problem Statement**: Optimize delivery paths across a multistage transportation network from source to destination. Additionally, support real-time traffic and weather multipliers updating edge costs dynamically.
- **Strategy**: Backward dynamic programming over topologically ordered stages. Incremental queue-based propagation to update minimum costs upon dynamic edge weight changes.
- **Time Complexity**: $O(V + E)$ initial pass; $O(V_{\text{affected}} + E_{\text{affected}})$ per update.
- **Space Complexity**: $O(V + E)$.

#### Assignment 6: Multi-Truck Relief Supply Allocation (0/1 Knapsack)
- **Problem Statement**: Distribute non-divisible relief items among multiple transport trucks, each with an individual weight limit. High-priority items receive an added utility bonus (+10).
- **Strategy**: Dynamic programming 0/1 knapsack evaluated per truck sequentially; selected items are marked as used.
- **Time Complexity**: $O(T \times n \times W)$ where $T$ = number of trucks, $n$ = items, $W$ = max capacity.
- **Space Complexity**: $O(n \times W)$ DP table per truck.

#### Assignment 7: Exam Timetable & Room Allocation (Graph Coloring)
- **Problem Statement**: Given academic courses (DAA, AIML, SPM, EAC, MDM-3) and student conflict pairs, assign exams to the minimum number of conflict-free time slots. Verify whether available classrooms satisfy student capacity.
- **Strategy**: Construct a course conflict graph, color vertices using greedy graph coloring, and validate against total seating capacity ($Rooms \times Capacity$).
- **Time Complexity**: $O(V^2 + E)$.
- **Space Complexity**: $O(V^2)$ adjacency matrix.

#### Assignment 8: Traveling Salesperson Problem (TSP - Branch and Bound)
- **Problem Statement**: Find the minimum-cost closed tour visiting each city exactly once and returning to the origin city.
- **Strategy**: Least Cost Branch and Bound using the Reduced Matrix Method. A priority queue tracks partial paths with lower bounds computed from row and column reductions to prune non-optimal search paths.
- **Time Complexity**: $O(n^2 \cdot 2^n)$ in worst case, significantly pruned in practice.
- **Space Complexity**: $O(n^2 \cdot 2^n)$ state-space tree storage.

---

## 🛠️ How to Compile & Run

Prerequisite: C++17 compatible compiler (`g++`, `clang++`, etc.)

```bash
# Example: Running Assignment 1
cd Assignment-1
g++ -std=c++17 assignment-1.cpp -o assignment-1
./assignment-1

# Example: Running Assignment 3
cd ../Assignment-3
g++ -std=c++17 assignment-3.cpp -o assignment-3
./assignment-3
```
