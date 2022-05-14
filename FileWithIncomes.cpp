#include "FileWithIncomes.h"
#include "Markup.h"

void FileWithIncomes::addIncomeToFile(Item income)
{
    string amount = AuxiliaryMethod::convertFloatToString (income.getItemAmount());
    CMarkup xml;
    string fileNameWithIncomes = XmlFile::getFileName();

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
    xml.AddElem( "IncomeId", income.getItemId() );
    xml.AddElem( "UserId", income.getUserId() );
    xml.AddElem( "Date", income.getItemDate() );
    xml.AddElem( "Item", income.getItemName() );
    xml.AddElem( "Amount", amount );

    xml.Save(fileNameWithIncomes);

}
vector <Item> FileWithIncomes::getIncomeFromFile(int idLoggedUser) {
    Item item;
    vector <Item> incomes;
    CMarkup xml;
    string fileNameWithIncomes = XmlFile::getFileName();
    bool fileExists = xml.Load(fileNameWithIncomes);

    if (fileExists == true) {
        xml.FindElem();
        xml.IntoElem();
        while ( xml.FindElem("Income") == true) {
            xml.IntoElem();
                xml.FindElem( "IncomeId");
                int itemId = atoi(xml.GetData().c_str());
                item.setupItemId(itemId);
                xml.FindElem("UserId");
            int userId = atoi(xml.GetData().c_str());//atoi( MCD_2PCSZ(xml.GetData()));
                item.setupUserId(userId);

                xml.FindElem( "Date");
                string itemDate = xml.GetData();
                item.setupStringDate(itemDate);

                xml.FindElem( "Item");
                string incomeName = xml.GetData();
                item.setupItemName(incomeName);

                xml.FindElem( "Amount");
                float itemAmount = atoi(xml.GetData().c_str());
                item.setupItemAmount(itemAmount);
                incomes.push_back(item);

                xml.OutOfElem();

        }
    }
    return incomes;
}

Item FileWithIncomes::changeIntDateFormat(Item income){

    Item incomeOb;
    int itemId = income.getItemId();
    incomeOb.setupItemId(itemId);
    int userId = income.getUserId();
    incomeOb.setupUserId(userId);
    //string itemDate;
    string itemName = income.getItemName();
    incomeOb.setupItemName(itemName);
    float itemAmount = income.getItemAmount();
    incomeOb.setupItemAmount(itemAmount);

    string iteamStringDate = AuxiliaryMethod::convertIntToString (income.getIntDate());
    string dateItemWithDash = AuxiliaryMethod::addDashToDate(iteamStringDate);
    incomeOb.setupStringDate(dateItemWithDash);
    cout << "po zmienie formatu data: " << dateItemWithDash <<endl;
     return incomeOb;
}
