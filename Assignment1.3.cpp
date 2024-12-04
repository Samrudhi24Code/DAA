//Implement a problem of smallest number with at
//least n trailing zeroes in factorial.
//Statement: Given a number n. The task is to find the
//smallest number whose factorial contains at least n
//trailing zeroes.
//Input : n = 1 Output : 5
//Input : n = 6 Output : 25


#include <iostream>
using namespace std;

// Function to calculate trailing zeroes in factorial of x
int trailingZeroes(int x) {
    int count = 0;
    while (x > 0) {
        count += x / 5; // Count factors of 5
        x /= 5;
    }
    return count;
}

// Function to find the smallest number with at least n trailing zeroes
int findSmallestNumber(int n) {
    if (n == 0) return 0; // Special case

    int low = 0, high = n * 5, ans = -1;

    // Binary search to find the smallest number
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int zeroes = trailingZeroes(mid);

        if (zeroes >= n) {
            ans = mid; // Update answer
            high = mid - 1; // Search in the left half for a smaller number
        } else {
            low = mid + 1; // Search in the right half
        }
    }
    return ans;
}

int main() {
    int n1 = 1, n2 = 6;
    cout << "Smallest number with at least " << n1 << " trailing zeroes: " << findSmallestNumber(n1) << endl;
    cout << "Smallest number with at least " << n2 << " trailing zeroes: " << findSmallestNumber(n2) << endl;

    return 0;
}
