Implement a problem of maximize Profit by trading
stocks based on given rate per day.Statement: Given an array arr[] of N positive integers
which denotes the cost of selling and buying a stock on
each of the N days. The task is to find the maximum
profit that can be earned by buying a stock on or selling
all previously bought stocks on a particular day.
Input: arr[] = {2, 3, 5} Output: 5
Input: arr[] = {8, 5, 1} Output: 0







#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Function to calculate maximum profit
int maximizeProfit(vector<int>& arr) {
    int minPrice = INT_MAX; // Minimum price seen so far
    int maxProfit = 0;      // Maximum profit so far

    // Traverse the array
    for (int price : arr) {
        // Update the minimum price
        if (price < minPrice) {
            minPrice = price;
        }
        // Calculate current profit and update maximum profit
        int currentProfit = price - minPrice;
        if (currentProfit > maxProfit) {
            maxProfit = currentProfit;
        }
    }
    return maxProfit;
}

// Driver code
int main() {
    vector<int> arr1 = {2, 3, 5};
    vector<int> arr2 = {8, 5, 1};

    cout << "Maximum Profit for arr1: " << maximizeProfit(arr1) << endl; // Output: 5
    cout << "Maximum Profit for arr2: " << maximizeProfit(arr2) << endl; // Output: 0

    return 0;
}///O(N)
