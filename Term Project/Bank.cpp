//  Bank.cpp
//  Term Project
//  Created by Sunny Irving Yu on 4/24/17.
//  Copyright © 2017 Sunny Irving Yu. All rights reserved.

#include "Bank.h"
Bank::Bank()
{
    name = "Bank Of Applers";
    customers = {nullptr};
    iter1 = customers.begin();
    iter2 = customers.end();
}
Bank::Bank(list<Employee *> c)
{
    customers = c;
    iter1 = customers.begin();
    iter2 = customers.end();
}
void Bank::setName(string n)
{
    name = n;
}
string Bank::getName()
{
    return name;
}
unsigned long int Bank::getCusListSize()
{
    return customers.size();
}
bool Bank::compare_name(const Employee *first, const Employee *second)
{
    return first->getName() > second->getName();
}
bool Bank::compare_balance(Employee *first, Employee *second)
{
    list<BankAccount *>::iterator itS = first->getIterBegin();
    itS++;
    list<BankAccount *>::iterator itB = first->getIterBegin();
    
    return ((*itB)->getTotalBalance() > (*itS)->getTotalBalance());
}
void Bank::sortByName()
{
    customers.sort(compare_name);
}
void Bank::sortByTotalDeposit()
{
    customers.sort(compare_balance);
}
void Bank::listCustomers(int choice)
{
    int i = 1;
    switch(choice)
    {
        case 1: sortByName();
        {
            for(iter1 = customers.begin(); iter1 != customers.end(); ++iter1)
            {
                cout << i << ". " << (*iter1)->getName() << endl;
                i++;
            }
            break;
        }
        case 2: sortByTotalDeposit();
        {
            
            for(iter1 = customers.begin(); iter1 != customers.end(); ++iter1)
            {
                list<BankAccount *>::iterator iB;// = (*iter1)->getIterBegin();
                list<BankAccount *>::iterator iE = (*iter1)->getIterEnd();
                for(iB = (*iter1)->getIterBegin(); iB != iE; ++iB)
                {
                    cout << i << ". " << (*iter1)->getName() << endl;
                    cout << (*iB)->getAccountType() << ", total balance: " << (*iB)->getTotalBalance() << endl << endl;
                    i++;
                }
            }
            break;
        }
    }
}
void Bank::addCustomer(Employee * emp_ptr)
{
    customers.push_back(emp_ptr);
}






