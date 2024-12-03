#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// Algorithm to find the maximum number of shops that can be visited by K persons
int maxShopsVisited(vector<int>& start, vector<int>& end, int K) {
    int n = start.size();  // Number of shops

    // Step 1: Create a vector of pairs (end time, start time) for sorting
    vector<pair<int, int>> activities;
    for (int i = 0; i < n; ++i) {
        activities.push_back({end[i], start[i]});
    }

    // Step 2: Sort activities by their end times (greedy approach)
    sort(activities.begin(), activities.end());

    // Step 3: Initialize a priority queue (min-heap) to keep track of the end times of K persons
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Initialize the heap with 0 for K persons (all are free at time 0)
    for (int i = 0; i < K; ++i) {
        minHeap.push(0);  // Initially, all persons are free at time 0
    }

    // Step 4: Iterate through each shop (activity)
    int count = 0;  // Counter for maximum activities
    for (const auto& activity : activities) {
        int shopStart = activity.second;  // Start time of the shop
        int shopEnd = activity.first;    // End time of the shop

        // Step 5: Get the earliest available person (person with the earliest end time)
        int earliestFree = minHeap.top();

        // Step 6: If the person can attend this activity (i.e., their free time is <= shop start time)
        if (earliestFree <= shopStart) {
            minHeap.pop();              // Remove the person from the heap
            minHeap.push(shopEnd);      // Update their end time (assign the shop to this person)
            count++;                    // Increment the count of activities visited
        }
    }

    // Step 7: Return the maximum number of activities that can be visited
    return count;
}

int main() {
    // Input: Start and End times of shops, and the number of persons
    vector<int> S = {1, 8, 3, 2, 6};
    vector<int> E = {5, 10, 6, 5, 9};
    int K = 2;

    // Calculate the maximum number of shops visited
    int result = maxShopsVisited(S, E, K);

    // Output the result
    cout << "The maximum number of shops that can be visited is: " << result << endl;

    return 0;
}
