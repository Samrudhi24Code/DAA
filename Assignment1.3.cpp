#include <iostream>
using namespace std;

// Function to calculate the number of trailing zeroes in the factorial of a number x
int trailingZeroes(int x) {
    int count = 0;

    // Trailing zeroes are contributed by factors of 5 in x!
    while (x > 0) {
        count += x / 5;  // Count how many multiples of 5 are present
        x /= 5;          // Move to higher powers of 5 (like 25, 125, etc.)
    }
    return count; // Return total count of trailing zeroes
}

// Function to find the smallest number whose factorial has at least n trailing zeroes
int findSmallestNumber(int n) {
    if (n == 0) return 0; // Special case: If n is 0, the answer is 0 because 0! = 1 has no trailing zeroes.

    // Binary search to find the smallest number
    int low = 0;               // Minimum possible value
    int high = 5 * n;          // Upper bound for the search; 5*n is a safe estimate
    int result = -1;           // Variable to store the final answer

    // Binary search loop
    while (low <= high) {
        int mid = low + (high - low) / 2; // Calculate the midpoint of the range

        // Count the number of trailing zeroes in mid!
        int zeroes = trailingZeroes(mid);

        // If the trailing zeroes in mid! is greater than or equal to n
        if (zeroes >= n) {
            result = mid;      // This might be the answer
            high = mid - 1;    // Try to find a smaller number in the left half
        } else {
            low = mid + 1;     // Otherwise, search in the right half
        }
    }

    return result; // Return the smallest number found
}

int main() {
    // Input: The number of trailing zeroes required
    int n;
    cout << "Enter the number of trailing zeroes: ";
    cin >> n;

    // Find and output the smallest number whose factorial has at least n trailing zeroes
    int result = findSmallestNumber(n);
    cout << "The smallest number whose factorial has at least " << n << " trailing zeroes is: " << result << endl;

    return 0;
}
