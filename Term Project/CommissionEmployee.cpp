//  CommissionEmployee.cpp
//  Term Project
//  Created by Sunny Irving Yu on 4/24/17.
//  Copyright © 2017 Sunny Irving Yu. All rights reserved.

#include "Employee.h"
#include "CommissionEmployee.h"
CommissionEmployee::CommissionEmployee(double c, double g, string eName, string sNo, list<BankAccount *> a) : Employee(eName, sNo, a)
{
    commissionRate = c;
    grossSales = g;
}
void CommissionEmployee::setComRate(double com)
{
    commissionRate = com;
}
void CommissionEmployee::setGroSales(double gro)
{
    grossSales = gro;
}
double CommissionEmployee::getGrossSales() const
{
    return grossSales;
}
double CommissionEmployee::getCommissionRate() const
{
    return commissionRate;
}
double CommissionEmployee::earnings()
{
    double earning_commissioned = commissionRate * grossSales;

    return earning_commissioned;
}
void CommissionEmployee::print()
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
