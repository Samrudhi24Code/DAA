//Statement: Given an array of 1s and 0s which has all 
//1s first followed by all 0s? Find the number of 0s. 
//Count the number of zeroes in the given array.



#include <iostream>
#include <vector>
using namespace std;

// Recursive function to find the first occurrence of 0
int findFirstZero(const vector<int>& arr, int low, int high) {
    if (low > high) return -1; // Base case: No zero found

    int mid = low + (high - low) / 2;

    // Check if mid is the first occurrence of 0
    if ((mid == 0 || arr[mid - 1] == 1) && arr[mid] == 0) {
        return mid;
    }

    // If the mid element is 1, look in the right half
    if (arr[mid] == 1) {
        return findFirstZero(arr, mid + 1, high);
    }

    // If mid is 0 but not the first one, search in the left half
    return findFirstZero(arr, low, mid - 1);
}

// Function to count the number of zeroes
int countZeroes(const vector<int>& arr) {
    int n = arr.size();

    // Find the first occurrence of 0
    int firstZeroIndex = findFirstZero(arr, 0, n - 1);

    // If no zero found, return 0
    if (firstZeroIndex == -1) return 0;

    // Count of zeroes = Total elements - Index of first zero
    return n - firstZeroIndex;
}

int main() {
    vector<int> arr1 = {1, 1, 1, 1, 0, 0};
    vector<int> arr2 = {1, 0, 0, 0, 0};

    cout << "Number of zeroes in arr1: " << countZeroes(arr1) << endl;
    cout << "Number of zeroes in arr2: " << countZeroes(arr2) << endl;

    return 0;
}//The recurrence relation is 
𝑇
(
𝑛
)
=
𝑇
(
𝑛
/
2
)
+
𝑂
(
1
)
T(n)=T(n/2)+O(1), where 
𝑂
(
1
)
O(1) is the comparison.
Solving this gives 
𝑂
(
log
⁡
𝑛
)
O(logn).
