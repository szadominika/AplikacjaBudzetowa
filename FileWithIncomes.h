#ifndef FILEWITHINCOMES_H
#define FILEWITHINCOMES_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "Markup.h"
#include "TextFile.h"
#include "Item.h"
#include "AuxiliaryMethods.h"

using namespace std;

class FileWithIncomes:public XmlFile {

    string fileNameWithIncomes;
    int lastItemId;
    int idLoggedUser;
    vector <Item> incomes;

public:
    FileWithIncomes(string fileNameWithIncomes) : XmlFile(fileNameWithIncomes){
     //idLoggedUser = 0;
     //lastItemId = 0;
    };
    void addIncomeToFile(Item income);
    vector <Item> getIncomeFromFile(int idLoggedUser);
    Item changeIntDateFormat(Item income);
    //int getLastItemId();
};

#endif
