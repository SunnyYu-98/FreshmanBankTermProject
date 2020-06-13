//  SalariedEmployee.h
//  Term Project
//  Created by Sunny Irving Yu on 4/15/17.
//  Copyright © 2017 Sunny Irving Yu. All rights reserved.

#ifndef SALARIEDEMPLOYEE_h
#define SALARIEDEMPLOYEE_h
#include "Employee.h"
#include <iostream>
using namespace std;
class SalariedEmployee : public Employee
{
protected:
    double salary;
public:
    //SalariedEmployee();
    SalariedEmployee(double s=0.0, string eName="", string sNo="", list<BankAccount *> a={nullptr});
    virtual void setSalary(double);
    double getSalary() const;
    virtual double earnings();
    virtual void print();    
};


#endif /* SalariedEmployee_h */
