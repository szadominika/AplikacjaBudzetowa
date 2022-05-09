#ifndef PLIKTEKSTOWY_H
#define PLIKTEKSTOWY_H

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

class XmlFile {

    const string FILE_NAME;

public:

    XmlFile(string fileName) : FILE_NAME(fileName) {
    }

    string getFileName();
 //   bool isFileEmpty();

};






#endif
