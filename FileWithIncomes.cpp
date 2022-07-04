#include "FileWithIncomes.h"
#include "Markup.h"

using namespace std;

bool FileWithIncomes::addIncomeToFile(Income income,Date date) {
    CMarkup xml;
    string fileNameWithIncomes = XmlFile :: getFileName();
    bool fileExists = xml.Load(fileNameWithIncomes);
     if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem( "IncomeId", income.getIncomeId());
    xml.AddElem( "UserID", income.getUserId());
    xml.AddElem( "Date", date.getDateString());
    xml.AddElem( "Item", income.getItemName());
    xml.AddElem( "Amount", AuxiliaryMethod::convertFloatToString (income.getItemAmount()));
    xml.Save(fileNameWithIncomes);
    lastIncomeId++;
}

vector <Income> FileWithIncomes::getIncomeFromFile(int ID_LOGGED_USER) {
    vector <Income> incomes;
    int incomeId = 0;
    CMarkup xml;
    if (fileExists(xml)) {
        xml.FindElem();
        xml.IntoElem();
        while ( xml.FindElem("Income") == true) {
                Income income;
                xml.IntoElem();
                xml.FindElem( "IncomeId");
                incomeId = atoi((xml.GetElemContent()).c_str());
                xml.FindElem("UserID");
           if (atoi((xml.GetElemContent()).c_str()) == ID_LOGGED_USER) {
                    income.setUserId(ID_LOGGED_USER);
                    income.setIncomeId(incomeId);
                    xml.FindElem( "Date");
                    income.setDate(AuxiliaryMethod::convertStringToInt(AuxiliaryMethod::removeDashFromDate(xml.GetElemContent())));//changeDateToIntNumber(xml.GetElemContent()));
                    xml.FindElem( "Item");
                    income.setItemName(xml.GetElemContent());
                    xml.FindElem( "Amount");
                    income.setItemAmount(AuxiliaryMethod::convertStringToFloat(xml.GetElemContent()));
                    incomes.push_back(income);
           }
           xml.OutOfElem();
        }
    }
    return incomes;
}

int FileWithIncomes::getLastIncomeIdFromFile() {
    CMarkup xml;
    vector <Income> incomes;
    if(fileExists(xml)) {
        xml.FindElem();
        xml.IntoElem();
        while(xml.FindElem("Income")) {
            xml.FindChildElem("IncomeId");
        }
        return lastIncomeId = AuxiliaryMethod::convertStringToInt(xml.GetChildData());
    } else {
        return 0;
    }
}

int FileWithIncomes::getLastIncomeId() {
    return lastIncomeId;
}

