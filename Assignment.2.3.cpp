/*Implement a problem of minimum work to be done
per day to finish given tasks within D days problem.
Statement: Given an array task[] of size N denoting
amount of work to be done for each task, the problem
is to find the minimum amount of work to be done on
each day so that all the tasks can be completed in at
most D days. Note: On one day work can be done for
only one task.
Input: task[] = [3, 4, 7, 15], D = 10
Output: 4
Input: task[] = [30, 20, 22, 4, 21], D = 6
Output: 22*/


#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

// Function to check if it's possible to complete tasks in D days with max work 'maxWork' per day
bool isPossible(const vector<int>& task, int D, int maxWork) {
    int daysRequired = 1, currentWork = 0;
    
    for (int t : task) {
        if (currentWork + t > maxWork) {
            // If adding this task exceeds maxWork, start a new day
            daysRequired++;
            currentWork = t;
            if (daysRequired > D) {
                return false; // More than D days required
            }
        } else {
            currentWork += t;
        }
    }
    return true;
}

// Function to find the minimum amount of work to be done per day to complete tasks in D days
int minWorkPerDay(const vector<int>& task, int D) {
    int low = *max_element(task.begin(), task.end()); // Maximum task value is the lower bound
    int high = accumulate(task.begin(), task.end(), 0); // Sum of tasks is the upper bound

    int result = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isPossible(task, D, mid)) {
            result = mid; // Update result, as it's possible with mid work per day
            high = mid - 1; // Try for a smaller max work per day
        } else {
            low = mid + 1; // Try for a larger max work per day
        }
    }

    return result;
}

// Driver code
int main() {
    vector<int> task1 = {3, 4, 7, 15};
    int D1 = 10;
    cout << "Minimum work per day for task1: " << minWorkPerDay(task1, D1) << endl; // Output: 4

    vector<int> task2 = {30, 20, 22, 4, 21};
    int D2 = 6;
    cout << "Minimum work per day for task2: " << minWorkPerDay(task2, D2) << endl; // Output: 22

    return 0;
}
O(N log N)
