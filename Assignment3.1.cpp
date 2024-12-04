Implement Coin Change problem.
Statement Given an integer array of coins[ ] of
size N representing different types of currency and an
integer sum, The task is to find the number of ways to
make sum by using different combinations
from coins[].
Note: Assume that you have an infinite supply of each
type of coin.
Input: sum = 4, coins[] = {1,2,3}, Output: 4
Input: sum = 10, coins[] = {2, 5, 3, 6} Output:



#include <iostream>
#include <vector>
using namespace std;

// Function to find the number of ways to make the sum using the given coins
int coinChangeWays(int sum, vector<int>& coins) {
    // Initialize a dp array of size sum + 1
    vector<int> dp(sum + 1, 0);
    
    // There is one way to make sum 0 (by choosing no coins)
    dp[0] = 1;
    
    // Traverse through each coin
    for (int coin : coins) {
        // Update the dp array for all sums that can be formed by adding the current coin
        for (int i = coin; i <= sum; i++) {
            dp[i] += dp[i - coin];
        }
    }
    
    // The last element in dp will have the number of ways to make the sum
    return dp[sum];
}

// Driver code
int main() {
    vector<int> coins1 = {1, 2, 3};
    int sum1 = 4;
    cout << "Number of ways to make sum " << sum1 << " with coins {1, 2, 3}: " << coinChangeWays(sum1, coins1) << endl;  // Output: 4

    vector<int> coins2 = {2, 5, 3, 6};
    int sum2 = 10;
    cout << "Number of ways to make sum " << sum2 << " with coins {2, 5, 3, 6}: " << coinChangeWays(sum2, coins2) << endl;  // Output: 5

    return 0;
}



//Time Complexity: 
𝑂
(
𝑁
×
sum
)
O(N×sum), where:
𝑁
N is the number of coins.
sum is the target sum to be achieved.
