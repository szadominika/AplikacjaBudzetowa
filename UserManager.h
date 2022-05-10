#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

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
        char selectOptionFromUserMenu();
        void showAllUsers();
        int getIdLoggedUser();
        void userLogIn();
        void logOffUser();
        bool isUserLoggedIn();

};


#endif
