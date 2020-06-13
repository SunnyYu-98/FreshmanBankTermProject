//  main.cpp
//  Term Project
//  Created by Sunny Irving Yu on 4/15/17.
//  Copyright © 2017 Sunny Irving Yu. All rights reserved.
#include <string>
#include <list>
#include <iostream>
#include "Bank.h"
#include "Employee.h"
#include "HourlyEmployee.h"
#include "SalariedEmployee.h"
#include "CommissionEmployee.h"
#include "SalariedCommissionEmployee.h"
#include "BankAccount.h"
#include "SavingAccount.h"
#include "CheckingAccount.h"
#include "Menu.h"
using namespace std;

int main()
{
    const double ANNUALINRESTRATE = 0.14;
    list<Employee *> emp_list;
    
    list<BankAccount *> emp_bankAccounts;
    emp_bankAccounts.push_back(new CheckingAccount(75000, ANNUALINRESTRATE));
    emp_bankAccounts.push_back(new SavingAccount(25000, ANNUALINRESTRATE));
    emp_list.push_back(new HourlyEmployee(40, 7.5, "1 Hourly Employee", "01928839", emp_bankAccounts));
    emp_list.push_back(new SalariedEmployee(70000, "1 Salaried Employee", "01828391", emp_bankAccounts));
    emp_list.push_back(new CommissionEmployee(0.8, 100000, "1 Commission Employee", "12193", emp_bankAccounts));
    emp_list.push_back(new CommissionEmployee(SalariedCommission(0.4, 50000, 65000, "1 Salaried Commissioned Employee", "391029", emp_bankAccounts))); //If i dont convert salariedCommission to Commission, it shows Ambigious convertion........
    
    Bank BankOfApplers(emp_list);
    Menu menu;
    menu.getUserOption(BankOfApplers, emp_list);

   
    return 0;
}
