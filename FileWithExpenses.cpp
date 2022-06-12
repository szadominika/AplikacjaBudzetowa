#include "FileWithExpenses.h"
#include "Markup.h"

bool FileWithExpenses::addExpenseToFile(Expense expense,Date date) {

    //string amount = AuxiliaryMethod::convertFloatToString (income.getItemAmount());
    CMarkup xml;

     if (!fileExists(xml))
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Expense");
    xml.IntoElem();
    xml.AddElem( "ExpenseId", expense.getExpenseId());
    xml.AddElem( "UserId", expense.getUserId());
    xml.AddElem( "Date", /*income.getItemDate()*/date.getDateString());
    xml.AddElem( "Item", expense.getItemName());
    xml.AddElem( "Amount", AuxiliaryMethod::convertFloatToString (expense.getItemAmount()));
    xml.Save(fileNameWithExpenses);
    lastExpenseId++;
}

vector <Expense> FileWithExpenses::getExpenseFromFile(int ID_LOGGED_USER) {

    //Income income;
    vector <Expense> expenses;
    int expenseId = 0;
    CMarkup xml;

    if (fileExists(xml)) {

        xml.FindElem();
        xml.IntoElem();
        while ( xml.FindElem("Expense") == true) {

                Expense expense;
                xml.IntoElem();
                xml.FindElem( "ExpenseId");
                //int itemId = atoi(xml.GetData().c_str());
                expenseId = atoi((xml.GetElemContent()).c_str());
                //item.setupItemId(itemId);
                xml.FindElem("UserId");
           // int userId = atoi(xml.GetData().c_str());//atoi( MCD_2PCSZ(xml.GetData()));
           if (atoi((xml.GetElemContent()).c_str()) == ID_LOGGED_USER) {
                    expense.setUserId(ID_LOGGED_USER);
                    expense.setExpenseId(expenseId);
                    xml.FindElem( "Date");
                    expense.setDate(AuxiliaryMethod::convertStringToInt(AuxiliaryMethod::removeDashFromDate(xml.GetElemContent())));//changeDateToIntNumber(xml.GetElemContent()));
                    xml.FindElem( "Item");
                    expense.setItemName(xml.GetElemContent());
                    xml.FindElem( "Amount");
                    expense.setItemAmount(AuxiliaryMethod::convertStringToFloat(xml.GetElemContent()));
                    expenses.push_back(expense);
           }
           xml.OutOfElem();
        }
    }
    return expenses;
}

int FileWithExpenses::getLastExpenseIdFromFile() {

    CMarkup xml;
    vector <Expense> expenses;

    if(fileExists(xml)) {

        xml.FindElem();
        xml.IntoElem();
        while(xml.FindElem("Expense")) {

            xml.FindChildElem("ExpenseId");
        }
        return lastExpenseId = AuxiliaryMethod::convertStringToInt(xml.GetChildData());
    } else {

        return 0;
    }
}

int FileWithExpenses::getLastExpenseId() {

    return lastExpenseId;
}

