Implement a problem of activity selection problem
with K persons.
Statement: Given two arrays S[] and E[] of size N denoting starting
and closing time of the shops and an integer value K denoting the
number of people, the task is to find out the maximum number of
shops they can visit in total if they visit each shop optimally based
on the following conditions:
 A shop can be visited by only one person
 A person cannot visit another shop if its timing collide with it
Input: S[] = {1, 8, 3, 2, 6}, E[] = {5, 10, 6, 5, 9}, K = 2
Output: 4
Input: S[] = {1, 2, 3}, E[] = {3, 4, 5}, K = 2
Output: 3


#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// Struct to store the shop timings
struct Shop {
    int start;
    int end;
};

// Comparator to sort shops by end time
bool compare(Shop a, Shop b) {
    return a.end < b.end;
}

int maxShopsVisited(vector<int>& S, vector<int>& E, int K) {
    int n = S.size();
    vector<Shop> shops(n);

    // Step 1: Store start and end times in a vector of structs
    for (int i = 0; i < n; i++) {
        shops[i] = {S[i], E[i]};
    }

    // Step 2: Sort the shops by end time
    sort(shops.begin(), shops.end(), compare);

    // Step 3: Use a priority queue to track the end times of shops visited by each person
    priority_queue<int, vector<int>, greater<int>> pq;

    int count = 0;

    for (int i = 0; i < n; i++) {
        // Step 4: If there are available persons or a person finishes before the current shop starts
        if (pq.size() < K || pq.top() <= shops[i].start) {
            if (pq.size() == K) {
                pq.pop(); // Remove the earliest finishing shop if all persons are busy
            }
            pq.push(shops[i].end); // Assign the shop to a person
            count++; // Increment the count of shops visited
        }
    }

    return count;
}

int main() {
    vector<int> S1 = {1, 8, 3, 2, 6};
    vector<int> E1 = {5, 10, 6, 5, 9};
    int K1 = 2;
    cout << "Maximum shops visited (Example 1): " << maxShopsVisited(S1, E1, K1) << endl;

    vector<int> S2 = {1, 2, 3};
    vector<int> E2 = {3, 4, 5};
    int K2 = 2;
    cout << "Maximum shops visited (Example 2): " << maxShopsVisited(S2, E2, K2) << endl;

    return 0;
}
//Time complexity is O(n Log n) O(N) for sorting and log for prority queue
