//  SavingAccount.h
//  Term Project
//  Created by Sunny Irving Yu on 4/24/17.
//  Copyright © 2017 Sunny Irving Yu. All rights reserved.

#ifndef SAVINGACCOUNT_h
#define SAVINGACCOUNT_h
using namespace std;
class SavingAccount : public BankAccount
{
private:
    bool status;
public:
    SavingAccount();
    SavingAccount(double, double);//balance, annual interest rate
    void updateStatus();
    void deposit(double);
    void withdraw(double);
    void calcInt();
    void monthlyProcess();
    string getAccountType();
};

#endif /* SavingAccount_h */
