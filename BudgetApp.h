#ifndef BUDGETAPP_H
#define BUDGETAPP_H

#include <iostream>

#include "UserManager.h"
#include "ItemManager.h"

using namespace std;

class BudgetApp {

   UserManager userManager;
   ItemManager *itemManager; // nie mamy danych do tej klasy od razu dlatego tworzymy wskaŸnik

   const string FILE_NAME_WITH_USERS;
   const string FILE_NAME_WITH_INCOMES;
   const string FILE_NAME_WITH_EXPENSES;

public:
    BudgetApp(string fileNameWithUsers, string FileNameWithIncomes, string FileNameWithExpenses)
    : userManager(fileNameWithUsers), FILE_NAME_WITH_INCOMES(FileNameWithIncomes), FILE_NAME_WITH_EXPENSES (FileNameWithExpenses){

        itemManager = NULL; // jezeli pracujemy na wskazniku to ustawiamy w klasie gdzie go tworzymy NULL
    }

    ~BudgetApp()  {// rowniez nalezy stworzyc destruktor, sprzata po danej klasie

        delete itemManager;
        itemManager = NULL;
    };

    void registerUser();
    void userLogIn();
    void logOutUser();
    bool isUserLoggedIn();
    void changePassword();

    char selectOptionFromMainMenu();
    char selectOptionFromUserMenu();

    void addIncome();
    void addExpense();
    void showBalanceForCurrentMonth();
    void showBalanceForLastMonth();
    void showBalanceForSelectedPeriod();
   // void viewAllExpenses();
    //void showAllUsers();

};

#endif
