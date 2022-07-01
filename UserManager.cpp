#include <iostream>

#include "UserManager.h"
#include "AuxiliaryMethods.h"

using namespace std;

char UserManager::selectOptionFromUserMenu() {
    char option;
    system("cls");
    cout << "  USER MENU " << endl;
    cout << endl;
    cout << "1. Add income " << endl;
    cout << "2. Add expense " << endl;
    cout << "3. View balance for current month " << endl;
    cout << "4. View balance for previous month " << endl;
    cout << "5. View balance for the selected period" << endl;
    cout << "6. Change password " << endl;
    cout << "7. Log out " << endl;
    cout << endl;
    cout << "Your choice: ";
    option = AuxiliaryMethod::getChar();

    return option;
}

char UserManager :: selectOptionFromMainMenu() {
    char option;
    system("cls");
    cout << "    MAIN MENU " << endl;
    cout << endl;
    cout << "1. Registration " << endl;
    cout << "2. Login " << endl;
    cout << "9. End " << endl;
    cout << endl;
    cout << "Your choice: ";
    option = AuxiliaryMethod::getChar();

    return option;
}

void UserManager::logOutUser() {
    loggedInUserId = 0;
}

bool UserManager::isUserLoggedIn() {
    if (loggedInUserId > 0)
        return true;
    else
        return false;
}

int UserManager::getLoggedInUserID() {
    return loggedInUserId;
}

bool UserManager::isLoginExists(string login) {
    for (int i = 0; i < users.size(); i++){
        if (users[i].getLogin() == login) {
            cout << endl << "This login already exists. Please enter a different login." << endl;
             return true;
        }
    }
    return false;
}

int UserManager::getNewUserId() {
        if (users.empty() == true)
        return 1;
    else
        return users.back().getUserId() + 1;
}

void UserManager::registerUser() {
    User user = getNewUserData();
    users.push_back(user);
    fileWithUsers.addUserToFile(user);
    cout << endl << "Your account was successfully created. Now please log in." << endl << endl;
    system("pause");
}

User UserManager::getNewUserData() {
    User user;
    string newName, newSurname;
    system("cls");
    cout << "REGISTRATION" << endl << endl;
    cout << "Please enter user details." << endl << endl;

    loggedInUserId = getNewUserId();
    user.setUserId(loggedInUserId);

    do {
            cout << "Enter login: ";
            user.setLogin(AuxiliaryMethod::getLine()); // bez obiektu, bezpoœrednio na klasie (metoda statyczna)
    } while (isLoginExists(user.getLogin()) == true);

        cout << "Enter password: ";
        user.setPassword(AuxiliaryMethod::getLine());
        cout << "Enter name: ";
        newName = AuxiliaryMethod::getLine();
        user.setName(AuxiliaryMethod::changeFirstLetterToCapitalAndOtherToLowercase(newName));
        cout << "Enter surname: ";
        newSurname = AuxiliaryMethod::getLine();
        user.setSurname(AuxiliaryMethod::changeFirstLetterToCapitalAndOtherToLowercase(newSurname));
    return user;
}

void UserManager::userLogIn() {
    User user;
    string login = "", password = "";
    system("cls");
    cout << "Please log in." << endl << endl;
    cout << endl << "Enter login: ";
    login = AuxiliaryMethod::getLine();

    vector <User>::iterator itr = users.begin();

    while (itr != users.end()) {
        if (itr -> getLogin() == login) {
            for (int numberOfTrial = 3; numberOfTrial > 0; numberOfTrial--) {
                cout << "Enter password. Left "  << numberOfTrial << " attempts.";
                password = AuxiliaryMethod::getLine();
                if (itr -> getPassword() == password) {
                    loggedInUserId = itr -> getUserId();
                    cout << endl << "You have successfully signed in." << endl << endl;
                    system("pause");
                    return ;
                }
            }
            cout << "You have entered 3 times incorrect password." << endl;
            system("pause");
            return ;
        }
        itr++;
    }
    cout << "There is no user with this login." << endl << endl;
    system("pause");
    return ;
}

void UserManager::changePassword() {
    string newPassword = "";
    cout << "Enter new password: ";
    newPassword = AuxiliaryMethod::getLine();
    bool isPasswordChanged = false;

    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++) {
        if (itr -> getUserId() == loggedInUserId) {
            itr -> setPassword(newPassword);
            isPasswordChanged = fileWithUsers.changeUserPassword(itr);
            if (isPasswordChanged)
                cout << "Your password has been successfully changed. Now please log in again." << endl << endl;
            system("pause");
            logOutUser();
        }
    }
}

