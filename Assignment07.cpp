#include <iostream>
#include <string>
#include <cctype> // For toupper and islower

using namespace std;

// Function to check if s1 can be transformed to s2
bool canTransform(string s1, string s2) {
    int i = 0, j = 0; // Pointers for s1 and s2
    int n1 = s1.length(), n2 = s2.length();

    // Traverse the strings
    while (i < n1 && j < n2) {
        // If the current character in s1 (converted to uppercase) matches s2
        if (toupper(s1[i]) == s2[j]) {
            j++; // Move to the next character in s2
        } else if (isupper(s1[i])) {
            // If s1[i] is uppercase and doesn't match s2[j], transformation is not possible
            return false;
        }
        // Move to the next character in s1
        i++;
    }

    // Check if all characters in s2 are matched
    while (j < n2) {
        return false; // If there are unmatched characters in s2, return false
    }

    // If all remaining characters in s1 are lowercase, transformation is possible
    while (i < n1) {
        if (isupper(s1[i])) {
            return false; // If any unmatched uppercase character remains, return false
        }
        i++;
    }

    return true; // All conditions satisfied
}

int main() {
    // Example Inputs
    string s1 = "daBcd";
    string s2 = "ABC";

    // Check transformation and output result
    if (canTransform(s1, s2)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    // Test with another input
    s1 = "argaju";
    s2 = "RAJ";
    if (canTransform(s1, s2)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
