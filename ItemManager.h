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
    float sumOfIncomes;
    float sumOfExpenses;
    Expense provideExpenseDetails();
    Income provideIncomeDetails();
    void viewIncome(vector <Income>::iterator itr);
    void viewExpense(vector <Expense>::iterator itr);
    void sortByDateIncomes();
    void sortByDateExpenses();
    void viewSelectedIncomes(int fromDate, int toDate);
    void viewSelectedExpenses(int FromDate, int ToDate);
    void sumUpIncomes(vector <Income>::iterator itr);
    void sumUpExpenses(vector <Expense>::iterator itr);

public:
    ItemManager (string fileNameWithIncomes, string fileNameWithExpenses, int idLoggedUser) :
        fileWithIncomes (fileNameWithIncomes), fileWithExpenses (fileNameWithExpenses), ID_LOGGED_USER(idLoggedUser) {
        sumOfIncomes = 0;
        sumOfExpenses = 0;
        incomes = fileWithIncomes.getIncomeFromFile(ID_LOGGED_USER);
        expenses = fileWithExpenses.getExpenseFromFile(ID_LOGGED_USER);

    };

    void addIncome();
    void addExpense();
    void showBalanceForCurrentMonth();
    void showBalanceForLastMonth();
    void showBalanceForSelectedPeriod();
    void viewAllExpenses();
};
#endif
