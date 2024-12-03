#include <iostream>
#include <vector>
using namespace std;

// Function to generate all subsets using backtracking
void generateSubsets(vector<int>& arr, vector<int>& subset, int index) {
    // Print the current subset
    for (int num : subset) {
        cout << num << " ";
    }
    cout << endl;

    // Explore subsets including the next elements
    for (int i = index; i < arr.size(); i++) {
        subset.push_back(arr[i]); // Include current element
        generateSubsets(arr, subset, i + 1); // Recur for remaining elements
        subset.pop_back(); // Backtrack and remove current element
    }
}

// Main function
int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n; // User input for the number of elements

    vector<int> arr(n); // Declare vector of size n

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; // User input for array elements
    }

    vector<int> subset; // Vector to store subsets

    cout << "All subsets are:" << endl;
    generateSubsets(arr, subset, 0); // Generate subsets starting from index 0

    return 0;
}
