//  SalariedCommission.cpp
//  Term Project
//  Created by Sunny Irving Yu on 4/24/17.
//  Copyright © 2017 Sunny Irving Yu. All rights reserved.
#include "Employee.h"
#include "SalariedEmployee.h"
#include "CommissionEmployee.h"
#include "SalariedCommission.h"
SalariedCommission::SalariedCommission(double cRate, double gSales, double s, string eName, string sNo, list<BankAccount *> a) : SalariedEmployee(s, eName, sNo, a) , CommissionEmployee(cRate, gSales, eName, sNo, a)
{
   // commissionRate = cRate;
   // grossSales = gSales;
   // salary = s;
}
void SalariedCommission::setGroSales(double groSale)
{
    CommissionEmployee::setGroSales(groSale);
}
void SalariedCommission::setComRate(double co)
{
    CommissionEmployee::setComRate(co);
}
void SalariedCommission::setSalary(double sal)
{
    SalariedEmployee::setSalary(sal);
}
double SalariedCommission::earnings()
{
    double earning_salar_comm = 0.0;
    earning_salar_comm = SalariedEmployee::getSalary() + (CommissionEmployee::getCommissionRate() * CommissionEmployee::getGrossSales());
    
    return earning_salar_comm;
}
void SalariedCommission::print()
{
    cout << endl;
    cout << "Employee's name: " << SalariedEmployee::getName() << endl;
    cout << "Social Security Number: " << SalariedEmployee::getSsn() << endl;
    cout << "Earnings: " << earnings() << endl << endl;
    cout << "Employee's Bank Accout Information: " << endl;
    cout << "----------------------------------------------------\n";
    cout << SalariedEmployee::getName() << " has " << SalariedEmployee::getNumOfAccounts() << " accounts.\n";
    list<BankAccount *>::iterator iter;
    
    int i = 1;
    for(iter = SalariedEmployee::getIterBegin(); iter != SalariedEmployee::getIterEnd(); ++iter)
    {
        cout << i << ". " << (*iter)->getAccountType() << ": Total Balance: ";
        cout << (*iter)->getTotalBalance() << endl;
        i++;
    }
    cout << endl << endl;
    //Make a fuction in Employee that prints the Bank Account Info?

}
