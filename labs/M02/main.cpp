/**
 * Mark Chouinard | W0527452
 * 09/06/22
 * M02 Lab
 *
 * Write a program that displays a menu allowing the user to select one of these four gases.  After a selection has been made, the user should enter the number of seconds it took for the sound to travel in this medium from its source to the location at which it was detected.  The program should then report how far away (in meters) the source of the sound was from the detection location.
 */
#include <iostream>

using namespace std;

int main() {
    // Declare constants
    const float C02 = 258.0, AIR = 331.5, HELIUM = 972.0, HYDROGEN = 1270.0;
    const int C02_CH = 1, AIR_CH = 2, HELIUM_CH = 3, HYDROGEN_CH = 4;
    // Declare string constants for prompt/error
    const string HOWLONG = "Enter number of seconds it took to hear the sound (0-30)",
            TIME_ERROR = "Invalid time.  Run the program again and enter a time between 0 and 30 seconds";
    // Declare vars for input and calculation
    int choice;
    float time, distance;


    // Display gas choice
    cout << "Select a gas\n";
    cout << "1. Carbon Dioxide\n";
    cout << "2. Air\n";
    cout << "3. Helium\n";
    cout << "4. Hydrogen\n";
    cin >> choice;

    // Basic input validation using if/else if statements
    if (choice == C02_CH) {
        // Prompt user for seconds input
        cout << HOWLONG;
        cin >> time;
        // Validate time input
        if (time < 0 || time > 30) {
            // Alert user of invalid input
            cout << TIME_ERROR;
        } else {
            // Calculate distance
            distance = time * C02;
            // Output distance
            cout << "The sound was " << distance << " meters away from the detection location";
        }
    } else if (choice == AIR_CH) {
        cout << HOWLONG;
        cin >> time;
        if (time < 0 || time > 30) {
            cout << TIME_ERROR;
        } else {
            distance = time * AIR;
            cout << "The sound was " << distance << " meters away from the detection location";
        }
    } else if (choice == HELIUM_CH) {
        cout << HOWLONG;
        cin >> time;
        if (time < 0 || time > 30) {
            cout << TIME_ERROR;
        } else {
            distance = time * HELIUM;
            cout << "The sound was " << distance << " meters away from the detection location";
        }
    } else if (choice == HYDROGEN_CH) {
        cout << HOWLONG;
        cin >> time;
        if (time < 0 || time > 30) {
            cout << TIME_ERROR;
        } else {
            distance = time * HYDROGEN;
            cout << "The sound was " << distance << " meters away from the detection location";
        }
    } else {
        // User input invalid choice.  Let them know.
        cout << "Invalid choice.  Re-run the program and enter a choice of 1 - 4";
    }

    return 0;
}
