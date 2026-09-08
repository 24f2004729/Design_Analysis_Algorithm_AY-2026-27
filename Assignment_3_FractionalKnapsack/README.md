# Assignment 3: Fractional Knapsack for Emergency Relief Distribution

## Problem
A limited-capacity relief boat (max weight W) must transport food, medicine,
and water from a relief center to flood-affected villages. Each item has a
weight and a utility value; some items (food, water) are divisible, others
(medical kits) must be taken whole. Maximize total utility value transported
within the weight limit.

## Files
- `fractional_knapsack.cpp` — Greedy fractional knapsack solution. Sorts
  items by value/weight ratio and fills remaining capacity with the
  highest-density option, supporting both divisible and indivisible items.

## How to Run
```bash
g++ -std=c++17 -O2 -o fractional_knapsack fractional_knapsack.cpp
./fractional_knapsack
```
You'll be prompted for the boat's capacity and each item's name, weight,
value, and whether it's divisible.

## Complexity Summary
| Step                        | Complexity |
|------------------------------|------------|
| Sort by value/weight ratio   | O(n log n) |
| Greedy selection pass        | O(n)       |
| **Overall**                  | **O(n log n)**, Space O(n) |

The greedy approach is provably optimal for the *fractional* knapsack
(unlike 0/1 knapsack), since divisible items let capacity always be filled
with the highest-value-density option available.

## Future Additions (placeholder)
- Report / write-up
- Sample relief-item datasets for different flood scenarios
