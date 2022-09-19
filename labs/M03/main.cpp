/**
 * Mark Chouinard | W0527452 | 09/18/22 | M03 Lab
 *
 * Write a program that asks the user to enter today's sales for five stores.
 * The program should then display a bar graph comparing each store's sales.
 * Create each bar in the graph by displaying a row of asterisks.  Each asterisk should represent $100 of sales.
 */

#include <iostream>

using namespace std;

int main() {

    // Declare array stores[] to store sales values, hundreds to store calculated number of asterisks
    int stores[5], hundreds;

    // Gather data for each store
    for (int n = 0; n < 5; n++) {

        // Flag for sales validation
        bool valid = false;
        // Do-While for gathering store sales
        do {
            cout << "Enter today's sales for store " << n + 1 << ": ";
            cin >> stores[n];
            // Validate sales number
            if (cin.good()) {
                valid = true;
            } else {
                // Empty input buffer
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                cout << "Invalid sales number. Re-enter." << endl;
            }
        } while (!valid);
    }

    cout << "\n\nSALES BAR CHART\n";
    cout << "(Each * = $100)\n\n";

    // Outer loop for each Store
    for (int i = 0; i < 5; i++) {
        // Calculate number of asterisks to display
        hundreds = stores[i] / 100;
        cout << "Store " << i + 1 << ": ";
        // Inner loop for asterisk display
        for (int h = 1; h <= hundreds; h++) {
            cout << "*";
        }
        // End with newline
        cout << "\n";
    }

    return 0;
}
