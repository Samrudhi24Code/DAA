Implement program Count all possible Paths
between two Vertices.
Statement Count the total number of ways or paths
that exist between two vertices in a directed graph.
These paths don’t contain a cycle, the simple enough
reason is that a cycle contains an infinite number of
paths and hence they create a problem.
Input: Count paths between A and E
Output: Total paths between A and E are 4
Input: Count paths between A and C
Output: Total paths between A and C are 2




#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// Function to perform backtracking and count all possible paths
void countPathsUtil(int current, int destination, const vector<vector<int>>& adjList, unordered_set<int>& visited, int& pathCount) {
    // If the current vertex is the destination, we found a valid path
    if (current == destination) {
        pathCount++;
        return;
    }
    
    // Mark the current vertex as visited
    visited.insert(current);
    
    // Recurse for all adjacent vertices
    for (int neighbor : adjList[current]) {
        if (visited.find(neighbor) == visited.end()) {
            // Explore the neighbor if it's not visited
            countPathsUtil(neighbor, destination, adjList, visited, pathCount);
        }
    }
    
    // Backtrack: remove the current vertex from the visited set
    visited.erase(current);
}

// Main function to count all paths from source to destination
int countPaths(int source, int destination, const vector<vector<int>>& adjList) {
    unordered_set<int> visited;  // Set to track visited nodes in the current path
    int pathCount = 0;
    countPathsUtil(source, destination, adjList, visited, pathCount);
    return pathCount;
}

int main() {
    // Example graph represented as an adjacency list
    vector<vector<int>> adjList(6);
    adjList[0] = {1, 2}; // A -> B, A -> C
    adjList[1] = {3};    // B -> D
    adjList[2] = {3};    // C -> D
    adjList[3] = {4};    // D -> E
    adjList[4] = {};     // E has no outgoing edges

    // Example 1: Count paths between A (0) and E (4)
    cout << "Total paths between A and E: " << countPaths(0, 4, adjList) << endl;  // Output: 4
    
    // Example 2: Count paths between A (0) and C (2)
    cout << "Total paths between A and C: " << countPaths(0, 2, adjList) << endl;  // Output: 2

    return 0;
}











Time Complexity: 
𝑂
(
2
𝑁
)
O(2 
N
 ) in the worst case, due to the backtracking approach exploring all paths in the graph.
