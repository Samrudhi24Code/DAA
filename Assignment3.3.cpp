//Implement Check if it is possible to transform one
string to another.
Statement Given two strings s1 and s2 (all letters in uppercase).
Check if it is possible to convert s1 to s2 by performing following
operations.
1. Make some lowercase letters uppercase.
2. Delete all the lowercase letters.
Input: s1 = daBcd s2 = ABC Output: yes
Input: s1 = argaju s2 = RAJ Output: yes

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to check if it's possible to transform s1 to s2
bool isTransformable(const string &s1, const string &s2) {
    int N = s1.size(), M = s2.size();

    // DP table to store results of subproblems
    vector<vector<bool>> dp(N + 1, vector<bool>(M + 1, false));

    // Base case: Both strings are empty
    dp[0][0] = true;

    // Fill the DP table
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            // If the character in s1 is a lowercase letter, we can delete it
            if (islower(s1[i - 1])) {
                dp[i][j] = dp[i - 1][j];  // Delete lowercase character
            } 
            // If the character in s1 is uppercase and matches the character in s2
            else if (j > 0 && s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1]; // Match uppercase character
            }
        }
    }

    // Return the result of transforming entire s1 to s2
    return dp[N][M];
}

int main() {
    string s1 = "daBcd", s2 = "ABC";
    if (isTransformable(s1, s2)) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    s1 = "argaju", s2 = "RAJ";
    if (isTransformable(s1, s2)) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    return 0;
}
















    O(N×M)
where:

𝑁
N is the length of string s1
𝑀
M is the length of string s2
