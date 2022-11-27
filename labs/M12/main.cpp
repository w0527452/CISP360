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

    cout << "Mark spend total: " << mark->getSpent() << endl;
    cout << "total after spending 35: " << mark->spend(35) << endl;
    cout << "Mark buy total: " << mark->getBought() << endl;
    cout << "total after buying 40: " << mark->buy(40) << endl;

    // Cleanup
    delete mark;
    mark = nullptr;

    

}

int main() {

    demoMemberType();

    return 0;
}
