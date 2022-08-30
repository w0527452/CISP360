/**
 * Mark Chouinard
 * W0527452
 * 08/29/22
 * M01 Lab
 *
 * A vineyard owner is planting several new rows of grapevines, and needs to know how many grapevines to plant in each
 * row.  She has determined that after measuring the length of a future row, she can use the following formula to
 * calculate the number of vines that will fit in the row, along with the trellis end-post assemblies that will need to
 * be constructed  at each end of the row.  V = R - 2E / S
 */
#include <iostream>
#include <iomanip>

using namespace std;

// Calculate number of grapevines that will fit in a row
void vineyard() {

    // init vars
    float vines, rowLength, endPost, spaceBetween;
    // Ask for row length
    cout << "What is the length of the row, in feet?\n";
    // Assign to var
    cin >> rowLength;
    // Ask for amount of space used by end-post assemblies
    cout << "How much space is used by an end-post assembly, in feet?\n";
    // Assign to var
    cin >> endPost;
    // Ask for space between vines
    cout << "What is the amount of space between the vines, in feet?\n";
    // Assign to var
    cin >> spaceBetween;
    // Calculate number of vines based on given formula
    vines = rowLength - 2 * endPost / spaceBetween;
    // Set output to 2 decimal places
    cout << setprecision(2) << fixed;
    // Output result string
    cout << vines << " grapevines will fit in this row.\n";

}

int main() {
    vineyard();

    return 0;
}
