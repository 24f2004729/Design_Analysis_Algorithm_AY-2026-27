// Assignment No. 2
// StreamFlix Movie Recommendation System Optimization
// Quick Sort movies by IMDB rating, release year, or watch-time popularity

#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <cstdlib>
#include <algorithm>
using namespace std;
using namespace std::chrono;

struct Movie {
    string title;
    double imdbRating;
    int releaseYear;
    long long watchTimeMinutes; // popularity metric

    Movie() : title(""), imdbRating(0), releaseYear(0), watchTimeMinutes(0) {}
    Movie(string t, double r, int y, long long w)
        : title(t), imdbRating(r), releaseYear(y), watchTimeMinutes(w) {}
};

enum SortKey { BY_RATING, BY_YEAR, BY_WATCHTIME };

// Comparator based on the chosen key (descending = "best first")
bool isGreater(const Movie &a, const Movie &b, SortKey key) {
    switch (key) {
        case BY_RATING:    return a.imdbRating > b.imdbRating;
        case BY_YEAR:      return a.releaseYear > b.releaseYear;
        case BY_WATCHTIME: return a.watchTimeMinutes > b.watchTimeMinutes;
    }
    return false;
}

int partition(vector<Movie> &movies, int low, int high, SortKey key) {
    // Median-of-three pivot selection to avoid worst-case O(n^2) on sorted data
    int mid = low + (high - low) / 2;
    if (isGreater(movies[mid], movies[low], key)) swap(movies[low], movies[mid]);
    if (isGreater(movies[high], movies[low], key)) swap(movies[low], movies[high]);
    if (isGreater(movies[mid], movies[high], key)) swap(movies[mid], movies[high]);
    Movie pivot = movies[high];

    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (isGreater(movies[j], pivot, key)) {
            i++;
            swap(movies[i], movies[j]);
        }
    }
    swap(movies[i + 1], movies[high]);
    return i + 1;
}

void quickSort(vector<Movie> &movies, int low, int high, SortKey key) {
    if (low < high) {
        int pi = partition(movies, low, high, key);
        quickSort(movies, low, pi - 1, key);
        quickSort(movies, pi + 1, high, key);
    }
}

vector<Movie> generateMovies(int n) {
    vector<Movie> movies(n);
    srand(7);
    for (int i = 0; i < n; i++) {
        double rating = 1.0 + (rand() % 90) / 10.0;      // 1.0 - 9.9
        int year = 1970 + rand() % 55;                    // 1970 - 2024
        long long watchTime = rand() % 5000000;            // popularity proxy
        movies[i] = Movie("Movie_" + to_string(i + 1), rating, year, watchTime);
    }
    return movies;
}

void printTop(const vector<Movie> &movies, int count, const string &label) {
    cout << "\nTop " << count << " movies by " << label << ":\n";
    for (int i = 0; i < min(count, (int)movies.size()); i++) {
        cout << "  " << movies[i].title
             << " | rating=" << movies[i].imdbRating
             << " | year=" << movies[i].releaseYear
             << " | watchTime=" << movies[i].watchTimeMinutes << "\n";
    }
}

int main() {
    int n;
    cout << "Enter number of movies to generate (e.g., 100000): ";
    cin >> n;

    vector<Movie> byRating = generateMovies(n);
    vector<Movie> byYear = byRating;
    vector<Movie> byWatch = byRating;

    auto t1 = high_resolution_clock::now();
    quickSort(byRating, 0, n - 1, BY_RATING);
    auto t2 = high_resolution_clock::now();
    quickSort(byYear, 0, n - 1, BY_YEAR);
    auto t3 = high_resolution_clock::now();
    quickSort(byWatch, 0, n - 1, BY_WATCHTIME);
    auto t4 = high_resolution_clock::now();

    cout << "\nSort by rating took:    " << duration_cast<milliseconds>(t2 - t1).count() << " ms\n";
    cout << "Sort by year took:      " << duration_cast<milliseconds>(t3 - t2).count() << " ms\n";
    cout << "Sort by watch time took:" << duration_cast<milliseconds>(t4 - t3).count() << " ms\n";

    printTop(byRating, 5, "IMDB rating");
    printTop(byYear, 5, "release year");
    printTop(byWatch, 5, "watch time popularity");

    cout << "\n--- Complexity Analysis ---\n";
    cout << "Quick Sort: Average = O(n log n), Worst = O(n^2) (mitigated here via\n";
    cout << "median-of-three pivot selection), Space = O(log n) for recursion stack.\n";
    cout << "In-place partitioning keeps memory overhead low, which matters under\n";
    cout << "peak-hour load with large movie catalogs.\n";

    return 0;
}
