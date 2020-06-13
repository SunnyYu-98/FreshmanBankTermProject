//  SalariedEmployee.cpp
//  Term Project
//  Created by Sunny Irving Yu on 4/24/17.
//  Copyright © 2017 Sunny Irving Yu. All rights reserved.

#include "Employee.h"
#include "SalariedEmployee.h"
SalariedEmployee::SalariedEmployee(double s, string eName, string sNo, list<BankAccount *> a) : Employee(eName, sNo, a)
{
    salary = s;
}
double SalariedEmployee::earnings()
{
    double earning_weeklySalaried = salary/52;
    return earning_weeklySalaried;
}
void SalariedEmployee::setSalary(double sa)
{
    salary = sa;
}
double SalariedEmployee::getSalary() const
{
    return salary;
}
void SalariedEmployee::print()
{
    cout << endl;
    cout << "Employee's name: " << getName() << endl;
    cout << "Social Security Number: " << getSsn() << endl;
    cout << "Earnings: " << earnings() << endl << endl;
    cout << "Employee's Bank Accout Information: " << endl;
    cout << "----------------------------------------------------\n";
    cout << getName() << " has " << getNumOfAccounts() << " accounts.\n";
    list<BankAccount *>::iterator iter;
    
    int i = 1;
    for(iter = getIterBegin(); iter != getIterEnd(); ++iter)
    {
        cout << i << ". " << (*iter)->getAccountType() << ": Total Balance: ";
        cout << (*iter)->getTotalBalance() << endl;
        i++;
    }
    cout << endl << endl;
    //Make a fuction in Employee that prints the Bank Account Info?
}
