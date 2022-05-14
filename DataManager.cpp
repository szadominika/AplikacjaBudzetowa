#include "DataManager.h"

int DataManager :: getCurrentDate() {
    int currentDate = 0;
    year = getCurrentYear();
    currentDate = (year * 10000);
    month = getCurrentMonth();
    currentDate += (month * 100);
    day = getCurrentDay();
    currentDate += day;

    return currentDate;
}

int DataManager :: getCurrentYear() {
    time(&calculatedTime);
    data = localtime(&calculatedTime);
    year = data -> tm_year+1900;

    return year;
}

int DataManager :: getCurrentMonth() {
    time(&calculatedTime);
    data = localtime(&calculatedTime);
    month = data -> tm_mon+1;

    return month;
}

int DataManager :: getCurrentDay() {
    time(&calculatedTime);
    data = localtime(&calculatedTime);
    day = data -> tm_mday;

    return day;
}

bool DataManager :: isDateCorrect(string date) {

    int year = (date[0]-'0')*1000 + (date[1]-'0')*100 + (date[2]-'0')*10 + (date[3]-'0');
    int month = (date[5]-'0')*10 + (date[6]-'0');
    int day = (date[8]-'0')*10 + (date[9]-'0');

    if (isValidFormatDate(date) == false) {
        return false;
    } else if (isValidYear (year) == false) {
        return false;
    } else if (isValidMonth(month) == false || month > getCurrentMonth()) {
        return false;
    } else if (day >= 1 && day <= 31) {
        if (isValidDay(day, month, year) == true) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }

    return true;
}

bool DataManager :: isValidYear (int year) {

    if (year > getCurrentYear() || year < MIN_VALID_YR) {
        return false;
    }
    return true;
}

bool DataManager :: isValidMonth(int month) {
    if (month < 1 || month > 12) {
        return false;
    }
    return true;
}

bool DataManager :: isValidDay (int day, int month, int year) {

    if (month == 2) {
        if ((isLeap(year) == true) && (day == 29)) {
            return true;
        } else if (day >= 1 && day <= 28) {
            return true;
        } else if (day < 1 && day >= 30) {
            return false;
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day >= 1 && day <= 30) {
            return true;
        } else return false;
    } else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
        if (day >= 1 && day <= 31) {
            return true;
        } else return false;
    }
}

bool DataManager :: isValidFormatDate (string date) {

    if ((!date.size() == 10) || (!date[0] == 2) || (date[4] != '-') || (date[7] != '-'))
        return false;
    else
        return true;
}

bool DataManager :: isLeap(int year) {
    if(((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) {
        return true;
    } else return false;
}
void DataManager :: showDate(Date dateOb)
{
    cout << endl << "Year: " << dateOb.getYear() << endl;
    cout << "Month: " << dateOb.getMonth() << endl;
    cout << "Day: " << dateOb.getDay() << endl;
}
