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

class Date{

    const int MIN_VALID_YR = 2000;

    string dateString;
    string sday, syear, smonth;
    int dateInt;
    int year, month, day;

    string createDate();
    bool isLeap(int year);
    bool isDateInProperRange();
    bool isDateCorrect(string date);//
    bool isDateCorrect();
    bool isValidFormatDate (string date);
    bool isValidYear (int year);
    bool isValidMonth(int month);
    int getCurrentMonth();
    bool isValidDay (int day, int month, int year);
    int getCurrentYear();

public:
    Date() {

        dateString = "";
        sday = "";
        smonth = "";
        syear = "";
        dateInt = 0;
        day = 0;
        month = 0;
        year = 0;
    }

    string getDateString();
    int getDateInt();
    string getCurrentDateFromSystem();
    int changeDateToIntNumber(string sday);
    void getDateFromUser();
    string changeDateTostring(int date);
};

#endif
