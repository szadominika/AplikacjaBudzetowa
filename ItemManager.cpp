#include "ItemManager.h"

using namespace std;

void ItemManager :: addIncome() {

    Income income;
    income = provideIncomeDetails();

    incomes.push_back(income);

    fileWithIncomes.addIncomeToFile(income, date);
    cout << endl << "Income has been successfully added to the file" << endl << endl;
    system("pause");
}

Income ItemManager :: provideIncomeDetails() {

    Income income;

    string itemName = "";
    float amount = 0;
    char option;

    system("cls");
    cout << " >>> ADDING NEW INCOME <<<" << endl << endl;

    date.getDateFromUser();
    income.setDate(date.getDateInt());

    cout << "Provide income description: ";
    itemName = AuxiliaryMethod::getLine();
    income.setItemName(itemName);

    cout << "Provide amount: ";
    amount = AuxiliaryMethod::getFloat();
    income.setItemAmount(amount);

    income.setIncomeId(fileWithIncomes.getLastIncomeId() + 1);
    income.setUserId(ID_LOGGED_USER);

    return income;
}

void ItemManager :: viewIncome( vector <Income>::iterator itr) {

    cout << "Income ID:   " << itr -> getIncomeId() << endl;
    cout << "User ID:     " << itr -> getUserId() << endl;
   // cout << "Date:        " << Date::changeDateTostring(itr -> getItemDate()) << endl;
    cout << "Item:        " << itr -> getItemName() << endl;
    cout << "Amount:      " << itr -> getItemAmount() << endl;

}

void ItemManager :: addExpense() {

    Expense expense;
    expense = provideExpenseDetails();

    expenses.push_back(expense);

    fileWithExpenses.addExpenseToFile(expense, date);
    cout << endl << "Income has been successfully added to the file" << endl << endl;
    system("pause");
}

Expense ItemManager :: provideExpenseDetails() {

    Expense expense;

    string itemName = "";
    float amount = 0;
    char option;

    system("cls");
    cout << " >>> ADDING NEW EXPENSE <<<" << endl << endl;

    date.getDateFromUser();
    expense.setDate(date.getDateInt());

    cout << "Provide expense description: ";
    itemName = AuxiliaryMethod::getLine();
    expense.setItemName(itemName);

    cout << "Provide amount: ";
    amount = AuxiliaryMethod::getFloat();
    expense.setItemAmount(amount);

    expense.setExpenseId(fileWithExpenses.getLastExpenseId() + 1);
    expense.setUserId(ID_LOGGED_USER);

    return expense;
}

void ItemManager :: viewExpense( vector <Expense>::iterator itr) {

    cout << "Expense ID:   " << itr -> getExpenseId() << endl;
    cout << "User ID:     " << itr -> getUserId() << endl;
//    cout << "Date:        " << Date::changeDateTostring(itr -> getItemDate()) << endl;
    cout << "Item:        " << itr -> getItemName() << endl;
    cout << "Amount:      " << itr -> getItemAmount() << endl;

}

void ItemManager::viewAllExpenses() {

    for (vector<Expense>::iterator itr=expenses.begin(); itr != expenses.end(); itr++) {

        viewExpense(itr);
        cout << endl;
    }
    system("pause");
}
