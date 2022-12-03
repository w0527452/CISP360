#include <iostream>
#include "Mortgage.h"
#include <iomanip>
#include <limits>

using namespace std;

Mortgage getInput() {
    int years, amount;
    double rate;
    bool amountValid = false, rateValid = false, yearsValid = false;

    Mortgage *house = nullptr;


    do {
        cout << "Amount of loan: ";
        cin >> amount;
        if (cin.good() && amount > 0) {
            amountValid = true;
        } else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input; please re-enter amount." << endl;
        }
    } while (!amountValid);

    do {
        cout << "Percentage Rate: ";
        cin >> rate;
        if (cin.good() && rate > 1) {
            rateValid = true;
        } else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input; please re-enter rate." << endl;
        }
    } while (!rateValid);

    do {
        cout << "Number of Years: ";
        cin >> years;
        if (cin.good() && years > 0) {
            yearsValid = true;
        } else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input; please re-enter years." << endl;
        }
    } while (!yearsValid);

    house = new Mortgage(years, rate, amount);

    return *house;

}

int main() {

    Mortgage house;

    house = getInput();

    cout << fixed << setprecision(2) << house.getPayment() << endl;
    cout << fixed << setprecision(2) << "Total Paid: " << house.totalPaid() << endl;

    return 0;
}
