#include "MemberType.h"

int MemberType::getId() const {
    return ID;
}

void MemberType::setId(int id) {
    ID = id;
}

int MemberType::getBought() const {
    return bought;
}

void MemberType::setBought(int bought) {
    MemberType::bought = bought;
}


int MemberType::getSpent() const {
    return spent;
}

void MemberType::setSpent(int spent) {
    MemberType::spent = spent;
}

const string &MemberType::getName() const {
    return name;
}

void MemberType::setName(const string &name) {
    MemberType::name = name;
}

int MemberType::spend(int amount) {
    this->spent += amount;

    return this->spent;
}

int MemberType::buy(int amount) {
    this->bought += amount;

    return this->bought;
}