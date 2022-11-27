#include <iostream>
#include "MemberType.h"

/**
 * Mark Chouinard | W0527452 | 11/27/22 | Lab M12
 *
 * In this lab, you will design a class memberType.

    Each object of memberType can hold the name of a person, member ID, number of books bought, and amount spent.
    Include the member function to perform the various operations on the objects of memberType--for example, modify, set, and show a person's name.  Similarly, update, modify, and show the number of books bought and the amount spent.
    Add the appropriate constructors.
    Write the definitions of the member functions of memberType.
    Write a program to test various operations of your class memberType.
    Your main and your class should be in separate inline files (.cpp and .h).  Failure to provide program with separate files will result in a grade of zero.
 */

using namespace std;

void demoMemberType() {
    // create nullptr
    MemberType *mark = nullptr;
    // instantiate/assign MemberType to pointer
    mark = new MemberType;
    // set things
    mark->setName("Mark");
    mark->setBought(5);
    mark->setId(1);
    mark->setSpent(20);
    // show and do things
    mark->summary();
    mark->buy(40, true);
    mark->spend(25, true);
    mark->summary();

    cout << endl << endl;

    // create nullptr
    MemberType *alex = nullptr;
    // Constructor with everything
    alex = new MemberType(2, 125, 200, "Alex");
    // show and do things
    alex->summary();
    alex->buy(20, true);
    alex->spend(30, true);
    alex->summary();

    // Cleanup
    delete mark;
    mark = nullptr;
    delete alex;
    alex = nullptr;

}

int main() {

    demoMemberType();

    return 0;
}
