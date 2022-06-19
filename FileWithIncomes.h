#ifndef FILEWITHINCOMES_H
#define FILEWITHINCOMES_H

#include <iostream>
#include <vector>
#include <cstdlib>

#include "Markup.h"
#include "XmlFile.h"
#include "Incomes.h"
#include "Item.h"
#include "AuxiliaryMethods.h"

using namespace std;

class FileWithIncomes : public XmlFile {

    string fileNameWithIncomes;
    int lastIncomeId;

    int getLastIncomeIdFromFile();

public:
    FileWithIncomes(string fileNameWithIncomes) : XmlFile(fileNameWithIncomes){

        lastIncomeId = getLastIncomeIdFromFile();
    };

    int getLastIncomeId();
    bool addIncomeToFile(Income income, Date date);
    vector <Income> getIncomeFromFile(int ID_LOGGED_USER);
};

#endif
