#ifndef AUXILIARYMETHOD_H
#define AUXILIARYMETHOD_H

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

class AuxiliaryMethod {

    static bool isFloatNumber(string input);

public:
    static char getChar();
    static string getLine();
    static float getFloat();
    static int convertStringToInt (string date);
    static string convertFloatToString(float amount);
    static string convertIntToString (int number);
    static float convertStringToFloat(string amount);
    static string addDashToDate(string date);
    static string removeDashFromDate(string date);
    static string changeFirstLetterToCapitalAndOtherToLowercase(string text);
    static bool isLetter(char choice);
    static string changeCommaToDot(string input);
};

#endif
