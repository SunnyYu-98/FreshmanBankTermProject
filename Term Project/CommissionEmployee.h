//  CommissionEmployee.h
//  Term Project
//  Created by Sunny Irving Yu on 4/15/17.
//  Copyright © 2017 Sunny Irving Yu. All rights reserved.

#ifndef COMMISSIONEMPLOYEE_h
#define COMMISSIONEMPLOYEE_h
#include "Employee.h"
#include <iostream>
using namespace std;
class CommissionEmployee : public Employee
{
protected:
    double commissionRate;
    double grossSales;
public:
    //CommissionEmployee();
    CommissionEmployee(double c=0.0, double g=0, string eName="", string sNo="", list<BankAccount *> a={nullptr});
    virtual void setComRate(double);
    virtual void setGroSales(double);
    double getCommissionRate() const;
    double getGrossSales() const;
    virtual double earnings();
    virtual void print();    
    
};

#endif /* CommissionEmployee_h */
