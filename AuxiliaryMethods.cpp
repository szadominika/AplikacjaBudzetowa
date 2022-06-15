#include <iostream>
#include <sstream>
#include <vector>
#include <windows.h>
#include <algorithm>

#include "AuxiliaryMethods.h"

using namespace std;

char AuxiliaryMethod::getChar()
{
    string input = "";
    char sign  = {0};

    while (true)
    {
        getline(cin, input);

        if (input.length() == 1)
        {
            sign = input[0];
            break;
        }
        cout << "This is not a character. Please enter again." << endl;
    }
    return sign;
}

string AuxiliaryMethod::getLine() {

    string input = "";
    getline(cin, input);
    return input;
}

string AuxiliaryMethod::changeFirstLetterToCapitalAndOtherToLowercase(string text) {

    if (!text.empty())
    {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}

string AuxiliaryMethod::removeDashFromDate(string date) {

    string stringDatewithoutDash;

    for (int i = 0 ; i <= date.length(); i++) {
        if (date[i] != '-') {
            stringDatewithoutDash += date[i];
        }
    }
    return stringDatewithoutDash;
}

int AuxiliaryMethod::convertStringToInt(string date) {

    int number;
    istringstream iss(date);
    iss >> number;
    return number;
}

float AuxiliaryMethod::getFloat() {

    string input = "";
    float number;

    while (true) {

        cin.clear();
        getline(cin, input);
        input = changeCommaToDot(input);
        stringstream myStream(input);
        if (myStream >> number)
            break;
        cout << "This is not the amount. Please add again. " << endl;
    }
    return number;
}

string AuxiliaryMethod::convertFloatToString(float amount) {

    std::stringstream FloatToStr;
    std::string str;

    FloatToStr << amount;
    FloatToStr >> str;
    FloatToStr.clear();

    return str;

}

string AuxiliaryMethod::convertIntToString (int number) {

    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

string AuxiliaryMethod::addDashToDate(string date) {

    string stringDateWithDash;
    stringDateWithDash = date.insert (4,1,'-');
    stringDateWithDash = stringDateWithDash.insert (7,1,'-');
    cout << stringDateWithDash << endl;

    return stringDateWithDash;
}

float AuxiliaryMethod::convertStringToFloat(string amount) {

    float input;
    istringstream iss(amount);
    iss >> input;
    return input;
}

bool AuxiliaryMethod::isFloatNumber(string input) {

    if(input == "")
        return false;
    else
    {
        size_t found = input.find_first_not_of("1234567890.,");

        if (found == string::npos)
        {
            found = input.find_first_not_of("1234567890");

            if(found == string::npos)
                return true;
            else if(found == input.find_last_not_of("1234567890"))
                return true;
        }
        return false;
    }
}

string AuxiliaryMethod::changeCommaToDot(string input) {

    size_t foundComma = input.find(",");
    if(foundComma != string::npos)
    {
        input.replace(foundComma, 1, ".");
    }
    return input;
}

bool AuxiliaryMethod::isLetter(char choice) {

    if(isdigit(choice))
        return false;
    return true;
}

