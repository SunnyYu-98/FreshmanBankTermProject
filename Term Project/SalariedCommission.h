//  SalariedCommission.h
//  Term Project
//  Created by Sunny Irving Yu on 4/24/17.
//  Copyright © 2017 Sunny Irving Yu. All rights reserved.

#ifndef SALARIEDCOMMISSION_h
#define SALARIEDCOMMISSION_h
#include "SalariedEmployee.h"
#include "CommissionEmployee.h"
#include <iostream>
using namespace std;
class SalariedCommission : public SalariedEmployee, public CommissionEmployee
{
public:
    SalariedCommission(double cRate=0.0, double gSales=0.0, double s=0.0, string eName="", string sNo="", list<BankAccount *> a={nullptr});
    void setSalary(double);
    void setComRate(double);
    void setGroSales(double);
    double earnings();
    void print();
};



#endif /* SalariedCommission_h */
