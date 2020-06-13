//  CheckingAccount.h
//  Term Project
//  Created by Sunny Irving Yu on 4/24/17.
//  Copyright © 2017 Sunny Irving Yu. All rights reserved.

#ifndef CHECKINGACCOUNT_h
#define CHECKINGACCOUNT_h
using namespace std;
class CheckingAccount : public BankAccount
{
public:
    CheckingAccount();
    CheckingAccount(double, double); //balance, annual interest rate
    //void deposit(double); not on the book
    void deposit(double);
    void withdraw(double);
    void monthlyProcess();
    string getAccountType();
};
#endif /* CheckingAccount_h */
