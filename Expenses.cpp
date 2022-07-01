#include <iostream>
#include "Expenses.h"

using namespace std;

void Expense::setExpenseId(int newExpenseId) {
    expenseId = newExpenseId;
}

int Expense::getExpenseId() {
    return expenseId;
}
