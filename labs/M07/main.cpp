#include <iostream>

/**
 * Mark Chouinard | W0527452 | 10/18/22 | Array Search Lab
 *
 * Write a program that has an array of at least 20 integers.
 * It should call a function that uses the linear search algorithm to locate one of the values.
 * The function should keep a count of the number of comparisons it makes until it finds the value.
 * The program then should call a function that uses the binary search algorithm to locate the same value.
 * It should also keep count of the number of comparisons it makes.  Display these values on the screen.
 */

using namespace std;

// Func definitions (not needed after refactor)
void printArray(int[], int);

/**
 * Helper func to swap var values
 *
 * @param a
 * @param b
 */
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

/**
 * Helper func to print array
 *
 * @param numbers
 * @param n
 */
void printArray(int numbers[], int n) {
    cout << "Array Contents:\n";
    for (int i = 0; i < n; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;
}

/**
 * Helper func to output results message
 *
 * @param found Subscript where needle was found or -1 for not found
 * @param needle Value we were searching for in array
 */
void showResults(int found, int needle) {
    if (found != -1) {
        cout << needle << " found at subscript " << found << endl << endl;
    } else {
        cout << needle << " not found in array\n\n";
    }
}

/**
 * Bubble sort array of n length
 *
 * @param arr
 * @param n
 */
void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }

    // Output sorted array
    printArray(arr, n);
}

/**
 * Binary search array for int i
 *
 * @param arr
 * @param lo    lower key/subscript to search
 * @param hi    Upper key/subscript to search
 * @param i     int to search for in array
 * @return
 */
int myBinarySearch(int arr[], int lo, int hi, int i) {
    static int count = 0, sorted = false;

    // Make sure we have a sorted array
    if (!sorted) {
        bubbleSort(arr, hi + 1);
        sorted = true;
    }
    count++;

    if (lo <= hi) {
        int mid = lo + (hi - lo) / 2; // Index of middle element.

        // If we found it, output count and return subscript
        if (arr[mid] == i) {
            cout << "count: " << count << endl;

            return mid;
        }

        // Split array and start over
        if (arr[mid] > i) {
            // Recursive call for left
            return myBinarySearch(arr, lo, mid - 1, i);
        } else // Recursive call for right
            return myBinarySearch(arr, mid + 1, hi, i);
    }

    // Output count
    cout << "count: " << count << endl;

    return -1; // Not found
}

/**
 * Sequentially search array for int
 *
 * @param arr
 * @param length
 * @param i
 * @return
 */
int myLinearSearch(int arr[], int length, int i) {
    static int count = 0;
    printArray(arr, length);
    for (int n = 0; n < length; n++) {
        count++;
        if (arr[n] == i) {
            cout << "count: " << count << endl;

            return n;
        }
    }

    // Output count
    cout << "count: " << count << endl;

    return -1;
}

int main() {
    // Declare and instantiate vars
    int numbers[] = {100, 48, 93, 20, 19, 49, 53, 84, 46, 27, 90, 56, 78, 39, 59, 22, 24, 14, 72, 80, 67};
    int found, needle = 3;

    cout << "Linear\n";
    found = myLinearSearch(numbers, 20, needle);
    showResults(found, needle);

    cout << "Binary\n";
    found = myBinarySearch(numbers, 0, 19, needle);
    showResults(found, needle);

    return 0;
}
