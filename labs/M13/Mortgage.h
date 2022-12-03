//
// Created by Mark Chouinard on 12/3/22.
//
#ifndef M13_MORTGAGE_H
#define M13_MORTGAGE_H


class Mortgage {
private:
    int years, loanAmount, numPayments;
    double rate, payment, totalPayments;
public:
    Mortgage();
    Mortgage(int years, double rate, double amount );

    int getYears() const;

    int getNumPayments() const;

    double getRate() const;

    int getLoanAmount() const;

    double getPayment() const;

    void setYears(int years);

    void setRate(double rate);

    void setLoanAmount(double loanAmount);

    void calculateLoan();

    double totalPaid() const;

};


#endif //M13_MORTGAGE_H
