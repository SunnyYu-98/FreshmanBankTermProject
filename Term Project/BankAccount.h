//  BankAccount.h
//  Term Project
//  Created by Sunny Irving Yu on 4/24/17.
//  Copyright © 2017 Sunny Irving Yu. All rights reserved.

#ifndef BANKACCOUNT_h
#define BANKACCOUNT_h
#include <iostream>
using namespace std;
class BankAccount
{
protected:
    double totalBalance;
    int numOfDeposit;
    int numOfWithdraws;
    double annualInterestRate;
    double monthlyServiceCharge;
    string accountType;
public:
    class InactiveAccount
    {
    public:
        InactiveAccount(){}
    };
    class InsufficientFund
    {
    public:
        InsufficientFund(){}
    };
    BankAccount();
    BankAccount(double, double);
    void increNumWithdraw();
    void increNumDeposit();
    void calcInt(); //make it virtual like the book says?
    double getTotalBalance();
    virtual void deposit(double);
    virtual void withDraw(double);
    virtual void monthlyProcess();
    virtual string getAccountType();
};


#endif /* BankAccount_h */
