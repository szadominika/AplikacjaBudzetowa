#ifndef XMLFILE_H
#define XMLFILE_H

#include <iostream>

#include "Markup.h"
#include "Date.h"

using namespace std;

class XmlFile {

    const string FILE_NAME;

public:
    XmlFile(string fileName) : FILE_NAME(fileName) {}
    bool fileExists(CMarkup &xml);
    string getFileName();
};

#endif
