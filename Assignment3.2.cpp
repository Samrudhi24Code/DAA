/*Implement Subset Sum Problem.
Statement Given a set of non-negative integers and a
value sum, the task is to check if there is a subset of the
given set whose sum is equal to the given sum.
Input: set[] = {3, 34, 4, 12, 5, 2}, sum = 9
Output: True
Input: set[] = {3, 34, 4, 12, 5, 2}, sum = 30
Output: False*/

#include <iostream>
#include <vector>
using namespace std;

// Function to check if there's a subset with the given sum
bool isSubsetSum(const vector<int>& set, int sum) {
    int n = set.size();
    
    // Create a DP table with (n+1) rows and (sum+1) columns
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
    
    // Base case: A sum of 0 is always possible (by selecting no elements)
    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }

    // Fill the DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            // If the current element is greater than the sum, exclude it
            if (set[i-1] > j) {
                dp[i][j] = dp[i-1][j];
            } else {
                // Otherwise, include or exclude the current element
                dp[i][j] = dp[i-1][j] || dp[i-1][j - set[i-1]];
            }
        }
    }

    // The result is in dp[n][sum]
    return dp[n][sum];
}

int main() {
    vector<int> set1 = {3, 34, 4, 12, 5, 2};
    int sum1 = 9;
    if (isSubsetSum(set1, sum1)) {
        cout << "Subset with sum " << sum1 << " exists." << endl;  // Output: True
    } else {
        cout << "Subset with sum " << sum1 << " does not exist." << endl;
    }

    vector<int> set2 = {3, 34, 4, 12, 5, 2};
    int sum2 = 30;
    if (isSubsetSum(set2, sum2)) {
        cout << "Subset with sum " << sum2 << " exists." << endl;
    } else {
        cout << "Subset with sum " << sum2 << " does not exist." << endl;  // Output: False
    }

    return 0;
}
Time Complexity: 
𝑂
(
𝑁
×
sum
)
O(N×sum)
We have to fill a DP table of size 
𝑁
×
sum
N×sum, where 
𝑁
N is the number of elements in the set, and sum is the target sum.
