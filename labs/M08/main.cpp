/**
 * Mark Chouinard | W0527452 | 10/25/22 | M08 Lab
 *
 * Write a program that uses two identical arrays of just eight integers.
 * It should display the contents of the first array, then call a function to sort the array using an ascending order
 * bubble sort modified to print out the array contents after each pass of the sort.  Next, the program should display
 * the contents of the the second array, then call a function to sort the array using an ascending order selection sort
 * modified  to print out the array contents after each pass of the sort.
 */
#include <iostream>
using namespace std;

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
void printArray(int numbers[], int n, const string& label ) {
    if ( !label.empty() ) {
        cout << label << endl;
    }
    for (int i = 0; i < n; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;
}

/**
 * Bubble Sort Array
 *
 * @param arr
 * @param n
 */
void bubbleSort( int arr[], int n ) {

    cout << "Original contents\n";
    printArray( arr, n, "Original contents (bubble)" );
    for ( int i = 0; i < n; i++ )  {
        for ( int j = i + 1; j < n; j++ ) {
            if ( arr[j] < arr[i] ) {
                swap( arr[j], arr[i] );
            }
            printArray( arr, n, "" );
        }
        printArray( arr, n, "" );
    }
}

/**
 * Linear Sort Array
 *
 * @param arr
 * @param n
 */
void selectionSort( int arr[], int n ) {
    int min;
    printArray( arr, n, "Original contents (selection)" );
    for ( int i = 0; i < n-1; i++ ) {
        min = i;
        for ( int j = i + 1; j < n; j++ ) {
            if ( arr[j] < arr[min] ) {
                min = j;
                swap( arr[i], arr[min] );
            }
            printArray( arr, n, "" );
        }
        printArray( arr, n, "" );
    }
}

int main() {
    int len = 8;
    int bubble[] = {18, 22, 4, 89, 48, 1, 99, 35 };
    int selection[] = {18, 22, 4, 89, 48, 1, 99, 35 };

    bubbleSort( bubble, len );
    selectionSort( selection, len );

    return 0;
}
