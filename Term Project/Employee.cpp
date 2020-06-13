//  Employee.cpp
//  Term Project
//  Created by Sunny Irving Yu on 4/24/17.
//  Copyright © 2017 Sunny Irving Yu. All rights reserved.

#include "Employee.h"
Employee::Employee(string eName, string sNo, list<BankAccount *> a)
{
    name = eName;
    ssn = sNo;
    accounts = a;
}
list<BankAccount *>::iterator Employee::getIterBegin()
{
    return accounts.begin();
}
list<BankAccount *>::iterator Employee::getIterEnd()
{
    return accounts.end();
}
void Employee::setName(string eName)
{
    name = eName;
}
string Employee::getName() const
{
    return name;
    
    
    //Has issue here after adding a customer mannuelly.
    
    
    
}
void Employee::setSsn(string sNo)
{
    ssn = sNo;
}
string Employee::getSsn() const
{
    return ssn;
}
unsigned long int Employee::getNumOfAccounts()
{
    numOfAccounts = accounts.size();
    return numOfAccounts;
}
list<BankAccount *> Employee::getAccounts() const
{
    return accounts;
}
void Employee::addAccount(BankAccount * newAcc_ptr)
{
    accounts.push_back(newAcc_ptr);
}
/*
string * Employee::getAccountTypesArray()
{
    int i = 0;
    const int SIZE = 7;
    string types[SIZE];
    list<BankAccount *>::iterator it;
    for (it = getIterBegin(); it != getIterEnd(); ++it)
    {
        types[i] = ((*it)->BankAccount::getAccountType());
        i++;
    }
    string *arrPtr = types;
    return arrPtr;
}
*/
