 #include <iostream>

 #include "BudgetApp.h"
 #include "AuxiliaryMethods.h"
 #include "User.h"

using namespace std;

void BudgetApp :: registerUser() {
    userManager.registerUser();
    userManager.logOutUser();
}

bool BudgetApp :: isUserLoggedIn() {
    userManager.isUserLoggedIn();
}

void BudgetApp :: logOutUser() {
    userManager.logOutUser();
    delete itemManager;
    itemManager = NULL;
}

char BudgetApp :: selectOptionFromMainMenu() {
    userManager.selectOptionFromMainMenu();
}

char BudgetApp :: selectOptionFromUserMenu() {
    userManager.selectOptionFromUserMenu();
}

void BudgetApp :: userLogIn() {
     userManager.userLogIn();
         if(userManager.isUserLoggedIn()) {
             itemManager = new ItemManager (FILE_NAME_WITH_INCOMES, FILE_NAME_WITH_EXPENSES, userManager.getLoggedInUserID());
         }
}

void BudgetApp :: addIncome() {
    if (userManager.isUserLoggedIn()) {
        itemManager->addIncome();
    }
}

void BudgetApp :: changePassword() {
    userManager.changePassword();
}

void BudgetApp :: addExpense() {
    if (userManager.isUserLoggedIn()) {
        itemManager->addExpense();
    }
}

void BudgetApp :: showBalanceForCurrentMonth() {
    itemManager-> showBalanceForCurrentMonth();
}

void BudgetApp :: showBalanceForLastMonth() {
    itemManager-> showBalanceForLastMonth();
}

void BudgetApp :: showBalanceForSelectedPeriod() {
    itemManager-> showBalanceForSelectedPeriod();
}
