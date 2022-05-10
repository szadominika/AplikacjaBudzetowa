#include "TextFile.h"

using namespace std;



/*bool XmlFile::isFileEmpty()
{
    bool emptyFile = true;
    fstream textFile;
    textFile.open(getFileName().c_str(), ios::app);

    if (textFile.good() == true)
    {
        textFile.seekg(0, ios::end);
            if (textFile.tellg() != 0)
                emptyFile = false;
    }

    textFile.close();
    return emptyFile;
}*/

string XmlFile::getFileName() {
    return FILE_NAME;
}
