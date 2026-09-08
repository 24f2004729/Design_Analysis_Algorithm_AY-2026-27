// Assignment No. 3
// Emergency Relief Supply Distribution using Fractional Knapsack
// Maximizes total utility value under boat weight capacity W

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

struct ReliefItem {
    string name;
    double weight;   // kg
    double value;    // utility value
    bool divisible;  // can be taken as a fraction?

    double ratio() const { return value / weight; }
};

struct Selection {
    string name;
    double takenWeight;
    double takenValue;
};

// Greedy fractional knapsack: sort by value/weight ratio, take highest first.
// Items marked non-divisible are only taken whole (if they still fit).
double fractionalKnapsack(vector<ReliefItem> items, double capacity, vector<Selection> &result) {
    sort(items.begin(), items.end(), [](const ReliefItem &a, const ReliefItem &b) {
        return a.ratio() > b.ratio();
    });

    double totalValue = 0.0;
    double remaining = capacity;

    for (const auto &item : items) {
        if (remaining <= 0) break;

        if (item.weight <= remaining) {
            // Take the whole item
            remaining -= item.weight;
            totalValue += item.value;
            result.push_back({item.name, item.weight, item.value});
        } else if (item.divisible) {
            // Take a fraction of this divisible item
            double fraction = remaining / item.weight;
            double takenValue = item.value * fraction;
            totalValue += takenValue;
            result.push_back({item.name, remaining, takenValue});
            remaining = 0;
        }
        // If not divisible and doesn't fully fit, skip it entirely.
    }

    return totalValue;
}

int main() {
    double capacity;
    int n;

    cout << "Enter boat capacity W (kg): ";
    cin >> capacity;

    cout << "Enter number of relief item types: ";
    cin >> n;

    vector<ReliefItem> items(n);
    for (int i = 0; i < n; i++) {
        cout << "\nItem #" << i + 1 << "\n";
        cout << "  Name: ";
        cin >> items[i].name;
        cout << "  Weight (kg): ";
        cin >> items[i].weight;
        cout << "  Utility value: ";
        cin >> items[i].value;
        cout << "  Divisible (1 = yes e.g. food/water, 0 = no e.g. medical kit): ";
        cin >> items[i].divisible;
    }

    vector<Selection> result;
    double maxValue = fractionalKnapsack(items, capacity, result);

    cout << fixed << setprecision(2);
    cout << "\n--- Optimal Relief Loading Plan ---\n";
    double totalWeight = 0;
    for (const auto &s : result) {
        cout << "  " << s.name << ": weight=" << s.takenWeight
             << " kg, value contributed=" << s.takenValue << "\n";
        totalWeight += s.takenWeight;
    }
    cout << "\nTotal weight loaded: " << totalWeight << " / " << capacity << " kg\n";
    cout << "Total utility value maximized: " << maxValue << "\n";

    cout << "\n--- Complexity Analysis ---\n";
    cout << "Sorting items by value/weight ratio: O(n log n)\n";
    cout << "Greedy selection pass: O(n)\n";
    cout << "Overall: O(n log n), Space = O(n)\n";
    cout << "The greedy approach is provably optimal for the fractional knapsack\n";
    cout << "(unlike 0/1 knapsack) because divisible items let us always fill\n";
    cout << "remaining capacity with the highest-value-density option available.\n";

    return 0;
}
