#include <iostream>

using namespace std;

// Function to calculate the maximum profit
int maxProfit(int prices[], int n) {
    int profit = 0;
    
    // Loop through the prices starting from the second day
    for (int i = 1; i < n; i++) {
        // If the current day's price is higher than the previous day's price
        if (prices[i] > prices[i - 1]) {
            // Add the profit (current day's price - previous day's price) to total profit
            profit += prices[i] - prices[i - 1];
        }
    }
    
    // Return the total profit
    return profit;
}

int main() {
    // Test case 1
    int arr1[] = {2, 3, 5};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);  // Calculate the size of the array
    cout << "Max Profit for arr1: " << maxProfit(arr1, n1) << endl;  // Output: 3

    // Test case 2
    int arr2[] = {8, 5, 1};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);  // Calculate the size of the array
    cout << "Max Profit for arr2: " << maxProfit(arr2, n2) << endl;  // Output: 0

    return 0;
}
