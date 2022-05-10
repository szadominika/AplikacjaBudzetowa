 #include <iostream>
 #include "BudgetApp.h"
 #include "AuxiliaryMethods.h"
 #include "User.h"

using namespace std;

void BudgetApp::registerUser()
{
    userManager.registerUser();
}

bool BudgetApp::isUserLoggedIn()
{
    userManager.isUserLoggedIn();
}

void BudgetApp :: showAllUsers() {

    userManager.showAllUsers();
}

void BudgetApp :: logOffUser(){

    userManager.logOffUser();
    //delete itemMenager;
    //itemMenager = NULL;
}

char BudgetApp::selectOptionFromMainMenu()
{
    AuxiliaryMethod auxiliaryMethod;
    char option;

    system("cls");
    cout << "    >>> MAIN MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Registration" << endl;
    cout << "2. Login" << endl;
    cout << "9. End" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    option = auxiliaryMethod.getChar();

    return option;
}

char BudgetApp::selectOptionFromUserMenu() {

    userManager.selectOptionFromUserMenu();
}


void BudgetApp::userLogIn() {

     userManager.userLogIn();
         if(userManager.isUserLoggedIn())
         {
            // adresatMenedzer = new AdresatMenedzer(NAZWA_PLIKU_Z_ADRESATAMI,NAZWA_TYMCZASOWEGO_PLIKU_Z_ADRESATAMI,uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
         }
}


/*void BudgetApp :: addIncome() {

    if (userMenager.ifUserIsLogged()) {
        itemMenager->addIncome();
    } else {

        cout << "You need to login " << endl;
        system ("pause");
    }
}

void BudgetApp :: addExpense() {

    if (userMenager.ifUserIsLogged()) {
        itemMenager->addExpense();
    } else {

        cout << "You need to login " << endl;
        system ("pause");
    }
}*/
