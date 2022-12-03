//
// Created by Mark Chouinard on 12/3/22.
//

#include "Mortgage.h"
#include <cmath>
using namespace std;

int Mortgage::getYears() const {
    return years;
}

void Mortgage::setYears(int years) {
    Mortgage::years = years;
}

int Mortgage::getNumPayments() const {
    return numPayments;
}

double Mortgage::getRate() const {
    return rate;
}

void Mortgage::setRate(double rate) {
    Mortgage::rate = rate/100;
}


int Mortgage::getLoanAmount() const {
    return loanAmount;
}

void Mortgage::setLoanAmount(double loanAmount) {
    Mortgage::loanAmount = loanAmount;
}

double Mortgage::getPayment() const {
    return payment;
}

void Mortgage::calculateLoan() {
    double term;
    this->numPayments = this->years * 12;
    term = pow( 1 + this->rate/12, 12 * this->years );
    this->payment = ( this->loanAmount * this->rate/12 * term ) / (term - 1)  ;
}

double Mortgage::totalPaid() const {
    return this->payment * this->numPayments;
}

Mortgage::Mortgage(int years, double rate, double loanAmount) : years(years), rate(rate/100), loanAmount(loanAmount) {
    this->calculateLoan();
}

Mortgage::Mortgage() : Mortgage( 0.0, 0.0, 0.0 ) {
}