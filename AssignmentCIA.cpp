#TSP
#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

// Define the number of nodes
const int N = 4;
const int INF = INT_MAX;

// Adjacency matrix for the graph
int graph[N][N] = {
    {0, 20, 10, 12},
    {20, 0, 15, 11},
    {10, 15, 0, 17},
    {12, 11, 17, 0}
};

// Function to solve TSP using Dynamic Programming
int tsp(int mask, int pos, vector<vector<int>>& dp) {
    // Base case: All cities have been visited
    if (mask == (1 << N) - 1) {
        return graph[pos][0]; // Return cost to return to starting city
    }

    // If the result is already computed, return it
    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    int result = INF;

    // Try to visit all unvisited cities
    for (int city = 0; city < N; city++) {
        if (!(mask & (1 << city))) { // If the city is not visited
            int newResult = graph[pos][city] + tsp(mask | (1 << city), city, dp);
            result = min(result, newResult);
        }
    }

    // Store and return the result
    dp[mask][pos] = result;
    return result;
}

int main() {
    // DP table: dp[mask][pos] stores the minimum cost to visit all cities in "mask" ending at "pos"
    vector<vector<int>> dp(1 << N, vector<int>(N, -1));

    // Solve the TSP starting from city 0
    int result = tsp(1, 0, dp);

    // Output the result
    cout << "The minimum cost to visit all cities is: " << result << endl;

    return 0;
}
