//  HourlyEmployee.cpp
//  Term Project
//  Created by Sunny Irving Yu on 4/24/17.
//  Copyright © 2017 Sunny Irving Yu. All rights reserved.

#include "Employee.h"
#include "HourlyEmployee.h"
HourlyEmployee::HourlyEmployee(double h, double w, string eName, string sNo, list<BankAccount *> a) : Employee(eName, sNo, a)
{
    hours = h;
    wage = w;
}
double HourlyEmployee::earnings()
{
    double earning_hourly = 0.0;
    if (hours <= 40)
        earning_hourly = wage * hours;
    else
        earning_hourly = (40 * wage) + ((hours - 40) * wage * 1.5);
    
    return earning_hourly;
}
void HourlyEmployee::setWage(double wa)
{
    wage = wa;
}
void HourlyEmployee::setHours(double ho)
{
    hours = ho;
}

void HourlyEmployee::print()
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
