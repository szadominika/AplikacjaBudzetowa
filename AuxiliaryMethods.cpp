#include <iostream>
#include <sstream>
#include <vector>
#include <windows.h>
#include <fstream>
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
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
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
