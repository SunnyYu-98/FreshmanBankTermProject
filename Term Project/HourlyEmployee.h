//  HourlyEmployee.h
//  Term Project
//  Created by Sunny Irving Yu on 4/15/17.
//  Copyright © 2017 Sunny Irving Yu. All rights reserved.

#ifndef HOURLYEMPLOYEE_h
#define HOURLYEMPLOYEE_h
#include "Employee.h"
#include "BankAccount.h"
#include<list>
#include <iostream>
#include <string>
using namespace std;

class HourlyEmployee : public Employee
{
private:
    double hours;
    double wage;
    double earning;
public:
    //HourlyEmployee();
    HourlyEmployee(double h=0, double w=0.0, string eName="", string sNo="", list<BankAccount *> a={nullptr});
    double earnings();
    void setHours(double);
    void setWage(double);
    void print();
};

#endif /* HourlyEmployee_h */
