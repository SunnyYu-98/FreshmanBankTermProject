//  Menu.cpp
//  Term Project
//  Created by Sunny Irving Yu on 5/9/17.
//  Copyright © 2017 Sunny Irving Yu. All rights reserved.

#include "Menu.h"

void Menu::printMenu()
{
    system("clear");
    cout << "        \n";
    cout << "  Welcome to Bank of Applers \n";
    cout << "        \n";
    cout << "Choices of Actions:\n";
    cout << "1. List all customers\n";
    cout << "2. List all customers' information\n";
    cout << "3. Add customer\n";
    cout << "4. Add account\n";
    cout << "5. Account actions (deposit, withdraw)\n";
    cout << "6. Quit\n";
}
void Menu::enterPositive()
{
    cout << "Please enter a positive number:\n";
}
void Menu::showEmployeeTypes()
{
    cout << "1. Hourly Employee\n";
    cout << "2. Salaried Employee\n";
    cout << "3. Commission Employee\n";
    cout << "4. Salaried Commission Employee\n";
}
void Menu::printEmployees(list<Employee *> eList)
{
    int i = 1;
    system("clear");
    list<Employee *>::iterator emp_iter;
    for(emp_iter = eList.begin(); emp_iter != eList.end(); ++emp_iter)
    {
        cout << i << ". \n";
        (*emp_iter)->print();
        i++;
    }
}
void Menu::option1(Bank b) //List customers
{
    int c;
    system("clear"); //clear is for Apple users.
    cout << "1. List by name\n";
    cout << "2. List by balance\n";
    cout << "Option(1-2): ";
    cin >> c;
    cin.ignore();
    while (c < 1 || c > 2)
    {
        cout << "Please enter 1 or 2:\n";
        cin >> c;
        cin.ignore();
    }
    switch (c)    //1 is by name, 2 is by balance
    {
        case 1:
            system("clear");
            b.listCustomers(1);
            pressEnter();
            break;
        case 2:
            system("clear");
            b.listCustomers(2);
            pressEnter();
            break;
    }
    }
