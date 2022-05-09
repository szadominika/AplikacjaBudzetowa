 #include <iostream>
 #include "BudgetApp.h"

using namespace std;

int main()
{
    BudgetApp budgetApp("Users.xml"/*, "Incomes.xml", "Expenses.xml"*/);
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
               // budgetApp.logowanieUzytkownika();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
       else {

            option = budgetApp.selectOptionFromUserMenu();
           /* switch (wybor)
            {
            case '1':
                budgetApp.dodajAdresata();
                break;
            case '2':
                budgetApp.wyszukajAdresatowPoImieniu();
                break;
            case '3':
                ksiazkaAdresowa.wyszukajAdresatowPoNazwisku();
                break;
            case '4':
                ksiazkaAdresowa.wyswietlWszystkichAdresatow();
                break;
            case '5':
                ksiazkaAdresowa.usunAdresata();
                break;
            case '6':
                ksiazkaAdresowa.edytujAdresata();
                break;
            case '7':
               ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();
                break;
            case '8':
                ksiazkaAdresowa.wylogowanieUzytkownika();
                break;
            }*/
        }
    }

    return 0;
}


