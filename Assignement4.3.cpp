Implement program to print all subsets of a given
Set or Array
Statement Given a set of positive integers, find all its
subsets.
Input: array = {1, 2, 3}
Output: // this space denotes null element.
1 1 2 1 2 3 1 3 2
2 3 3
Input: 1 2
Output: 1 2 1 2




#include <iostream>
#include <vector>
using namespace std;

// Function to print the subsets using backtracking
void findSubsets(vector<int>& arr, vector<int>& currentSubset, int index) {
    // Base case: If we've considered all elements, print the current subset
    if (index == arr.size()) {
        for (int i = 0; i < currentSubset.size(); i++) {
            cout << currentSubset[i] << " ";
        }
        cout << endl;
        return;
    }
    
    // Exclude the current element and move to the next
    findSubsets(arr, currentSubset, index + 1);
    
    // Include the current element in the subset and move to the next
    currentSubset.push_back(arr[index]);
    findSubsets(arr, currentSubset, index + 1);
    
    // Backtrack: remove the last element to explore other possibilities
    currentSubset.pop_back();
}

// Driver code
int main() {
    vector<int> arr = {1, 2, 3}; // Input array
    vector<int> currentSubset; // Current subset
    findSubsets(arr, currentSubset, 0); // Start the backtracking process
    
    return 0;
}
