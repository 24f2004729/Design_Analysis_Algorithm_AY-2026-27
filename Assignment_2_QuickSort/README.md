# Assignment 2: Quick Sort for Movie Recommendation Optimization

## Problem
StreamFlix offers personalized recommendations by sorting movies based on
user preferences (IMDB rating, release year, or watch-time popularity).
During peak hours, sorting large datasets slows the system down. Implement
Quick Sort to efficiently sort movies by various user-selected parameters
while handling large datasets with fast response times.

## Files
- `quick_sort.cpp` — Quick Sort implementation supporting three sort keys
  (rating, year, watch time), using median-of-three pivot selection to avoid
  worst-case behavior on already-sorted data.

## How to Run
```bash
g++ -std=c++17 -O2 -o quick_sort quick_sort.cpp
./quick_sort
```
You'll be prompted for the number of movies to generate.

## Complexity Summary
| Case     | Complexity   |
|----------|--------------|
| Average  | O(n log n)   |
| Worst    | O(n^2) (mitigated via median-of-three pivot) |
| Space    | O(log n) recursion stack (in-place) |

In-place partitioning keeps memory overhead low, which matters under
peak-hour load with large movie catalogs.

## Future Additions (placeholder)
- Benchmark comparisons across the three sort keys at scale
- Report / write-up
- Sample movie dataset (CSV/JSON)
