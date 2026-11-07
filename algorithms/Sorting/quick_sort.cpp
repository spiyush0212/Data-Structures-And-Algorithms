#include <iostream>
#include <vector>

using namespace std;

/*
    ALGORITHM

    (1) Choose an element as the pivot (here, the last element).
    (2) Partition the array: move all elements <= pivot to its left and larger >= elements to its right.
    (3) Place the pivot at its correct sorted position after step (2)
    (4) Recursively apply Quick Sort steps (1) (2) and (3) to the left and right subarrays, excluding the pivot.
    (5) Stop when a subarray has zero or one element, as it is already sorted.

    TIME COMPLEXITY:

    Best Case:    O(n log n)
    Average Case: O(n log n)
    Worst Case:   O(n^2)

    SPACE COMPLEXITY:

    Average: O(log n) - Recursion stack
    Worst:   O(n)     - Recursion stack

    PROPERTIES:

    - In-place sorting algorithm
    - Not stable, same elements can move places. Eg; [1 1 2 1]
    - Divide and conquer algorithm
    - No additional array required
*/



/*
    PARTITION FUNCTION (Lomuto Partition Scheme)

    1. Select the last element as the pivot.
    2. Move all elements <= pivot to its left.
    3. Move all elements > pivot to its right.
    4. Place pivot at its correct sorted position.
    5. Return the pivot's final index.
*/

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];

    // i tracks the boundary of elements <= pivot
    int i = low - 1;

    for (int j = low; j < high; j++) {

        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    // Place pivot at its correct position
    swap(arr[i + 1], arr[high]);

    return i + 1;
}

/*
    QUICK SORT

    1. Choose a pivot and partition the array.
    2. Recursively sort the left subarray.
    3. Recursively sort the right subarray.
    4. No merging is required because partitioning
       places the pivot in its correct position.
*/

void quickSort(vector<int>& arr, int low, int high) {
    if (low >= high)
        return;

    int pivotIndex = partition(arr, low, high);

    quickSort(arr, low, pivotIndex - 1);
    quickSort(arr, pivotIndex + 1, high);
}

int main() {

    vector<int> arr = {10, 7, 8, 9, 1, 5};

    cout << "Original Array: ";
    for (int num : arr)
        cout << num << " ";

    quickSort(arr, 0, arr.size() - 1);

    cout << "\nSorted Array: ";
    for (int num : arr)
        cout << num << " ";

    return 0;
}