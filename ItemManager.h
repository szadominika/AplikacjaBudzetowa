#ifndef ITEMMANAGER_H
#define ITEMMANAGER_H

#include <iostream>
#include <vector>
#include <string>

#include "Item.h"
#include "User.h"
#include "UserManager.h"
#include "Date.h"
#include "FileWithIncomes.h"
#include "FileWithExpenses.h"

using namespace std;

class ItemManager {

    const int ID_LOGGED_USER;
    vector <Income> incomes;
    vector <Expense> expenses;

    FileWithIncomes fileWithIncomes;
    FileWithExpenses fileWithExpenses;

    Date date;
    float totalIncome;
    // float totalExpense;

   // Expense provideIncomeDetails();
    Income provideIncomeDetails();

    void viewIncome(vector <Income>::iterator itr);
    //void viewExpense(vector <Expense>::iterator itr);
    //void sortIncomesByDate();
    //void sortExpensesByDate();
    //void viewSelectedIncome(int FromDate, int ToDate);
    //void viewSelectedExpenses(int FromDate, int ToDate);
    //void sumUpAllIncome(vector <Income>::iterator itr);
    //void sumUpAllExpenses(vector <Expenses>::iterator itr);

public:
    ItemManager (string fileNameWithIncomes, string fileNameWithExpenses, int idLoggedUser) :
        fileWithIncomes (fileNameWithIncomes), fileWithExpenses (fileNameWithExpenses), ID_LOGGED_USER(idLoggedUser) {

            totalIncome = 0;
            //totalExpense = 0;
        incomes = fileWithIncomes.getIncomeFromFile(ID_LOGGED_USER);
        //expenses = fileWithExpenses.getExpenseFromFile(ID_LOGGED_USER);
    };

    void addIncome();
   // void addExpense();
    //void viewCurrentMonthBalance();
    //void viewLastMonthBalance();
    //void viewBalanceOfSelectedPeriod();

    //bool provideDate();
    //void showAllIncomes(vector <Income>::iterator itr);
};
#endif
