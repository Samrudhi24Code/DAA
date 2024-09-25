//Implement a problem of activity selection problem
//with K persons.
//Statement: Given two arrays S[] and E[] of size N denoting starting
//and closing time of the shops and an integer value K denoting the
//number of people, the task is to find out the maximum number of
//shops they can visit in total if they visit each shop optimally based
//on the following conditions:
// A shop can be visited by only one person
// A person cannot visit another shop if its timing collide with it

#include <iostream>
using namespace std;

struct Shop {
    int start, end;
};

// Bubble sort to sort shops based on their ending time
void bubbleSort(Shop shops[], int N) {
    for (int i = 0; i < N - 1; ++i) {
        for (int j = 0; j < N - i - 1; ++j) {
            if (shops[j].end > shops[j + 1].end) {
                // Swap the shops
                Shop temp = shops[j];
                shops[j] = shops[j + 1];
                shops[j + 1] = temp;
            }
        }
    }
}

int main() {
    int N, K;

    cout << "Enter the number of shops: ";
    cin >> N;

    // Dynamically allocate arrays
    int *S = new int[N];
    int *E = new int[N];
    Shop *shops = new Shop[N];

    cout << "Enter the start and end times of the shops:\n";
    for (int i = 0; i < N; ++i) {
        cin >> S[i] >> E[i];
        shops[i].start = S[i];
        shops[i].end = E[i];
    }

    cout << "Enter the number of persons: ";
    cin >> K;

    // Sort the shops based on their end times using bubble sort
    bubbleSort(shops, N);

    // Dynamically allocate the persons array
    int *persons = new int[K]();
    int count = 0;

    // Assign shops to persons optimally
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < K; ++j) {
            if (persons[j] <= shops[i].start) {
                persons[j] = shops[i].end;
                count++;
                break;
            }
        }
    }

    cout << "Maximum shops visited: " << count << endl;

    // Clean up dynamically allocated memory
    delete[] S;
    delete[] E;
    delete[] shops;
    delete[] persons;

    return 0;
}
