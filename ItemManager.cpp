#include "ItemManager.h"

using namespace std;

void ItemManager :: addIncome() {
    Income income;
    income = provideIncomeDetails();
    incomes.push_back(income);
    fileWithIncomes.addIncomeToFile(income, date);
    cout << endl << "Income has been successfully added to the file." << endl << endl;
    system("pause");
}

Income ItemManager :: provideIncomeDetails() {
    Income income;
    string itemName = "";
    float amount = 0;
    char option;

    system("cls");
    cout << "  ADDING NEW INCOME " << endl << endl;
    date.getDateFromUser();
    income.setDate(date.getDateInt());

    cout << "Provide income description: ";
    itemName = AuxiliaryMethod::getLine();
    income.setItemName(itemName);
    cout << "Provide amount: ";
    // amount = (AuxiliaryMethod::getFloat());
    do {
        string samount = (AuxiliaryMethod::getLine());
        if(isAmountCorrect(samount)) {
            amount = AuxiliaryMethod::convertStringToFloat(AuxiliaryMethod::changeCommaToDot(samount));

           // amount = stof(AuxiliaryMethod::changeCommaToDot(samount));
            break;
        }
    } while(true);
    cout<< amount;
    system("pause");

    income.setItemAmount(amount);

    income.setIncomeId(fileWithIncomes.getLastIncomeId() + 1);
    income.setUserId(ID_LOGGED_USER);

    return income;
}

bool ItemManager::isAmountCorrect(string samount) {

    int positionOfDot = 0;

    for(int i=0; i < samount.size(); i++) {
        int singleChar = samount[i];

        if((singleChar == 44 || singleChar == 46) && (samount[i+1] == 44 || samount[i+1] == 46)) {
            cout << "Incorrect character in value. Please enter amount again." << endl;
            return false;
        }
        if (((singleChar == 45) || (singleChar > 57))) {
            cout << "Incorrect character in value. Please enter amount again." << endl;
            return false;
        }
         if(singleChar == 44 || singleChar == 46) {
            positionOfDot = i;

            samount.erase(0, positionOfDot+1);
                if(samount.size() > 2) {
                    cout << "Please enter the date to 2 decimal places." << endl;
                    return false;
            }
        }
    }
    if (samount.empty()) {
            cout << "The amount has not been enter. Please enter amount again.";
            return false;
        }

    return true;
}

void ItemManager :: viewIncome( vector <Income>::iterator itr) {
    // cout << "Income ID:   " << itr -> getIncomeId() << endl;
    //cout << "User ID:     " << itr -> getUserId() << endl;
    //int date = itr -> getItemDate();
    cout << "Date:        " << date.changeDateTostring(itr -> getItemDate()) << endl;
    // cout << "Item:        " << itr -> getItemName() << endl;
    cout << "Amount:      " << itr -> getItemAmount() << endl;
}

void ItemManager :: addExpense() {
    Expense expense;
    expense = provideExpenseDetails();
    expenses.push_back(expense);

    fileWithExpenses.addExpenseToFile(expense, date);
    cout << endl << "Expense has been successfully added to the file." << endl << endl;
    system("pause");
}

Expense ItemManager :: provideExpenseDetails() {
    Expense expense;
    string itemName = "";
    float amount = 0;
    char option;

    system("cls");
    cout << "  ADDING NEW EXPENSE " << endl << endl;
    date.getDateFromUser();
    expense.setDate(date.getDateInt());

    cout << "Provide expense description: ";
    itemName = AuxiliaryMethod::getLine();
    expense.setItemName(itemName);
    cout << "Provide amount: ";
    //amount = AuxiliaryMethod::getFloat();
    do {
        string samount = (AuxiliaryMethod::getLine());
        if(isAmountCorrect(samount)) {
            amount = AuxiliaryMethod::convertStringToFloat(samount);
            break;
        }
    } while(true);

    expense.setItemAmount(amount);

    expense.setExpenseId(fileWithExpenses.getLastExpenseId() + 1);
    expense.setUserId(ID_LOGGED_USER);

    return expense;
}

