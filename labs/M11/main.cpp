#include <iostream>

/**
 * Mark Chouinard | W0527452 | 11/20/22 | M11 Lab
 *
 * The user should see a list of what each bin holds and how many parts are in each bin.  The user can choose to either
 * quit the program or select a bin.  When a bin is selected, the user can either add parts to it or remove parts from
 * it.  The loop then repeats, showing the updated bin data on the screen.
 */

using namespace std;

// Bin struct
struct Bin {
    string partDesc;
    int numParts;
};

// Enum for adding or subtracting - overkill?
enum Direction {
    UP = 1,
    DOWN
};

// function definitions
unsigned int unitChange(Bin box, Direction dir);

Direction getDirection();

Bin addParts(Bin box, int count);

Bin removeParts(Bin box, int count);

bool validCount(Bin box, int count, Direction dir);

// Global because "Do not use classes nor pointers for the lab"
Bin boxes[10];

/**
 * Show menu - where all the action begins and ends
 */
void displayMenu() {
    unsigned int size = 10, boxID = 99, count;
    Bin tempBin;
    while (boxID != 0) {
        for (int i = 0; i < size; i++) {
            cout << i + 1 << ". " << boxes[i].partDesc << " [" << boxes[i].numParts << "]\n";
        }
        cout << "0 [quit]\n";
        cout << "\nEnter a menu number: ";
        while (!(cin >> boxID) || boxID > 10) {
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            cout << "Enter a menu number: ";
        }
        if (boxID == 0) {
            exit(0);
        }
        cout << boxes[boxID - 1].partDesc << " [" << boxes[boxID - 1].numParts << "]" << endl;
        // Add or Remove Parts
        Direction dir = getDirection();
        tempBin = boxes[boxID - 1];
        count = unitChange(tempBin, dir);

        switch (dir) {
            case UP:
                cout << "Add " << count << endl;
                tempBin = addParts(tempBin, count);
                break;
            default:
                cout << "Subtract " << count << endl;
                tempBin = removeParts(tempBin, count);
        }
        boxes[boxID - 1].numParts = tempBin.numParts;
        cout << boxes[boxID - 1].partDesc << " now has " << boxes[boxID - 1].numParts << " pieces\n";
    }

}

/**
 * Add parts to bin
 *
 * @param box
 * @param count
 * @return
 */
Bin addParts(Bin box, int count) {

    box.numParts += count;

    return box;
}

/**
 * Remove parts from bin
 *
 * @param box
 * @param count
 * @return
 */
Bin removeParts(Bin box, int count) {

    box.numParts -= count;

    return box;
}

/**
 * Get user choice to add or subtract
 * @return
 */
Direction getDirection() {
    unsigned int choice;
    cout << "1 [Increase]\n2 [Decrease]\n";
    while (!(cin >> choice) || choice < UP || choice > DOWN) {
        cout << "choice: " << choice << endl;
        cout << "Choose 1 or 2: ";
    }
    switch (choice) {
        case 1:
            return UP;
            break;
        default:
            return DOWN;
    }

}

/**
 * Get number of units to add/subtract
 *
 * @param box
 * @param dir
 * @return
 */
unsigned int unitChange(Bin box, Direction dir) {
    unsigned int choice;
    cout << "How many units?: ";
    while (!(cin >> choice) || choice < 1 || choice > 30) {
        cout << "Inventory must remain between 0 and 30\nThere are currently " << box.numParts << " units in bin.\n";
    }
    while ( !validCount(box, choice, dir) ) {
        cout << "Inventory must remain between 0 and 30\nThere are currently " << box.numParts << " units in bin.\n";
        cout << "How many units? ";
        cin >> choice;
    }

    return choice;
}

/**
 * Validate count
 *
 * @param box
 * @param count
 * @param dir
 * @return
 */
bool validCount(Bin box, int count, Direction dir) {
    if (dir == UP) {
        if (static_cast<int>(box.numParts) + count > 30) {
            return false;
        }
    } else {
        if (static_cast<int>(box.numParts) - count < 0) {
            return false;
        }
    }

    return true;
}

// Setup bins
void init() {
    boxes[0].partDesc = "Valve";
    boxes[0].numParts = 10;
    boxes[1].partDesc = "Bearing";
    boxes[1].numParts = 5;
    boxes[2].partDesc = "Bushing";
    boxes[2].numParts = 15;
    boxes[3].partDesc = "Coupling";
    boxes[3].numParts = 21;
    boxes[4].partDesc = "Flange";
    boxes[4].numParts = 7;
    boxes[5].partDesc = "Gear";
    boxes[5].numParts = 5;
    boxes[6].partDesc = "Gear Housing";
    boxes[6].numParts = 5;
    boxes[7].partDesc = "Vacuum Gripper";
    boxes[7].numParts = 25;
    boxes[8].partDesc = "Cable";
    boxes[8].numParts = 18;
    boxes[9].partDesc = "Rod";
    boxes[9].numParts = 12;

    displayMenu();
}

int main() {

    init();

    return 0;
}
