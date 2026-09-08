# Assignment 1: Merge Sort for Customer Order Processing

## Problem
Design and implement a sorting algorithm using Merge Sort to efficiently
arrange customer orders based on their timestamps. The solution should
handle a large dataset (up to 1 million orders) with minimal computational
overhead. Additionally, analyze the time complexity and compare it with
traditional sorting techniques.

## Files
- `merge_sort.cpp` — Merge Sort implementation with a built-in comparison
  against Insertion Sort, and timing benchmarks.

## How to Run
```bash
g++ -std=c++17 -O2 -o merge_sort merge_sort.cpp
./merge_sort
```
You'll be prompted for the number of orders to generate (try `1000000` to
test the large-dataset case).

## Complexity Summary
| Algorithm       | Best      | Average   | Worst     | Space   |
|------------------|-----------|-----------|-----------|---------|
| Merge Sort       | O(n log n)| O(n log n)| O(n log n)| O(n)    |
| Insertion Sort   | O(n)      | O(n^2)    | O(n^2)    | O(1)    |
| Quick Sort       | O(n log n)| O(n log n)| O(n^2)    | O(log n)|

Merge Sort is chosen here because it guarantees O(n log n) performance even
in the worst case and is stable — important when multiple orders share the
same timestamp and their relative order should be preserved.

## Future Additions (placeholder)
- Benchmark results / graphs for varying dataset sizes
- Report / write-up (PDF or DOCX)
- Test datasets (CSV)