void ItemManager :: viewExpense( vector <Expense>::iterator itr) {
    //cout << "Expense ID:   " << itr -> getExpenseId() << endl;
    //cout << "User ID:     " << itr -> getUserId() << endl;
    cout << "Date:        " << date.changeDateTostring(itr -> getItemDate()) << endl;
    // cout << "Item:        " << itr -> getItemName() << endl;
    cout << "Amount:      " << itr -> getItemAmount() << endl;
}

void ItemManager::viewAllExpenses() {
    for (vector<Expense>::iterator itr=expenses.begin(); itr != expenses.end(); itr++) {
        viewExpense(itr);
        cout << endl;
    }
    system("pause");
}

void ItemManager::showBalanceForCurrentMonth() {
    int todaysDate = date.changeDateToIntNumber(date.getCurrentDateFromSystem());
    int minDate = (todaysDate/100)*100 + 1;
    int maxDate = (todaysDate/100 + 1)*100;

    system("cls");
    sortByDateIncomes();
    cout << "INCOMES FOR THE CURRENT MONTH  " << endl;
    viewSelectedIncomes(minDate, maxDate);
    sortByDateExpenses();
    cout << "EXPENSES FOR THE CURRENT MONTH " << endl;
    viewSelectedExpenses(minDate, maxDate);

    cout << "FINANCE STATEMENT   " << endl;
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
        cout << "There were no incomes." << endl;
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
        cout << "There were no incomes." << endl;
}

void ItemManager::sumUpExpenses (vector <Expense>::iterator itr) {
    sumOfExpenses += itr -> getItemAmount();
}

void ItemManager::showBalanceForLastMonth() {
    int todaysDate = date.changeDateToIntNumber(date.getCurrentDateFromSystem());
    int minDate = (todaysDate/100 - 1)*100 + 1;
    int maxDate = (todaysDate/100)*100;

    system("cls");
    sortByDateIncomes();
    cout << "INCOMES FOR THE PREVIOUS MONTH  " << endl;
    viewSelectedIncomes(minDate, maxDate);
    sortByDateExpenses();
    cout << "EXPENSES FOR THE PREVIOUS MONTH " << endl;
    viewSelectedExpenses(minDate, maxDate);

    cout << "FINANCE STATEMENT   " << endl;
    cout << "Month Balance:    " << showpos << sumOfIncomes - sumOfExpenses << endl << endl;
    cout << noshowpos;
    sumOfIncomes = 0;
    sumOfExpenses = 0;
    system("pause");
}

void ItemManager::showBalanceForSelectedPeriod() {
    system("cls");
    int firstDate = 0, secondDate = 0, minDate = 0, maxDate = 0;
    cout << "Enter a start date and an end date of period that you want to view summary: " << endl;
    cout << "Enter a start date: " << endl;
    date.getDateFromUser();
    firstDate = date.getDateInt();
    cout << "Enter an end date: " << endl;
    date.getDateFromUser();
    secondDate = date.getDateInt();
    if (firstDate < secondDate) {
        minDate = firstDate;
        maxDate = secondDate;
    } else {
        minDate = secondDate;
        maxDate = firstDate;
    }

    system("cls");
    sortByDateIncomes();
    cout << "INCOMES FOR THE SELECTED PERIOD" << endl;
    viewSelectedIncomes(minDate, maxDate);
    sortByDateExpenses();
    cout << "EXPENSES FOR THE SELECTED PERIOD " << endl;
    viewSelectedExpenses(minDate, maxDate);

    cout << "FINANCE STATEMENT   " << endl;
    cout << "Month Balance:    " << showpos << sumOfIncomes - sumOfExpenses << endl << endl;
    cout << noshowpos;
    sumOfIncomes = 0;
    sumOfExpenses = 0;
    system("pause");
}
