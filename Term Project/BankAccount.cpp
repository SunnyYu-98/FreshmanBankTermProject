//  BankAccount.cpp
//  Term Project
//  Created by Sunny Irving Yu on 4/24/17.
//  Copyright © 2017 Sunny Irving Yu. All rights reserved.

#include "Bank.h"
#include "BankAccount.h"
BankAccount::BankAccount()
{
    totalBalance = 0.0;
    numOfDeposit = 0;
    numOfWithdraws = 0;
    annualInterestRate = 0.14;
    monthlyServiceCharge = 0.0;
    accountType = "Bank Account";
}
BankAccount::BankAccount(double b, double a)
{
    totalBalance = b;
    annualInterestRate = a;
    numOfDeposit = 0;
    numOfWithdraws = 0;
    monthlyServiceCharge = 0.0;
    accountType = "Bank Account";
}
void BankAccount::increNumWithdraw()
{
    numOfWithdraws++;
}
void BankAccount::increNumDeposit()
{
    numOfDeposit++;
}
void BankAccount::calcInt()
{
    double monthlyInterRate = annualInterestRate / 12;
    double monInterest = totalBalance * monthlyInterRate;
    totalBalance += monInterest;
}
double BankAccount::getTotalBalance()
{
    return totalBalance;
}
void BankAccount::deposit(double num)
{
    totalBalance += num;
    increNumDeposit();
}
void BankAccount::withDraw(double num)
{
    totalBalance -= num;
    increNumWithdraw();
}
void BankAccount::monthlyProcess()
{
    totalBalance -= monthlyServiceCharge;
    numOfDeposit = 0;
    numOfWithdraws = 0;
    monthlyServiceCharge = 0;
}
string BankAccount::getAccountType()
{
    return accountType;
}
