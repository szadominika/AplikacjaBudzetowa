 #include <iostream>

 #include "BudgetApp.h"

using namespace std;

int main()
{
    BudgetApp budgetApp("Users.xml", "Incomes.xml", "Expenses.xml");
   // budgetApp.showAllUsers();
    // system("pause");
    char option = 0;

    while (true)
    {

        if (!budgetApp.isUserLoggedIn())
        {
           option = budgetApp.selectOptionFromMainMenu();

            switch (option)
            {
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
                cout << endl << "There is no such option in the menu." << endl << endl;
                system("pause");
                break;
            }
        }
       else {

            option = budgetApp.selectOptionFromUserMenu();
            switch (option)
            {
            case '1':
                budgetApp.addIncome();
                break;
            case '2':
               //budgetApp.addExpense();
                break;
            case '3':
               // budgetApp.viewCurrentMonthBalance();
                break;
            case '4':
               // budgetApp.viewLastMonthBalance();
                break;
            case '5':
                //budgetApp..viewBalanceOfSelectedPeriod();
                break;
            case '6':
               // budgetApp.changePassword();
                break;
            case '7':
               budgetApp.logOffUser();
                break;
            }
        }
    }

    return 0;
}


