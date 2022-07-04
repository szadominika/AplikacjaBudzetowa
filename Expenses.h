#ifndef EXPENSES_H
#define EXPENSES_H

#include <iostream>

#include "Item.h"

using namespace std;

class Expense : public Item {

    int expenseId;

public:
    void setExpenseId (int newExpenseId);
    int getExpenseId();
};


#endif
