//  SavingAccount.cpp
//  Term Project
//  Created by Sunny Irving Yu on 4/24/17.
//  Copyright © 2017 Sunny Irving Yu. All rights reserved.

#include "BankAccount.h"
#include "SavingAccount.h"
SavingAccount::SavingAccount() : BankAccount()
{
    status = true;
    accountType = "Saving Account";
    
    
    BankAccount::accountType = "Saving Account"; //just testing
    
    
    
    
    
}
SavingAccount::SavingAccount(double b, double anRate) : BankAccount(b, anRate)
{
    totalBalance = b;
    if (totalBalance < 25)
    {
        status = false;
    }
    accountType = "Saving Account";
}
void SavingAccount::updateStatus()
{
    if (totalBalance < 25.0)
        status = false;
    else
        status = true;
}
void SavingAccount::deposit(double n)
{
    updateStatus();
    if (!status)
    {
        if (totalBalance+n > 25)
        {
            status = true;
            BankAccount::deposit(n);
        }
        else
            throw InactiveAccount();
    }
    else
    {
        BankAccount::deposit(n);
    }
}
void SavingAccount::withdraw(double n)
{
    updateStatus();
    if (!status)
    {
        throw InactiveAccount();
    }
    else if (n > totalBalance)
    {
        throw InsufficientFund();
    }
    else
    {
        BankAccount::withDraw(n);
    }
}
void SavingAccount::monthlyProcess()
{
    if (numOfWithdraws > 4)
    {
        monthlyServiceCharge = int(numOfWithdraws/4);
        BankAccount::monthlyProcess();
        updateStatus();
        
    }
    else
        monthlyServiceCharge = 0;
    
}
string SavingAccount::getAccountType()
{
    return accountType;
}
