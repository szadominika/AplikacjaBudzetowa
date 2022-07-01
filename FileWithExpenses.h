#ifndef FILEWITHEXPENSES_H
#define FILEWITHEXPENSES_H

#include <iostream>
#include <vector>
#include <cstdlib>

#include "Markup.h"
#include "XmlFile.h"
#include "Expenses.h"
#include "AuxiliaryMethods.h"

using namespace std;

class FileWithExpenses : public XmlFile {

    string fileNameWithExpenses;
    int lastExpenseId;
    int getLastExpenseIdFromFile();

public:
    FileWithExpenses(string fileNameWithExpenses) : XmlFile(fileNameWithExpenses){

        lastExpenseId = getLastExpenseIdFromFile();
    };
    int getLastExpenseId();
    bool addExpenseToFile(Expense expenses, Date date);
    vector <Expense> getExpenseFromFile(int ID_LOGGED_USER);
};

#endif
