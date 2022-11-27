#include <iostream>
#include "MemberType.h"

using namespace std;

void demoMemberType() {
    MemberType *mark = nullptr;
    mark = new MemberType;
    mark->setName("Mark");
    mark->setBought(5);
    mark->setId(1);
    mark->setSpent(20);
}

int main() {

    demoMemberType();

    return 0;
}
