//  Employee.h
//  Term Project
//  Created by Sunny Irving Yu on 4/15/17.
//  Copyright © 2017 Sunny Irving Yu. All rights reserved.

#ifndef EMPLOYEE_h
#define EMPLOYEE_h
#include "BankAccount.h"
#include <iostream>
#include <string>
#include <list>  
#include <vector> // asdhlaldhsaljkdhasljkdhasklsdhklasd
using namespace std;
class Employee
{
protected:          //make it protected so the derived classes can access it.
    string name;
    string ssn;
    unsigned long int numOfAccounts;
    list<BankAccount *> accounts;
public:
    Employee(string eName = "", string sNo = "", list<BankAccount *> a = {nullptr});
    list<BankAccount *>::iterator getIterBegin();
    list<BankAccount *>::iterator getIterEnd();
    void setName(string eName);
    string getName() const;
    void setSsn(string sNo);
    string getSsn() const;
    unsigned long int getNumOfAccounts();
    list<BankAccount *> getAccounts() const;
    void addAccount(BankAccount *);
    //string * getAccountTypesArray();
    virtual double earnings() = 0;
    virtual void print() = 0;
};

#endif /* Employee_h */
