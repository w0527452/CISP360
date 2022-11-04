#include <iostream>
using namespace std;

/**
 * Mark Chouinard | W0527452 | 11/3/22 | M09 Lab
 *
 * Write a program that dynamically allocates an array large enough to hold a user defined number of test scores
 * Once all the scores are entered, the array should be passed to a function that sorts them in ascending order.
 * Another function should be called that calculates the average score.  The program should display the sorted list of
 * scores and averages with appropriate headings.
 */

/**
 * Helper func to print array contents
 * @param array scores
 * @param int n scores size
 * @param string label Text to display
 */
void printArray(float scores[], int n, string label = "") {
    cout << label << endl;
    for (int i = 0; i < n; i++) {
        cout << *(scores + i) << " ";
    }
    cout << endl;
}

/**
 * Calculate average of array
 *
 * @param array scores
 * @param int n scores size
 * @return
 */
float scoreAverage(float scores[], int n) {
    float average, sum = 0.0;

    for (int x = 0; x < n; x++) {
        sum += *(scores + x);
    }

    average = sum / n;

    return average;
}

/**
 * Helper func to sort array (insertion)
 *
 * @param array scores
 * @param int n size of scores
 */
void sortScores(float scores[], int n) {
    float key;
    int step, i;
    for (step = 1; step < n; step++) {
        key = *(scores + step);
        i = step - 1;

        while (key < *(scores + i) && i >= 0) {
            *(scores + (i + 1)) = *(scores + i);
            --i;
        }
        *(scores + (i + 1)) = key;
    }
}

/**
 * Start the program?
 */
void init() {
    int num;
    float average;

    cout << "How many scores? ";
    cin >> num;
    // Dynamic
    auto *scores = new float[num];
    for (int n = 0; n < num; n++) {
        cout << "Enter score number " << n + 1 << ": ";
        cin >> *(scores + n);
    }

    // Print before
    printArray(scores, num, "Before Sort");
    // Sort
    sortScores(scores, num);
    // Average
    average = scoreAverage(scores, num);
    // Print after
    printArray(scores, num, "Sorted");
    // Display avg
    cout << "The average is " << average << endl;
}

int main() {
    init();

    return 0;
}
