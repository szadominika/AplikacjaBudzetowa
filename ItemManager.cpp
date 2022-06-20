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
    //int date = itr -> getItemDate();
    cout << "Date:        " << date.changeDateTostring(itr -> getItemDate()) << endl;
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
    cout << "Date:        " << date.changeDateTostring(itr -> getItemDate()) << endl;
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

void ItemManager::viewCurrentMonthBalance() {

    int todaysDate = date.changeDateToIntNumber(date.getCurrentDateFromSystem());
    int minDate = (todaysDate/100)*100 + 1;
    int maxDate = (todaysDate/100 + 1)*100;

    system("cls");

    sortByDateIncomes();
    cout << ">>> INCOMES FOR THE CURRENT MONTH  <<<\n" << endl;
    viewSelectedIncomes(minDate, maxDate);


    sortByDateExpenses();
    cout << ">>> EXPENSES FOR THE CURRENT MONTH <<<\n" << endl;
    viewSelectedExpenses(minDate, maxDate);

    cout << ">>>   FINANCE STATEMENT   <<<\n" << endl;
    cout << "Total income:     " << sumOfIncomes << endl;
    cout << "Total expense:    " << sumOfExpenses << endl;
    cout << "Month Balance:    " << showpos << sumOfIncomes - sumOfExpenses << endl << endl;
    cout << noshowpos;

    sumOfIncomes = 0;
    sumOfExpenses = 0;

    system("pause");
}

void ItemManager::sortByDateIncomes() {

    sort(incomes.begin(), incomes.end(), Income());
}

void ItemManager::viewSelectedIncomes(int minDate, int maxDate) {

    bool incomeExist = false;

    for (vector <Income>::iterator itr = incomes.begin(); itr != incomes.end(); itr++) {

        int date = itr -> getItemDate();
        if(date >= minDate && date <= maxDate) {
            incomeExist = true;
            sumUpIncomes(itr);
            viewIncome(itr);
            cout << endl;
        }
    }
    if (!incomeExist)
        cout << "There were no incomes.\n" << endl;
}

void ItemManager::sumUpIncomes (vector <Income>::iterator itr) {

    sumOfIncomes += itr -> getItemAmount();
}

void ItemManager::sortByDateExpenses() {

    sort(expenses.begin(), expenses.end(), Expense());
}

void ItemManager::viewSelectedExpenses(int minDate, int maxDate) {

    bool expenseExist = false;

    for (vector <Expense>::iterator itr = expenses.begin(); itr != expenses.end(); itr++) {

        int date = itr -> getItemDate();
        if(date >= minDate && date <= maxDate) {
            expenseExist = true;
            sumUpExpenses(itr);
            viewExpense(itr);
            cout << endl;
        }
    }
    if (!expenseExist)
        cout << "There were no incomes.\n" << endl;
}

void ItemManager::sumUpExpenses (vector <Expense>::iterator itr) {

    sumOfExpenses += itr -> getItemAmount();
}
