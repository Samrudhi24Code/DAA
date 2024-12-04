Implement program to find all distinct subsets of a
given set using Bit Masking Approach.
Statement Given an array of integers arr[], The task is
to find all its subsets. The subset cannot contain duplicate elements, so any repeated subset should be
considered only once in the output.
Input: S = {1, 2, 2} Output: {}, {1}, {2}, {1, 2}, {2,
2}, {1, 2,2}
Input: S = {1, 2} Output: {}, {1}, {2}, {1, 2}


    #include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Helper function to generate subsets using backtracking
void backtrack(vector<int>& arr, int index, vector<int>& current, vector<vector<int>>& result) {
    // Add current subset to result
    result.push_back(current);

    // Iterate through the remaining elements
    for (int i = index; i < arr.size(); ++i) {
        // Skip duplicates
        if (i > index && arr[i] == arr[i - 1]) {
            continue;
        }

        // Include arr[i] in the current subset
        current.push_back(arr[i]);

        // Recurse for the next index
        backtrack(arr, i + 1, current, result);

        // Exclude arr[i] from the current subset (backtrack)
        current.pop_back();
    }
}

// Function to find all distinct subsets
vector<vector<int>> findSubsets(vector<int>& arr) {
    vector<vector<int>> result;
    vector<int> current;
    
    // Sort the array to handle duplicates efficiently
    sort(arr.begin(), arr.end());

    // Call the backtracking helper function
    backtrack(arr, 0, current, result);
    
    return result;
}

int main() {
    vector<int> arr1 = {1, 2, 2};
    vector<int> arr2 = {1, 2};

    vector<vector<int>> result1 = findSubsets(arr1);
    vector<vector<int>> result2 = findSubsets(arr2);

    // Print the subsets for arr1
    cout << "Subsets of {1, 2, 2}:" << endl;
    for (const auto& subset : result1) {
        cout << "{ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "}" << endl;
    }

    // Print the subsets for arr2
    cout << "Subsets of {1, 2}:" << endl;
    for (const auto& subset : result2) {
        cout << "{ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "}" << endl;
    }

    return 0;
}

























Time Complexity:
Sorting: 
𝑂
(
𝑁
log
⁡
𝑁
)
O(NlogN), where 
𝑁
N is the size of the array.
Backtracking: We generate all subsets, and for a set of size 
𝑁
N, the number of subsets is 
2
𝑁
2 
N
 . For each subset, we add it to the result, which takes 
𝑂
(
𝑁
)
O(N) for each subset.
Hence, the total time complexity is 
𝑂
(
𝑁
log
⁡
𝑁
+
2
𝑁
)
O(NlogN+2 
N
 ).
