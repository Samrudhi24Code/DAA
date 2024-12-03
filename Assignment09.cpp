#include <iostream>
#include <vector>
using namespace std;

// Function to perform DFS and count paths
void countPathsUtil(int src, int dest, vector<vector<int>>& adj, vector<bool>& visited, int& pathCount) {
    // If the source is the destination, a path is found
    if (src == dest) {
        pathCount++;
        return;
    }

    // Mark the current vertex as visited
    visited[src] = true;

    // Explore all neighbors of the current vertex
    for (int neighbor : adj[src]) {
        if (!visited[neighbor]) {
            countPathsUtil(neighbor, dest, adj, visited, pathCount);
        }
    }

    // Backtrack: Mark the current vertex as unvisited
    visited[src] = false;
}

// Function to count all paths between two vertices
int countPaths(int V, vector<pair<int, int>>& edges, int src, int dest) {
    // Create an adjacency list
    vector<vector<int>> adj(V);
    for (auto edge : edges) {
        adj[edge.first].push_back(edge.second);
    }

    // Initialize visited array and path count
    vector<bool> visited(V, false);
    int pathCount = 0;

    // Start DFS from the source vertex
    countPathsUtil(src, dest, adj, visited, pathCount);

    return pathCount;
}

int main() {
    // Dynamic input from the user
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;

    cout << "Enter the number of edges: ";
    cin >> E;

    vector<pair<int, int>> edges(E);

    cout << "Enter the edges (u v) where u is the source and v is the destination vertex:" << endl;
    for (int i = 0; i < E; i++) {
        cin >> edges[i].first >> edges[i].second;
    }

    int src, dest;
    cout << "Enter the source vertex: ";
    cin >> src;
    cout << "Enter the destination vertex: ";
    cin >> dest;

    cout << "Total paths from " << src << " to " << dest << ": "
         << countPaths(V, edges, src, dest) << endl;

    return 0;
}
