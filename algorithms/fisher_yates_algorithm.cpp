#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

/*
    Fisher-Yates Shuffle:
    Randomly shuffles an array in O(N) time and O(1) auxiliary space.

    Two implementations:
    1. mt19937 + uniform_int_distribution - Better randomness and uniform distribution.
    2. rand() % (i + 1) - Simpler, but can have modulo bias.

    Time & Space:
    Time Complexity: O(N)
    Space Complexity: O(1) auxiliary space

    Algorithm:
    - Start from the last element and move toward the first.
    - For each index i, randomly choose an index j between 0 and i.
    - Swap arr[i] with arr[j].
    - Continue until i = 1.
    - This ensures every permutation has an equal probability when using a uniform random generator.
*/

// Method 1: Fisher-Yates using mt19937
void shuffleMT19937(vector<int>& arr) {
    const int n = arr.size();
    mt19937 gen{random_device{}()};

    for (int i = n - 1; i > 0; i--) {
        uniform_int_distribution<int> dist(0, i);
        int j = dist(gen);
        swap(arr[i], arr[j]);
    }
}

// Method 2: Fisher-Yates using rand()
void shuffleRand(vector<int>& arr) {
    const int n = arr.size();

    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        swap(arr[i], arr[j]);
    }
}

void print(const vector<int>& arr) {
    for (int x : arr) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};

    cout << "Original array: ";
    print(arr);

    shuffleMT19937(arr);

    cout << "After MT19937 shuffle: ";
    print(arr);

    shuffleRand(arr);

    cout << "After rand() shuffle: ";
    print(arr);

    return 0;
}