#ifndef BUDGETAPP_H
#define BUDGETAPP_H


#include <iostream>
#include "UserManager.h"



using namespace std;


class BudgetApp {

   UserManager userManager;
  // AdresatMenedzer *adresatMenedzer; // nie mamy danych do tej klasy od razu dlatego tworzymy wskaŸnik
   const string FILE_NAME_WITH_USERS;

public:
        BudgetApp(string fileNameWithUsers/*, string FileNameWithIncomes, string FileNameWithExpenses*/)
    : userManager(fileNameWithUsers)/*, FILE_NAME_WITH_INCOMES(FileNameWithIncomes), FILE_NAME_WITH_EXPENSES (FileNameWithExpenses) */{

    }
       // { /*
        //adresatMenedzer = NULL; // jezeli pracujemy na wskazniku to ustawiamy w klasie gdzie go tworzymy NULL

  //  };

   /* ~KsiazkaAdresowa() // rowniez nalezy stworzyc destruktor, sprzata po danej klasie
    {
        delete adresatMenedzer;
        adresatMenedzer = NULL;
    };*/

    void registerUser();
    void showAllUsers();
    void userLogIn();
    void logOffUser();
    bool isUserLoggedIn();
    char selectOptionFromMainMenu();
    char selectOptionFromUserMenu();
    void addIncome();
    // void addExpense();

};

#endif
