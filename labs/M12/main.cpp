#include <iostream>
#include "MemberType.h"

using namespace std;

void output(MemberType member) {
    cout << member.getName() << " spend total: " << member.getSpent() << endl;
    cout << "total after spending 35: " << member.spend(35) << endl;
    cout << member.getName() << " buy total: " << member.getBought() << endl;
    cout << "total after buying 40: " << member.buy(40) << endl;
}

void demoMemberType() {
    // create nullptr
    MemberType *mark = nullptr;
    // instantiate/assign MemberType to pointer
    mark = new MemberType;
    mark->setName("Mark");
    mark->setBought(5);
    mark->setId(1);
    mark->setSpent(20);

    output(*mark);

    // Cleanup
    delete mark;
    mark = nullptr;

    cout << endl << endl;

    mark = new MemberType(2, 125, 200, "Alex");

    output(*mark);

    // Cleanup
    delete mark;
    mark = nullptr;

}

int main() {

    demoMemberType();

    return 0;
}
