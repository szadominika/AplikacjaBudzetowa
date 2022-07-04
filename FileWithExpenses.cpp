#include "FileWithExpenses.h"
#include "Markup.h"


using namespace std;

bool FileWithExpenses::addExpenseToFile(Expense expense,Date date) {
    CMarkup xml;
    string fileNameWithExpenses = XmlFile :: getFileName();
    bool fileExists = xml.Load(fileNameWithExpenses);
     if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Expenses");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Expense");
    xml.IntoElem();
    xml.AddElem( "ExpenseId", expense.getExpenseId());
    xml.AddElem( "UserID", expense.getUserId());
    xml.AddElem( "Date", date.getDateString());
    xml.AddElem( "Item", expense.getItemName());
    xml.AddElem( "Amount", AuxiliaryMethod::convertFloatToString (expense.getItemAmount()));
    xml.Save(fileNameWithExpenses);
    lastExpenseId++;
}

vector <Expense> FileWithExpenses::getExpenseFromFile(int ID_LOGGED_USER) {
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
                expenseId = atoi((xml.GetElemContent()).c_str());
                xml.FindElem("UserID");
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

