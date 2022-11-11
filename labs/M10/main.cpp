#include <iostream>

using namespace std;

/**
 * Mark Chouinard | W0527452 | 11/10/22
 * M10
 * Write a function that accepts an int array and the array's size as arguments.  The function should create a copy of
 * the array, except that the element values should be reversed in the copy.  The function should return a pointer to
 * the new array.  Demonstrate the function in a complete program.
 */

/**
 * Return pointer to reversed array
 *
 * @param numbers
 * @param size
 * @return
 */
int *reverse(int numbers[], int size) {
    int *reversed = nullptr;
    // Dynamic allocation so it doesn't disappear when function ends
    reversed = new int[size];

    // Point of exercise was pointers, not array reversal, right?
    reverse_copy(numbers, numbers + size, reversed);

    return reversed;
}

/**
 * Helper func to print array
 *
 * @param arr
 * @param size
 */
void printArray( const int *arr, int size ) {
    for ( int i = 0; i < size; i++ ) {
        cout << *(arr + i ) << ' ';
    }
    cout << endl;
}

/**
 * Keep main clean
 */
void init() {
    const int size = 5;
    // Null pointer to accept return from revers func
    int *reversed = nullptr;

    // Create array to be reversed
    int arr[] = {1, 2, 3, 4, 5};

    printArray( arr, size );

    // Assign pointer returned from func to our pointer
    reversed = reverse(arr, size);

    printArray( reversed, size );

    // Free memory, reset to null pointer
    delete[] reversed;
    reversed = nullptr;
}


int main() {

    init();

    return 0;
}
