 #include <iostream>

 #include "BudgetApp.h"
 #include "AuxiliaryMethods.h"
 #include "User.h"

using namespace std;

void BudgetApp :: registerUser() {

    userManager.registerUser();
}

bool BudgetApp :: isUserLoggedIn() {

    userManager.isUserLoggedIn();
}

//void BudgetApp :: showAllUsers() {

//    userManager.showAllUsers();
//}

void BudgetApp :: logOffUser() {

    userManager.logOffUser();
    delete itemManager;
    itemManager = NULL;
}

char BudgetApp :: selectOptionFromMainMenu() {

    char option;

    system("cls");
    cout << "    >>> MAIN MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Registration" << endl;
    cout << "2. Login" << endl;
    cout << "9. End" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    option = AuxiliaryMethod::getChar();

    return option;
}

char BudgetApp :: selectOptionFromUserMenu() {

    userManager.selectOptionFromUserMenu();
}

void BudgetApp :: userLogIn() {

     userManager.userLogIn();
         if(userManager.isUserLoggedIn())
         {
             itemManager = new ItemManager (FILE_NAME_WITH_INCOMES, FILE_NAME_WITH_EXPENSES, userManager.getIdLoggedUser());

         }
}

void BudgetApp :: addIncome() {

    if (userManager.isUserLoggedIn()) {
        itemManager->addIncome();
    } else {
        cout << "You need to login " << endl;
        system ("pause");
    }
}

void BudgetApp :: changePassword() {

    userManager.changePassword();
}

void BudgetApp :: addExpense() {

    if (userManager.isUserLoggedIn()) {
        itemManager->addExpense();
    } else {
        cout << "You need to login " << endl;
        system ("pause");
    }
}

void BudgetApp::viewAllExpenses() {

    itemManager->viewAllExpenses();
}

void BudgetApp :: viewCurrentMonthBalance() {

    itemManager-> viewCurrentMonthBalance();
}

void BudgetApp :: viewLastMonthBalance() {

    itemManager-> viewLastMonthBalance();
}

void BudgetApp :: viewBalanceOfSelectedPeriod() {

    itemManager-> viewBalanceOfSelectedPeriod();
}
