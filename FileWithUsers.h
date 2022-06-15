#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H


#include <iostream>
#include <vector>
#include <windows.h>
#include <cstdlib>
#include <vector>

#include "XmlFile.h"
#include "Markup.h"
#include "User.h"

using namespace std;

class FileWithUsers : public XmlFile {

    string fileNameWithUsers;

public:
    FileWithUsers(string fileNameWithUsers) : XmlFile(fileNameWithUsers) {};
    void addUserToFile(User user);
    vector <User> loadUserFromFile();
    bool changeUserPassword(vector <User>::iterator itr);

};

#endif
