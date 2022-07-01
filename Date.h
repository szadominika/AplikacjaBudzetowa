#ifndef DATE_H
#define DATE_H

#include "AuxiliaryMethods.h"
#include "Incomes.h"

#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <windows.h>

using namespace std;

class Date {

    string dateString;
    string sday, syear, smonth;
    int dateInt;
    int year, month, day;
    bool isDateCorrect();

public:
    Date() {
        dateString = "";        sday = "";        smonth = "";        syear = "";
        dateInt = 0;        day = 0;        month = 0;        year = 0;
    }

    string getDateString();
    int getDateInt();
    void setDateString(string newDateString);
    void setDateInt(int newDateInt);
    string getCurrentDateFromSystem();
    int changeDateToIntNumber(string sday);
    void getDateFromUser();
    string changeDateTostring(int date);
};

#endif
