//  CheckingAccount.cpp
//  Term Project
//  Created by Sunny Irving Yu on 4/24/17.
//  Copyright © 2017 Sunny Irving Yu. All rights reserved.

#include "BankAccount.h"
#include "CheckingAccount.h"
CheckingAccount::CheckingAccount() : BankAccount()
{
    accountType = "Checking Account";
}
CheckingAccount::CheckingAccount(double b, double aRate) : BankAccount(b, aRate)
{
    totalBalance = b;
    accountType = "Checking Account";
}

void CheckingAccount::deposit(double num_d)
{
    totalBalance +=num_d;
    numOfDeposit++;
}
void CheckingAccount::withdraw(double num_w)
{
    if (totalBalance - num_w < 0)
    {
        monthlyServiceCharge += 15;
        throw InsufficientFund();
    }
    else
        BankAccount::withDraw(num_w);
}
void CheckingAccount::monthlyProcess()
{
    monthlyServiceCharge +=5;
    monthlyServiceCharge += (0.10*numOfWithdraws);
    BankAccount::monthlyProcess();
}
string CheckingAccount::getAccountType()
{
    return accountType;
}
