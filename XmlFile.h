#ifndef XMLFILE_H
#define XMLFILE_H

#include <iostream>
//#include <fstream>
#include <cstdlib>

#include "Markup.h"
#include "Date.h"

using namespace std;

class XmlFile {

    const string FILE_NAME;

public:
    Date date;
    XmlFile(string fileName) : FILE_NAME(fileName) {
    }
    bool fileExists(CMarkup &xml);
    string getFileName();
};



#endif
