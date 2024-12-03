#include <iostream>
#include <vector>
#include <set>
#include <algorithm> // For sort

using namespace std;

// Function to find all distinct subsets using bit masking
vector<vector<int>> findDistinctSubsets(vector<int>& nums) {
    int n = nums.size();
    set<vector<int>> subsetSet; // To store unique subsets
    
    // Sort the array to ensure consistent ordering
    sort(nums.begin(), nums.end());

    // Iterate over all possible subsets (2^n)
    for (int mask = 0; mask < (1 << n); ++mask) {
        vector<int> subset;

        // Generate a subset for the current bitmask
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) { // If the i-th bit is set
                subset.push_back(nums[i]);
            }
        }

        // Add the subset to the set (avoids duplicates)
        subsetSet.insert(subset);
    }

    // Convert set to vector for the final result
    vector<vector<int>> result(subsetSet.begin(), subsetSet.end());
    return result;
}

int main() {
    // Example input
    vector<int> nums1 = {1, 2, 2};
    vector<int> nums2 = {1, 2};

    // Find and print subsets for the first input
    cout << "Subsets for {1, 2, 2}:\n";
    vector<vector<int>> subsets1 = findDistinctSubsets(nums1);
    for (const auto& subset : subsets1) {
        cout << "{ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "}\n";
    }

    // Find and print subsets for the second input
    cout << "\nSubsets for {1, 2}:\n";
    vector<vector<int>> subsets2 = findDistinctSubsets(nums2);
    for (const auto& subset : subsets2) {
        cout << "{ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "}\n";
    }

    return 0;
}
