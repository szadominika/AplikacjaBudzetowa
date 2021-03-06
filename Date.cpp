#include <iostream>

#include "Date.h"

using namespace std;

string Date::getDateString() {
    return dateString;
}

int Date::getDateInt() {
    return dateInt;
}

void Date::setDateString(string newDateString) {
        dateString = newDateString;
}

void Date:: setDateInt(int newDateInt) {
      dateInt = newDateInt;
}

void Date::getDateFromUser() {
    char option;
    cout << "Czy chcesz uzyc dzisiejszej daty? (y/n)" << endl;
    while(true) {
        option = AuxiliaryMethod::getChar();
        if (AuxiliaryMethod::isLetter(option)){
            if (tolower(option)=='y'){
                dateString = getCurrentDateFromSystem();
                dateInt = changeDateToIntNumber(dateString);
                break;
            }
            else if (tolower(option)=='n') {
                cout << "Wpisz dat? (YYYY-MM-DD): ";
                while (true) {
                    dateString = AuxiliaryMethod::getLine();
                    dateInt = changeDateToIntNumber(dateString);
                    if(isDateCorrect()){
                        break;
                    }
                    else
                        cout << "Niepoprawny format. Prosze wpisac ponownie." << endl;
                }
                break;
            }
            else {
                cout << "Nie ma takiej opcji. Sprobuj ponownie.";
                Sleep(1500);
            }
        }
        else {
            cout << "To nie jest litera. Sprobuj ponownie.";
            Sleep(1500);
        }
    }
}

bool Date::isDateCorrect() {
    int year = AuxiliaryMethod::convertStringToInt(syear);
    int month = AuxiliaryMethod::convertStringToInt(smonth);
    int day = AuxiliaryMethod::convertStringToInt(sday);
    int minDate = 20000101;
    int maxDate = (changeDateToIntNumber(getCurrentDateFromSystem())/100 + 1) * 100;
    if (dateInt >= minDate && dateInt < maxDate){
        if(month < 1 || month > 12)
            return false;
        if(day < 1 || day > 31)
            return false;
        if(month == 2) {
            if(((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
                return day <= 29;
            else
                return day <= 28;
        }
        if(month == 4 || month == 6 || month == 9 || month == 11)
            return day <= 30;
        return true;
    }
    return false;
}

string Date :: getCurrentDateFromSystem() {
    string sdate;
    time_t t = time(0);
    tm* now = localtime(&t);
    year = now->tm_year + 1900;
    month = now->tm_mon + 1;
    day = now->tm_mday;
    syear = AuxiliaryMethod::convertIntToString(year);
    smonth = AuxiliaryMethod::convertIntToString(month);
    sday = AuxiliaryMethod::convertIntToString(day);
    if (month > 0 && month < 10)
        smonth = "0" + smonth;
    if (day > 0 && day < 10)
        sday = "0" + sday;
    sdate = syear + "-" + smonth + "-" + sday;
    return sdate;
}

string Date :: changeDateTostring(int date) {
    string sdate = AuxiliaryMethod::convertIntToString(date);
    sdate.insert(4,"-");
    sdate.insert(7, "-");
    return sdate;
}

int Date :: changeDateToIntNumber(string sdate) {
    string date;
    stringstream ss(sdate);
    getline(ss, syear, '-');
    getline(ss, smonth, '-');
    getline(ss, sday);
    date = syear + smonth + sday;
    return AuxiliaryMethod::convertStringToInt(date);
}


