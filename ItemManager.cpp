#include "ItemManager.h"

using namespace std;

void ItemManager :: addIncome() {
    Income income;
    income = provideIncomeDetails();
    incomes.push_back(income);
    fileWithIncomes.addIncomeToFile(income, date);
    cout << endl << "Przychod zostal dodany do pliku." << endl << endl;
    system("pause");
}

Income ItemManager :: provideIncomeDetails() {
    Income income;
    string itemName = "";
    float amount = 0;
    char option;

    system("cls");
    cout << "  DODAJ PRZYCHOD " << endl << endl;
    date.getDateFromUser();
    income.setDate(date.getDateInt());
    cout << "Wprowadz nazwe przychodu: ";
    itemName = AuxiliaryMethod::getLine();
    income.setItemName(itemName);
    cout << "Wprowadz kwote: ";
    do {
        string samount = (AuxiliaryMethod::getLine());
        if(isAmountCorrect(samount)) {
            amount = AuxiliaryMethod::convertStringToFloat(AuxiliaryMethod::changeCommaToDot(samount));
            break;
        }
    } while(true);
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
            cout << "Niepoprawna wartosc. Sprobuj ponownie." << endl;
            return false;
        }
        if (((singleChar == 45) || (singleChar > 57))) {
            cout << "Niepoprawna wartosc. Sprobuj ponownie." << endl;
            return false;
        }
         if(singleChar == 44 || singleChar == 46) {
            positionOfDot = i;

            samount.erase(0, positionOfDot+1);
                if(samount.size() > 2) {
                    cout << "Prosze podaj wartosc z dokladnoscia do 0.00" << endl;
                    return false;
            }
        }
    }
    if (samount.empty()) {
            cout << "Nie wprowadzono kwoty. Sprobuj ponownie.";
            return false;
        }
    return true;
}

void ItemManager :: viewIncome( vector <Income>::iterator itr) {
     cout << "Income ID:   " << itr -> getIncomeId() << endl;
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
    cout << endl << "Wydatek zostal dodany do pliku." << endl << endl;
    system("pause");
}

Expense ItemManager :: provideExpenseDetails() {
    Expense expense;
    string itemName = "";
    float amount = 0;
    char option;

    system("cls");
    cout << "  DODAJ WYDATEK " << endl << endl;
    date.getDateFromUser();
    expense.setDate(date.getDateInt());
    cout << "Wprowadz nazwe wydatku: ";
    itemName = AuxiliaryMethod::getLine();
    expense.setItemName(itemName);
    cout << "Wprowadz kwote: ";
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
    cout << "Expense ID:   " << itr -> getExpenseId() << endl;
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
    cout << fixed << setprecision(2);
    system("cls");
    sortByDateIncomes();
    cout << "Dochod w biezacym miesiacu.  " << endl;
    viewSelectedIncomes(minDate, maxDate);
    sortByDateExpenses();
    cout << "Wydatki w biezacym miesiacu. " << endl;
    viewSelectedExpenses(minDate, maxDate);

    cout << "Podsumowanie  " << endl;
    if(sumOfIncomes == 0){
        cout << "Suma przychodow: brak" << endl;
    } else
    cout << "Suma przychodow: " << sumOfIncomes << endl;

    if(sumOfExpenses == 0){
        cout << "Suma wydatkow: brak" << endl;
    } else
    cout << "Suma wydatkow: " << sumOfExpenses << endl;

    cout << "Miesieczny bilans:    " << showpos << sumOfIncomes - sumOfExpenses << endl << endl;
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
        cout << "Nie wprowadzono przychodu.." << endl;
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
        cout << "Nie wprowadzono wydatkow." << endl;
}

void ItemManager::sumUpExpenses (vector <Expense>::iterator itr) {
    sumOfExpenses += itr -> getItemAmount();
}

void ItemManager::showBalanceForLastMonth() {
    int todaysDate = date.changeDateToIntNumber(date.getCurrentDateFromSystem());
    int minDate = (todaysDate/100 - 1)*100 + 1;
    int maxDate = (todaysDate/100)*100;
    cout << fixed << setprecision(2);
    system("cls");
    sortByDateIncomes();
    cout << "Dochod w poprzednim miesiacu  " << endl;
    viewSelectedIncomes(minDate, maxDate);
    sortByDateExpenses();
    cout << "Wydatki w poprzednim miesiacu " << endl;
    viewSelectedExpenses(minDate, maxDate);

    cout << "Podsumowanie  " << endl;
    if(sumOfIncomes == 0){
        cout << "Suma przychodow: brak" << endl;
    } else
    cout << "Suma przychodow: " << sumOfIncomes << endl;

    if(sumOfExpenses == 0){
        cout << "Suma wydatkow: brak" << endl;
    } else
    cout << "Suma wydatkow: " << sumOfExpenses << endl;

    cout << "Miesieczny bilans:    " << showpos << sumOfIncomes - sumOfExpenses << endl << endl;
    cout << noshowpos;
    sumOfIncomes = 0;
    sumOfExpenses = 0;
    system("pause");
}

void ItemManager::showBalanceForSelectedPeriod() {
    system("cls");
    int firstDate = 0, secondDate = 0, minDate = 0, maxDate = 0;
    cout << fixed << setprecision(2);

    cout << "Wprowadz date poczatkowa: " << endl;
    date.getDateFromUser();
    firstDate = date.getDateInt();
    cout << "Wprowadz date koncowa: " << endl;
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
    cout << "Przychod w wybranym okresie" << endl;
    viewSelectedIncomes(minDate, maxDate);
    sortByDateExpenses();
    cout << "Wydatki w wybranym okresie" << endl;
    viewSelectedExpenses(minDate, maxDate);

    cout << "Podsumowanie  " << endl;
    if(sumOfIncomes == 0){
        cout << "Suma przychodow: brak" << endl;
    } else
    cout << "Suma przychodow: " << sumOfIncomes << endl;

    if(sumOfExpenses == 0){
        cout << "Suma wydatkow: brak" << endl;
    } else
    cout << "Suma wydatkow: " << sumOfExpenses << endl;

    cout << "Miesieczny bilans:    " << showpos << sumOfIncomes - sumOfExpenses << endl << endl;
    cout << noshowpos;
    sumOfIncomes = 0;
    sumOfExpenses = 0;
    system("pause");
}
