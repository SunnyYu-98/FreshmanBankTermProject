//  Menu.h
//  Term Project
//  Created by Sunny Irving Yu on 5/9/17.
//  Copyright © 2017 Sunny Irving Yu. All rights reserved.

#ifndef Menu_h
#define Menu_h
#include "Employee.h"
#include "HourlyEmployee.h"
#include "SalariedEmployee.h"
#include "CommissionEmployee.h"
#include "SalariedCommission.h"
#include "Bank.h"
#include "BankAccount.h"
#include "SavingAccount.h"
#include "CheckingAccount.h"
#include <list>
#include <iostream>
#include <string>
using namespace std;

class Menu
{
private:
    const double MINBALANCE = 25;
    void printMenu();
    void enterPositive();
    void showEmployeeTypes();
    void printEmployees(list<Employee *>);
    void option1(Bank); //List all customers
    void option2(list<Employee *>); //List all customers' information
    void option3(Bank &, list<Employee *> &);//Add customer
    void option4(list<Employee *> &, Bank &); //Add account
    void option5(list<Employee *> &, Bank &); //Account actions
    void pressEnter();
public:
    void getUserOption(Bank &, list<Employee *> &);
};





#endif /* Menu_h */
