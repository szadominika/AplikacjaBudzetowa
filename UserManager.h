#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
//#include <sstream>

#include "User.h"
#include "FileWithUsers.h"

using namespace std;

class UserManager {

    int loggedInUserId;
    vector <User> users;
    FileWithUsers fileWithUsers;
    User getNewUserData();
    int getNewUserId();
    bool isLoginExists(string login);

public:
        UserManager(string fileNameWithUsers) : fileWithUsers(fileNameWithUsers) {
            loggedInUserId = 0;
            users = fileWithUsers.loadUserFromFile();
        };
        void registerUser();
        void userLogIn();
        void logOutUser();
        bool isUserLoggedIn();
        void changePassword();
        char selectOptionFromUserMenu();
        char selectOptionFromMainMenu();
        int getLoggedInUserID();
};

#endif
