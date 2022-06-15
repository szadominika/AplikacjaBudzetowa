#include "XmlFile.h"

using namespace std;



bool XmlFile::fileExists(CMarkup &xml) {

   return xml.Load(getFileName());
}

string XmlFile::getFileName() {

    return FILE_NAME;
}
