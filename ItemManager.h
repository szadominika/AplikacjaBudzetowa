#ifndef ITEMMANAGER_H
#define ITEMMANAGER_H

#include <iostream>
#include <vector>
#include <string>

#include "Item.h"
#include "User.h"
#include "UserManager.h"
#include "DataManager.h"
#include "FileWithIncomes.h"

using namespace std;

class ItemManager : public Item {

    const int ID_LOGGED_USER;
    vector <Item> incomes;
    FileWithIncomes fileWithIncomes;

    Item provideIncomeDetails();
    int getNewIncomeId();

public:
    ItemManager (string fileNameWithIncomes, /*string fileNameWithExpenses, */int idLoggedUser) :
        fileWithIncomes (fileNameWithIncomes)/*,expenseFile (fileNameWithExpenses)*/,ID_LOGGED_USER(idLoggedUser){
    incomes = fileWithIncomes.getIncomeFromFile(ID_LOGGED_USER);
    };

    void addIncome();
    bool provideDate();
    void showAllIncomes();

};
#endif
