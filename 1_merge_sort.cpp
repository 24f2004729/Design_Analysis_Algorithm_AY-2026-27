// Assignment No. 1
// Merge Sort to arrange customer orders based on timestamps
// Handles large datasets (up to 1 million orders) efficiently: O(n log n)

#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <algorithm>
using namespace std;
using namespace std::chrono;

struct Order {
    int orderId;
    long long timestamp; // epoch time in seconds

    Order() : orderId(0), timestamp(0) {}
    Order(int id, long long ts) : orderId(id), timestamp(ts) {}
};

// Merge two sorted halves [left..mid] and [mid+1..right]
void merge(vector<Order> &orders, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<Order> leftArr(n1), rightArr(n2);

    for (int i = 0; i < n1; i++) leftArr[i] = orders[left + i];
    for (int j = 0; j < n2; j++) rightArr[j] = orders[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (leftArr[i].timestamp <= rightArr[j].timestamp) {
            orders[k++] = leftArr[i++];
        } else {
            orders[k++] = rightArr[j++];
        }
    }
    while (i < n1) orders[k++] = leftArr[i++];
    while (j < n2) orders[k++] = rightArr[j++];
}

void mergeSort(vector<Order> &orders, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(orders, left, mid);
    mergeSort(orders, mid + 1, right);
    merge(orders, left, mid, right);
}

// Simple insertion sort for comparison on small inputs (O(n^2))
void insertionSort(vector<Order> orders) {
    int n = orders.size();
    for (int i = 1; i < n; i++) {
        Order key = orders[i];
        int j = i - 1;
        while (j >= 0 && orders[j].timestamp > key.timestamp) {
            orders[j + 1] = orders[j];
            j--;
        }
        orders[j + 1] = key;
    }
}

vector<Order> generateOrders(int n) {
    vector<Order> orders(n);
    srand(42);
    for (int i = 0; i < n; i++) {
        orders[i] = Order(i + 1, rand() % 1000000);
    }
    return orders;
}

int main() {
    int n;
    cout << "Enter number of orders to generate (e.g., 100000): ";
    cin >> n;

    vector<Order> orders = generateOrders(n);
    vector<Order> ordersCopyForInsertion = orders;

    // --- Merge Sort timing ---
    auto startMerge = high_resolution_clock::now();
    mergeSort(orders, 0, n - 1);
    auto endMerge = high_resolution_clock::now();
    auto mergeDuration = duration_cast<milliseconds>(endMerge - startMerge);

    cout << "\nMerge Sort completed in " << mergeDuration.count() << " ms\n";
    cout << "First 5 sorted orders (id, timestamp):\n";
    for (int i = 0; i < min(5, n); i++)
        cout << "  Order#" << orders[i].orderId << " -> " << orders[i].timestamp << "\n";

    // --- Insertion Sort comparison (only for small n, since O(n^2) is slow) ---
    if (n <= 20000) {
        auto startIns = high_resolution_clock::now();
        insertionSort(ordersCopyForInsertion);
        auto endIns = high_resolution_clock::now();
        auto insDuration = duration_cast<milliseconds>(endIns - startIns);
        cout << "\nInsertion Sort (O(n^2)) completed in " << insDuration.count() << " ms\n";
    } else {
        cout << "\nSkipping Insertion Sort comparison for n > 20000 (too slow, O(n^2)).\n";
    }

    cout << "\n--- Complexity Analysis ---\n";
    cout << "Merge Sort:      Best/Avg/Worst = O(n log n), Space = O(n) (auxiliary arrays)\n";
    cout << "Insertion Sort:  Best = O(n), Avg/Worst = O(n^2), Space = O(1)\n";
    cout << "Quick Sort:      Avg = O(n log n), Worst = O(n^2), Space = O(log n)\n";
    cout << "Merge Sort is preferred here because it guarantees O(n log n) even in the\n";
    cout << "worst case and is stable, which matters when orders share the same timestamp.\n";

    return 0;
}
