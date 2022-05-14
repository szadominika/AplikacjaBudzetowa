#ifndef AUXILIARYMETHOD_H
#define AUXILIARYMETHOD_H


#include <iostream>

using namespace std;

class AuxiliaryMethod {
public:
    static char getChar();
    static string getLine();
    static float getFloat();
    static string changeFirstLetterToCapitalAndOtherToLowercase(string text);
    static string removeDashFromDate(string date);
    static int convertStringToInt (string date);
    static string convertFloatToString(float amount);
    static string convertIntToString (int number);
    static string addDashToDate(string date);

};

#endif
