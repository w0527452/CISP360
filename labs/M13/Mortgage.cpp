//
// Created by Mark Chouinard on 12/3/22.
//

#include "Mortgage.h"


using namespace std;

// Getters/Setters
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
    Mortgage::rate = rate / 100;
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

// Calculate loan values
void Mortgage::calculateLoan() {
    double term;
    this->numPayments = this->years * 12;
    term = pow(1 + this->rate / 12, 12 * this->years);
    this->payment = (this->loanAmount * this->rate / 12 * term) / (term - 1);
}

// Calculate total paid
double Mortgage::totalPaid() const {
    return this->payment * this->numPayments;
}

// Calculate total interest paid
double Mortgage::totalInterest() const {
    return this->totalPaid() - this->loanAmount;
}

void Mortgage::showDetails() {
    cout << "LOAN DETAILS\n";
    cout << "============\n";
    cout << "Loan Amount: " << this->loanAmount << endl;
    cout << "Interest Rate: " << this->rate * 100 << endl;
    cout << "Number Years: " << this->years << endl;
    cout << "Monthly Payment: $" << fixed << setprecision(2) << this->getPayment() << endl;
    cout << "Total Paid: $" << fixed << setprecision(2) << this->totalPaid() << endl;
    cout << "Total Interest: $" << fixed << setprecision(2) << this->totalInterest() << endl;
}

// Prompt user for details
// Only used with default constructor
void Mortgage::getDetails() {
    bool amountValid = false, rateValid = false, yearsValid = false;
    double tmpRate;

    do {
        cout << "Amount of loan: ";
        cin >> this->loanAmount;
        if (cin.good() && this->loanAmount > 0) {
            amountValid = true;
        } else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input; please re-enter amount." << endl;
        }
    } while (!amountValid);

    do {
        cout << "Percentage Rate: ";
        cin >> tmpRate;
        if (cin.good() && tmpRate > 1) {
            rateValid = true;
            this->setRate(tmpRate);
        } else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input; please re-enter rate." << endl;
        }
    } while (!rateValid);

    do {
        cout << "Number of Years: ";
        cin >> this->years;
        if (cin.good() && this->years > 0) {
            yearsValid = true;
        } else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input; please re-enter years." << endl;
        }
    } while (!yearsValid);
}

Mortgage::Mortgage(int years, double rate, double loanAmount) : years(years), rate(rate / 100), loanAmount(loanAmount) {
    this->calculateLoan();
}

Mortgage::Mortgage() {
    this->getDetails();
    this->calculateLoan();
}