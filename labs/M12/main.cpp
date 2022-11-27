#include <iostream>
#include "MemberType.h"

using namespace std;

void demoMemberType() {
    // create nullptr
    MemberType *mark = nullptr;
    // instantiate/assign MemberType to pointer
    mark = new MemberType;
    mark->setName("Mark");
    mark->setBought(5);
    mark->setId(1);
    mark->setSpent(20);

    mark->summary();
    mark->buy(40);
    mark->spend(25);
    cout << "After spending 25, buying 40:\n";
    mark->summary();

    // Cleanup
    delete mark;
    mark = nullptr;

    cout << endl << endl;

    // Constructor with everything
    mark = new MemberType(2, 125, 200, "Alex");

    mark->summary();
    mark->buy(20);
    mark->spend(30);
    cout << "After spending 30, buying 20:\n";

    mark->summary();

    // Cleanup
    delete mark;
    mark = nullptr;

}

int main() {

    demoMemberType();

    return 0;
}