void Menu::option2(list<Employee *> eL) //List all customers' information
{
    printEmployees(eL);
    pressEnter();
}
void Menu::option3(Bank &b, list<Employee *> &eL) //Add customer
{
    system("clear");
    int type;
    int accountNum;
    showEmployeeTypes();
    cout << "What type of employee are you? (1-4)\n";
    cin >> type;
    cin.ignore();
    while (type > 4 || type < 1)
    {
        cout << "Please enter the number from 1 to 4\n";
        cin >> type;
        cin.ignore();
    }
    
    double hours_m, wage_m, salary_m, commissionRate_m, grossSales_m;
    string name_m, social_m;
    
    system("clear");
    cout << "Please enter your name: ";
    cin >> name_m;
    cin.ignore();
    cout << "\nPlease enter your social security number:";
    cin >> social_m;
    cin.ignore();
    cout << "How many accounts would you like to have?";
    cin >> accountNum;
    cin.ignore();
    while (accountNum < 0 || accountNum > 7)
    {
        cout << "Sorry, each customer can have a maximum of 7 accouts.\n";
        cout << "Please enter a positive number from 1 to 7.\n";
        cin>>accountNum;
        cin.ignore();
    }
    
    int accountType;
    double balance;
    double interestRate;
    list<BankAccount *> newAccount;
    for(int x=0; x < accountNum; x++)
    {
        system("clear");
        cout << "For account No. " << x+1 << ", do you want it to be a checking or saving account?\n";
        cout << "1.Checking\n2.Saving\n\nChoice:";
        cin >> accountType;
        cin.ignore();
        
        cout << "How much money do you want to put into this account?\n";
        cin >> balance;
        cin.ignore();
        while(balance < 0)
        {
            enterPositive();
            cin >> balance;
            cin.ignore();
        }
        cout << "What is the annual interest rate?\n";
        cin >> interestRate;
        cin.ignore();
        while(interestRate < 0)
        {
            enterPositive();
            cin >> interestRate;
            cin.ignore();
        }
        switch (accountType)
        {
            case 1:
                newAccount.push_back(new CheckingAccount(balance, interestRate));
                cout << "\nDone.\n";
                pressEnter();
                break;
            case 2:
                newAccount.push_back(new SavingAccount(balance, interestRate));
                cout << "\nDone.\n";
                pressEnter();
                break;
        }
    }
    switch (type)
    {
        case 1:
        {
            system("clear");
            cout << "How many hours do you work per month?\n";
            cin >> hours_m;
            cin.ignore();
            while(hours_m < 0 || hours_m > 672)
            {
                cout << "Please enter a range from 0 to 672:\n";
                cin >> hours_m;
                cin.ignore();
            }
            cout << "What is your wage?\n";
            cin >> wage_m;
            cin.ignore();
            while(wage_m < 0)
            {
                enterPositive();
                cin >> wage_m;
                cin.ignore();
            }
            eL.push_back(new HourlyEmployee(hours_m, wage_m, name_m, social_m, newAccount));
            b.addCustomer((*eL.end()));
            cout << "Done\n";
            pressEnter();
            break;
        }
        case 2:
        {
            system("clear");
            cout << "What is your salary? \n";
            cin >> salary_m;
            cin.ignore();
            while(salary_m < 0)
            {
                enterPositive();
                cin >> salary_m;
                cin.ignore();
            }
            eL.push_back(new SalariedEmployee(salary_m, name_m, social_m, newAccount));
            b.addCustomer((*eL.end()));
            cout << "Done\n";
            pressEnter();
            break;
        }
        case 3:
        {
            system("clear");
            cout << "What is your commission rate?\n";
            cin >> commissionRate_m;
            cin.ignore();
            while(commissionRate_m < 0)
            {
                enterPositive();
                cin >> commissionRate_m;
                cin.ignore();
            }
            cout << "What is your gross sales?\n";
            cin >> grossSales_m;
            cin.ignore();
            while (grossSales_m < 0)
            {
                enterPositive();
                cin >> grossSales_m;
                cin.ignore();
            }
            eL.push_back(new CommissionEmployee(commissionRate_m, grossSales_m, name_m, social_m, newAccount));
            b.addCustomer((*eL.end()));
            cout << "Done\n";
            pressEnter();
            break;
        }
        case 4:
        {
            system("clear");
            cout << "What is your salary? \n";
            cin >> salary_m;
            cin.ignore();
            while(salary_m < 0)
            {
                enterPositive();
                cin >> salary_m;
                cin.ignore();
            }
            cout <<"What is your commission rate?\n";
            cin >> commissionRate_m;
            cin.ignore();
            while(commissionRate_m < 0)
            {
                enterPositive();
                cin >> commissionRate_m;
                cin.ignore();
            }
            cout << "What is your gross sales?\n";
            cin >> grossSales_m;
            cin.ignore();
            while (grossSales_m < 0)
            {
                enterPositive();
                cin >> grossSales_m;
                cin.ignore();
            }
            eL.push_back(new CommissionEmployee(SalariedCommission(commissionRate_m, grossSales_m, salary_m, name_m, social_m, newAccount)));
            b.addCustomer((*eL.end()));
            cout << "Done\n";
            pressEnter();
            break;
        }
    }
}
void Menu::option4(list<Employee *> &eL, Bank &b) //Add Account
{
    int user;
    system("clear");
    printEmployees(eL);
    cout << "Which one is you?\n";
    cin >> user;
    cin.ignore();
    while(user < 0 || user > eL.size())
    {
        cout << "Please input a number from 1 to " << eL.size() << endl;
        cin >> user;
        cin.ignore();
    }
    list<Employee *>::iterator iter = eL.begin();
    
    
    int accountType;
    double balance;
    double interestRate;
    system("clear");
    cout << "Do you want it to be a checking or saving account?\n";
    cout << "1.Checking\n2.Saving\n\nChoice:";
    cin >> accountType;
    cin.ignore();
    
    cout << "How much money do you want to put into this account?\n";
    cin >> balance;
    cin.ignore();
    
    while(balance < 0)
    {
        enterPositive();
        cin >> balance;
        cin.ignore();
    }
    cout << "What is the annual interest rate?\n";
    cin >> interestRate;
    cin.ignore();
    while(interestRate < 0)
    {
        enterPositive();
        cin >> interestRate;
        cin.ignore();
    }
    switch (accountType)
    {
        case 1:
            (*iter+(user-1))->addAccount(new CheckingAccount(balance, interestRate));
            cout << "\nDone.\n";
            pressEnter();
            break;
        case 2:
            (*iter+(user-1))->addAccount(new SavingAccount(balance, interestRate));
            cout << "\nDone.\n";
            pressEnter();
            break;
    }
    
}
void Menu::option5(list<Employee *> &eL, Bank &b)
{
    int o; //option of action (deposit/withdraw)
    int i = 1; //counter
    int t; //account choice
    int user;
    system("clear");
    printEmployees(eL);
    cout << "Which one is you?\n";
    cin >> user;
    cin.ignore();
    while(user < 0 || user > eL.size())
    {
        cout << "Please input a number from 1 to " << eL.size() << endl;
        cin >> user;
        cin.ignore();
    }
    system("clear");
    list<Employee *>::iterator empIT = eL.begin();
    list<BankAccount *> theAccounts = (*empIT + (user-1))->getAccounts();
    list<BankAccount *>::iterator accountsIT = theAccounts.begin();
    unsigned long int accountSize = theAccounts.size();
    for(accountsIT = theAccounts.begin(); accountsIT !=theAccounts.end(); ++accountsIT)
    {
        cout << i << ". " << (*accountsIT)->getAccountType() << ": " << (*accountsIT)->getTotalBalance() << endl;
        i++;
    }
    cout << "Which account do you want to perform the action on?\n";
    cin >> t;
    cin.ignore();
    while (t < 1 || t > accountSize)
    {
        cout << "Please enter a number in range from 1 to " << accountSize << ": \n";
        cin >> t;
        cin.ignore();
    }
    system("clear");
    
    cout << "1. Deposit\n2.Withdraw\n\n";
    cout << "What action do you want to perform?\nChoice: \n";
    cin >> o;
    cin.ignore();
    while(o < 1 || o > 2)
    {
        cout << "Please enter 1 or 2: ";
        cin >> o;
        cin.ignore();
    }
    switch (o)
    {
        case 1:
        {
            system("clear");
            double num_d = 0.0;
            cout << "How much do you want to deposit?\n";
            cin >> num_d;
            cin.ignore();
            while(num_d < 0)
            {
                enterPositive();
                cin >> num_d;
                cin.ignore();
            }
            if ((*accountsIT+t)->getAccountType() == "Saving Account")
            {
                try
                {
                    (*accountsIT+t)->deposit(num_d);
                }
                catch (BankAccount::InactiveAccount obj)
                {
                    cout << "Sorry, $" << num_d << " is not enough to make you account active again.\n";
                    cout << "So therefore you cannot perform any action on this accout.\n";
                    pressEnter();
                }
                break;
            }
            else
            {
                (*accountsIT+t)->deposit(num_d);
                cout << "Done\n";
                pressEnter();
            }
            break;
        }
        case 2:
            system("clear");
            double num_w = 0.0;
            cout << "How much you want to withdraw?\n";
            cin >> num_w;
            cin.ignore();
            while (num_w < 0)
            {
                enterPositive();
                cin >> num_w;
                cin.ignore();
            }
            
            
            
            
            
            
            
            
            
            cout << "account type:" << ((*accountsIT+t)->getAccountType());
            // BAD ACCESS, RUN-TIME ERROR
            //make it t-1?
            
            
            
            
            
            
            
            
            
            if ((*accountsIT+t)->getAccountType() == "Saving Account")
            {
                try
                {
                    (*accountsIT+t)->withDraw(num_w);
                    cout << "Done\n";
                    pressEnter();
                }
                catch (BankAccount::InactiveAccount obj)
                {
                    cout << "Sorry, your account is currenetly inactive.\n";
                    cout << "So you cannot perform any action on it unless you deposit more money to make your balance more than $" << MINBALANCE << endl;
                    pressEnter();
                }
                catch(BankAccount::InsufficientFund obj)
                {
                    cout << "Sorry, you do not have sufficient fund to make this withdraw.\n";
                    pressEnter();
                }
            }
            break;
    }
}

void Menu::getUserOption(Bank &b, list<Employee *> &eL)
{
    int choice = 0; //In case user accidentally enter a character
    while (choice != 6)
    {
        printMenu();
        cout << "Please enter your choice of action: (1-6)\n";
        cin >> choice;
        cin.ignore();
        while (choice > 6 || choice < 1)
        {
            cout << "Please enter a number from 1 to 6:\n";
            cin >> choice;
            cin.ignore();
        }
        switch (choice)
        {
            case 1:
                option1(b);
                break;
            case 2:
                option2(eL);
                break;
            case 3:
                option3(b,eL);
                break;
            case 4:
                option4(eL, b);
                break;
            case 5:
                option5(eL, b);
                break;
            case 6:
                break;
        }
    }
}
void Menu::pressEnter()
{
    cout << "Press Enter to continue...\n";
    cin.ignore();
}
