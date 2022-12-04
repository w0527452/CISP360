#include <iostream>
#include "Mortgage.h"


/**
 * Mark Chouinard | 12/3/22 | M13 LAB | W0527452
 *
 * Design a class that will determine the monthly payment on a home mortgage.
 */

using namespace std;

int main() {

    // Default constructor prompts for all details
    Mortgage house;
    house.showDetails();

// Different constructor example(Screenshot #3)
//    Pointer and whatnot
//    Mortgage *house;
//    house = new Mortgage(25, 7.5, 450500);
//    house->showDetails();
//    delete house;
//    house = nullptr;

    return 0;
}
