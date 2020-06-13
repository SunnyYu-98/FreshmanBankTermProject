//  Bank.h
//  Term Project
//  Created by Sunny Irving Yu on 4/24/17.
//  Copyright © 2017 Sunny Irving Yu. All rights reserved.

#ifndef BANK_h
#define BANK_h
#include "Employee.h"
#include "HourlyEmployee.h"
#include "SalariedEmployee.h"
#include "CommissionEmployee.h"
#include "SalariedCommission.h"
#include "BankAccount.h"
#include <list>
#include <cctype>
#include <string>
using namespace std;

class Bank
{
protected:
    string name;
    list<Employee *> customers;
    list<Employee *>::iterator iter1, iter2;
    static bool compare_name(const Employee *, const Employee *);
    static bool compare_balance(Employee *, Employee *);
public:
    Bank();
    Bank(list<Employee *>);
    void setName(string);
    string getName();
    unsigned long int getCusListSize();
    void sortByName();
    void sortByTotalDeposit();
    void addCustomer(Employee *); 
    void listCustomers(int);
};

#endif /* Bank_h */
