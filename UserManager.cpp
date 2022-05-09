#include <iostream>
#include "UserManager.h"
#include "AuxiliaryMethods.h"

using namespace std;



char UserManager::selectOptionFromUserMenu() {

    char option;
   // AuxiliaryMethod auxiliaryMethod;
    system("cls");
    cout << " >>> USER MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Add income" << endl;
    cout << "2. Add expense" << endl;
    cout << "3. Display balance for current month" << endl;
    cout << "4. Display balance for previous month" << endl;
    cout << "5. Display balance for selected period" << endl;
    cout << "6. Change password" << endl;
    cout << "7. Log out" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    option = AuxiliaryMethod::getChar();

    return option;
}

void UserManager::logOffUser() {

    loggedInUserId = 0;

}

bool UserManager::isUserLoggedIn() {

    if (loggedInUserId > 0)
        return true;
    else
        return false;

}

int UserManager::getIdLoggedUser() {

    return loggedInUserId;

}

void UserManager::showAllUsers() {

    for (int i = 0; i < users.size(); i++) {
        cout << "User ID: " << users[i].getUserId() << endl;
        cout << "Login: " << users[i].getLogin() << endl;
        cout << "Password: " << users[i].getPassword() << endl;
        cout << "User name: " << users[i].getName() << endl;
        cout << "User surname: " << users[i].getSurname() << endl << endl;
    }
}

bool UserManager::isLoginExists(string login) {

    for (int i = 0; i < users.size(); i++){

        if (users[i].getLogin() == login)
        {
            cout << endl << "This login already exists." << endl;
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
    //FileWithUsers fileWithUsers;
    users.push_back(user);
    fileWithUsers.addUserToFile(user);
    cout << endl << "Account created" << endl << endl;
    system("pause");
}

User UserManager::getNewUserData() {

    User user;
    string newName, newSurname;

    user.setUserId(getNewUserId());

    do {
        cout << "Enter login: ";

       user.setLogin(AuxiliaryMethod::getLine()); // bez obiektu, bezpoœrednio na klasie (metoda statyczna)
    } while (isLoginExists(user.getLogin()) == true);

        cout << "Enter password ";
        user.setPassword(AuxiliaryMethod::getLine());

        cout << "Enter name ";
        newName = AuxiliaryMethod::getLine();
        user.setName(AuxiliaryMethod::changeFirstLetterToCapitalAndOtherToLowercase(newName));

        cout << "Enter surname ";
        newSurname = AuxiliaryMethod::getLine();
        user.setSurname(AuxiliaryMethod::changeFirstLetterToCapitalAndOtherToLowercase(newSurname));

    return user;
}

int UserManager::userLogIn() {

    User user;
    string login = "", password = "";

    cout << endl << "Enter login ";
    login = AuxiliaryMethod::getLine();

    vector <User>::iterator itr = users.begin();
    while (itr != users.end())
    {
        if (itr -> getLogin() == login)
        {
            for (int numberOfTrial = 3; numberOfTrial > 0; numberOfTrial--)
            {
                cout << "Enter password. You have: " << numberOfTrial << " left: ";
                password = AuxiliaryMethod::getLine();

                if (itr -> getPassword() == password)
                {
                    loggedInUserId = itr -> getUserId();
                    cout << endl << "You logged successfully" << endl << endl;
                    system("pause");
                    return loggedInUserId;

                }
            }
            cout << "You have entered 3 times incorrect password" << endl;
            system("pause");
            return 0;
        }
        itr++;
    }
    cout << "There is no user with this login" << endl << endl;

    system("pause");
    return 0;
}
