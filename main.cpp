 #include <iostream>

 #include "BudgetApp.h"
 #include <ctime>
#include <windows.h>

using namespace std;

int main() {
    setlocale(LC_ALL, "Polish");
    BudgetApp budgetApp("Users.xml", "Incomes.xml", "Expenses.xml");
    char option = 0;
    while (true) {
        if (!budgetApp.isUserLoggedIn()) {
           option = budgetApp.selectOptionFromMainMenu();

            switch (option) {
            case '1':
                budgetApp.registerUser();
                break;
            case '2':
                budgetApp.userLogIn();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji." << endl << endl;
                system("pause");
                break;
            }
        }
       else {
            option = budgetApp.selectOptionFromUserMenu();
            switch (option) {
            case '1':
                budgetApp.addIncome();
                break;
            case '2':
                budgetApp.addExpense();
                break;
            case '3':
                budgetApp.showBalanceForCurrentMonth();
                break;
            case '4':
                budgetApp.showBalanceForLastMonth();
                break;
            case '5':
                budgetApp.showBalanceForSelectedPeriod();
                break;
            case '6':
                budgetApp.changePassword();
                break;
            case '7':
               budgetApp.logOutUser();
                break;
            }
        }
    }
    return 0;
}


