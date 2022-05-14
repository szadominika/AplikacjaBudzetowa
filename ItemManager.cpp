#include "ItemManager.h"

void ItemManager :: addIncome()
{
    Item income = provideIncomeDetails();
    incomes.push_back(income);
    fileWithIncomes.addIncomeToFile(income);
    cout << endl << "Income added to the file" << endl << endl;
    showAllIncomes();
    system("pause");
}


int ItemManager :: getNewIncomeId()
{
    if (incomes.empty() == true)
        return 1;
    else
        return incomes.back().getItemId() + 1;
}


Item ItemManager :: provideIncomeDetails()
{
    Item item;
    DataManager dataManager;
    string itemName, userSurname, otherDate, stringDatewithoutDash, currentStringDate, stringAmount;
    int currentDate, intDateWithoutDash;
    float amount;
    char option;

    int itemId = getNewIncomeId();
    item.setupItemId(itemId);
    item.setupUserId(ID_LOGGED_USER);

    cout << "Do you want to add income with current date?" <<endl;
    cout << "If yes, please click 'y', if you want to choose other date, please click 'n': " << endl;
    option = AuxiliaryMethod::getChar();

    if (option == 'y') {
        currentDate = dataManager.getCurrentDate();
        currentStringDate = AuxiliaryMethod::convertIntToString(currentDate);
        currentStringDate = AuxiliaryMethod::addDashToDate(currentStringDate);
        item.setupStringDate(currentStringDate);
    }
    else if (option == 'n') {

        do {
            cout << "Provide date in format YYYY-MM-DD: ";
            otherDate = AuxiliaryMethod :: getLine();
        } while (dataManager.isDateCorrect(otherDate) == false);

        stringDatewithoutDash = AuxiliaryMethod :: removeDashFromDate(otherDate);
        intDateWithoutDash = AuxiliaryMethod :: convertStringToInt (stringDatewithoutDash);
        item.setupStringDate(otherDate);
    }
    cout << "Provide income description: ";
    itemName = AuxiliaryMethod::getLine();
    item.setupItemName(itemName);
    cout << "Provide amount: ";
    amount = AuxiliaryMethod::getFloat();
    item.setupItemAmount(amount);

    return item;
}

void ItemManager :: showAllIncomes() {

    for (int i = 0; i < incomes.size(); i++) {
        cout << "Item Id: " << incomes[i].getItemId() << endl;
        cout << "User Id: " << incomes[i].getUserId() << endl;
        cout << "Item date: " << incomes[i].getItemDate() << endl;
        cout << "Item name: " << incomes[i].getItemName() << endl;
        cout << "Item amount: " << incomes[i].getItemAmount() << endl << endl;
    }
}
