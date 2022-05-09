#ifndef BUDGETAPP_H
#define BUDGETAPP_H


#include <iostream>
#include "UserManager.h"



using namespace std;


class BudgetApp {

   UserManager userManager;
   // ItemMenager *itemMenager;

  // AdresatMenedzer *adresatMenedzer; // nie mamy danych do tej klasy od razu dlatego tworzymy wskaŸnik
   const string FILE_NAME_WITH_USERS;

public:
        BudgetApp(string fileNameWithUsers/*, string FileNameWithIncomes, string FileNameWithExpenses*/)
    : userManager(fileNameWithUsers)/*, FILE_NAME_WITH_INCOMES(FileNameWithIncomes), FILE_NAME_WITH_EXPENSES (FileNameWithExpenses) */{
       // itemMenager = NULL;
    }
        //(string fileNameWithUsers/*, string fileNameWithIncomes, string fileNameWithExpenses*/): userManager(fileNameWithUsers);/*, NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami),NAZWA_TYMCZASOWEGO_PLIKU_Z_ADRESATAMI(nazwaTymczasowegoPlikuZAdresatami*/)
 //   { /*
        //adresatMenedzer = NULL; // jezeli pracujemy na wskazniku to ustawiamy w klasie gdzie go tworzymy NULL
          //itemMenager = NULL;*/
  //  };

   /* ~BudgetApp() {
        delete itemMenager;
        itemMenager = NULL;
    };

    ~KsiazkaAdresowa() // rowniez nalezy stworzyc destruktor, sprzata po danej klasie
    {
        delete adresatMenedzer;
        adresatMenedzer = NULL;
    };*/

    void registerUser();
    void showAllUsers();
   // int userLogIn();
    void logOffUser();
    bool isUserLoggedIn();
    char selectOptionFromMainMenu();
    char selectOptionFromUserMenu();
   // void addIncome();
    // void addExpense();

};

#endif
