//Implement a problem of move all zeroes to end of 
//array.
//Statement: Given an array of random numbers, Push all the zero’s 
//of a given array to the end of the array. For example, if the given 
//arrays is {1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0}, it should be changed to {1, 9, 
//8, 4, 2, 7, 6, 0, 0, 0, 0}. The order of all other elements should be 
//same.


#include <iostream>
#include <vector>
using namespace std;

// Function to merge two halves such that zeroes are moved to the end
void mergeHalves(vector<int>& arr, int low, int mid, int high) {
    vector<int> temp;
    
    // Add non-zero elements from both halves
    for (int i = low; i <= mid; ++i) {
        if (arr[i] != 0) temp.push_back(arr[i]);
    }
    for (int i = mid + 1; i <= high; ++i) {
        if (arr[i] != 0) temp.push_back(arr[i]);
    }

    // Add zero elements from both halves
    for (int i = low; i <= mid; ++i) {
        if (arr[i] == 0) temp.push_back(arr[i]);
    }
    for (int i = mid + 1; i <= high; ++i) {
        if (arr[i] == 0) temp.push_back(arr[i]);
    }

    // Copy the sorted array back to the original array
    for (int i = low; i <= high; ++i) {
        arr[i] = temp[i - low];
    }
}

// Recursive function to rearrange the array
void rearrangeZeroes(vector<int>& arr, int low, int high) {
    if (low >= high) return; // Base case

    int mid = low + (high - low) / 2;

    // Recursively divide and conquer
    rearrangeZeroes(arr, low, mid);
    rearrangeZeroes(arr, mid + 1, high);

    // Combine the two halves
    mergeHalves(arr, low, mid, high);
}

int main() {
    vector<int> arr = {1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0};

    cout << "Original Array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    // Call the function
    rearrangeZeroes(arr, 0, arr.size() - 1);

    cout << "Modified Array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    return 0;
}
//Time Complexity is O(n logn)
