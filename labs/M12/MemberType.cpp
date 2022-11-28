#include "MemberType.h"
#include <iostream>

int MemberType::getId() const {
    return ID;
}

void MemberType::setId(int id) {
    ID = id;
}

int MemberType::getBought() const {
    return bought;
}

void MemberType::setBought(int amount) {
    MemberType::bought = amount;
}


int MemberType::getSpent() const {
    return spent;
}

void MemberType::setSpent(int amount) {
    MemberType::spent = amount;
}

const string &MemberType::getName() const {
    return name;
}

void MemberType::setName(const string &name) {
    MemberType::name = name;
}

void MemberType::spend(int amount, bool output) {
    this->spent += amount;

    if (output) {
        cout << this->getName() << " spent $" << amount << endl;
    }
}

void MemberType::buy(int amount, bool output) {
    this->bought += amount;

    if (output) {
        cout << this->getName() << " bought " << amount << " books" << endl;
    }
}

void MemberType::summary() const {
    cout << this->getName() << "(ID " << this->getId() << ")" << " has spent $" << this->getSpent() << " and bought "
         << this->getBought() << " books" << endl;
}

MemberType::MemberType(int id, int bought, int spent, const string &name) : ID(id), bought(bought), spent(spent),
                                                                            name(name) {}

MemberType::MemberType() {
    this->name = "";
    this->bought = 0;
    this->spent = 0;
    this->ID = 0;
}




