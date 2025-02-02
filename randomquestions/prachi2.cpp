#include <iostream>
#include <vector>
#include <limits>

using namespace std;

// Function to calculate the minimum strokes needed
int minStrokes(vector<int>& heights, int start, int end, int currentHeight) {
    // Base case: if no Plancks left
    if (start > end) return 0;
    // If there's only one Planck
    if (start == end) return heights[start] > currentHeight;

    // Find the minimum height in the range
    int minHeight = numeric_limits<int>::max();
    int minIndex = 0;

    for (int k = start; k <= end; k++) {
        if (heights[k] < minHeight) {
            minHeight = heights[k];
            minIndex = k;
        }
    }

    // Calculate the number of strokes
    return min(end - start + 1, 
               minStrokes(heights, start, minIndex - 1, minHeight) +
               minStrokes(heights, minIndex + 1, end, minHeight) +
               minHeight - currentHeight);
}

// Main function to read input and call the solve function
void solve() {
    int n; 
    cin >> n; // Number of Plancks
    vector<int> heights(n);
    
    for (int i = 0; i < n; i++) {
        cin >> heights[i]; // Heights of the Plancks
    }

    cout << minStrokes(heights, 0, n - 1, 0) << endl;
}

// Entry point of the program
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}