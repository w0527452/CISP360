//Mark Chouinard | CISP 360 | W0527452
#include <iostream>

using namespace std;

//Lab Assignment M00

//Stock Commission:  Kathryn bought 750 shares of stock at a price of $35.00 per share.
// She must pay her stockbroker a 2 percent commission for the transaction.
// Write a program that calculates and displays the following:

//The amount paid for the stock alone (without the commission).
//The amount of the commission
//The total amount paid (for the stock plus the commission).

/**
 * Per lab, display cost of shares, cost of commission, total cost
 *
 * @param int shares Number of shares purchased
 * @param float perShare Cost per share
 */
void kathryn(int shares, float perShare) {
    // 2% commission
    const float fee = 0.02;
    // init vars
    float cost, commission, total;
    // calc cost
    cost = shares * perShare;
    // calc commission
    commission = cost * fee;
    // calc total cost
    total = cost + commission;
    // output all the things
    printf("The total cost of %d shares at $%.2f per share is $%.2f for a total of $%.2f including a %.2f percent commission of $%.2f",
           shares, perShare, cost, total, fee * 100.0, commission);
}

/**
 * Expanded version that requires user to input values
 */
void anyone() {
    // init vars
    int shares;
    float perShare, cost, fee, commission, total;
    // assign user input to vars
    cout << "How many shares?\n";
    cin >> shares;
    cout << "Per share cost?\n";
    cin >> perShare;
    cout << "Percent commission?\n";
    cin >> fee;
    // convert fee into percent decimal
    fee /= 100;
    // calculations
    cost = shares * perShare;
    commission = cost * fee;
    total = cost + commission;
    // output all the things
    printf("The total cost of %d shares at $%.2f per share is $%.2f for a total of $%.2f including a %.2f percent commission of $%.2f",
           shares, perShare, cost, total, fee * 100.0, commission);
}

int main() {
    kathryn(750, 35);
//    anyone();

    return 0;
}
