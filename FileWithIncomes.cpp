#include "FileWithIncomes.h"
#include "Markup.h"

bool FileWithIncomes::addIncomeToFile(Income income,Date date) {

    //string amount = AuxiliaryMethod::convertFloatToString (income.getItemAmount());
    CMarkup xml;
    string fileNameWithIncomes = XmlFile :: getFileName();
    bool fileExists = xml.Load(fileNameWithIncomes);

     if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem( "IncomeId", income.getIncomeId());
    xml.AddElem( "UserId", income.getUserId());
    xml.AddElem( "Date", /*income.getItemDate()*/date.getDateString());
    xml.AddElem( "Item", income.getItemName());
    xml.AddElem( "Amount", AuxiliaryMethod::convertFloatToString (income.getItemAmount()));
    xml.Save(fileNameWithIncomes);
    lastIncomeId++;
}

vector <Income> FileWithIncomes::getIncomeFromFile(int ID_LOGGED_USER) {

    //Income income;
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
                //int itemId = atoi(xml.GetData().c_str());
                incomeId = atoi((xml.GetElemContent()).c_str());
                //item.setupItemId(itemId);
                xml.FindElem("UserId");
           // int userId = atoi(xml.GetData().c_str());//atoi( MCD_2PCSZ(xml.GetData()));
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

