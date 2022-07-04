#ifndef INCOMES_H
#define INCOMES_H

#include <iostream>

#include "Item.h"

using namespace std;

class Income : public Item {

    int incomeId;

public:
    void setIncomeId (int newIncomeId);
    int getIncomeId();
};


#endif
