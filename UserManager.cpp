#include <iostream>

#include "UserManager.h"
#include "AuxiliaryMethods.h"

using namespace std;

char UserManager::selectOptionFromUserMenu() {
    char option;
    system("cls");
    cout << "  MENU UZYTKOWNIKA " << endl;
    cout << endl;
    cout << "1. Dodaj przychod " << endl;
    cout << "2. Dodaj wydatek " << endl;
    cout << "3. Bilans z biezacego miesiaca " << endl;
    cout << "4. Bilans z poprzedniego miesiaca  " << endl;
    cout << "5. Bilans z wybranego okresu " << endl;
    cout << "6. Zmien haslo" << endl;
    cout << "7. Wyloguj sie " << endl;
    cout << endl;
    cout << "Twoj wybor: ";
    option = AuxiliaryMethod::getChar();

    return option;
}

char UserManager :: selectOptionFromMainMenu() {
    char option;
    system("cls");
    cout << "    MENU GLOWNE" << endl;
    cout << endl;
    cout << "1. Rejestracja " << endl;
    cout << "2. Logowanie " << endl;
    cout << "9. Wyjscie z programu " << endl;
    cout << endl;
    cout << "Twoj wybor: ";
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
            cout << endl << "Ten login juz istnieje. Prosze wpisz inny." << endl;
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
    cout << endl << "Konto zostalo pomyslnie zalozone. Prosze sie zalogowac." << endl << endl;
    system("pause");
}

User UserManager::getNewUserData() {
    User user;
    string newName, newSurname;
    system("cls");
    cout << "REJESTRACJA" << endl << endl;
    cout << "Wprowadz dane uzytkownika." << endl << endl;

    loggedInUserId = getNewUserId();
    user.setUserId(loggedInUserId);

    do {
            cout << "Wprowadz login: ";
            user.setLogin(AuxiliaryMethod::getLine()); // bez obiektu, bezpoœrednio na klasie (metoda statyczna)
    } while (isLoginExists(user.getLogin()) == true);

        cout << "Wprowadz haslo: ";
        user.setPassword(AuxiliaryMethod::getLine());
        cout << "Wprowadz imie: ";
        newName = AuxiliaryMethod::getLine();
        user.setName(AuxiliaryMethod::changeFirstLetterToCapitalAndOtherToLowercase(newName));
        cout << "Wprowadz nazwisko: ";
        newSurname = AuxiliaryMethod::getLine();
        user.setSurname(AuxiliaryMethod::changeFirstLetterToCapitalAndOtherToLowercase(newSurname));
    return user;
}

void UserManager::userLogIn() {
    User user;
    string login = "", password = "";
    system("cls");
    cout << "Prosze sie zalogowac." << endl << endl;
    cout << endl << "Wprowadz login: ";
    login = AuxiliaryMethod::getLine();

    vector <User>::iterator itr = users.begin();

    while (itr != users.end()) {
        if (itr -> getLogin() == login) {
            for (int numberOfTrial = 3; numberOfTrial > 0; numberOfTrial--) {
                cout << "Wprowadz haslo. Zostalo "  << numberOfTrial << " proby logowania.";
                password = AuxiliaryMethod::getLine();
                if (itr -> getPassword() == password) {
                    loggedInUserId = itr -> getUserId();
                    cout << endl << "Jestes zalogowany." << endl << endl;
                    system("pause");
                    return ;
                }
            }
            cout << "Wprowadziles 3 razy bledne hasło. Sprobuj jeszcze raz." << endl;
            system("pause");
            return ;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika o takim loginie." << endl << endl;
    system("pause");
    return ;
}

void UserManager::changePassword() {
    string newPassword = "";
    cout << "Wprowadz nowe haslo: ";
    newPassword = AuxiliaryMethod::getLine();
    bool isPasswordChanged = false;

    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++) {
        if (itr -> getUserId() == loggedInUserId) {
            itr -> setPassword(newPassword);
            isPasswordChanged = fileWithUsers.changeUserPassword(itr);
            if (isPasswordChanged)
                cout << "Twoje haslo zostalo pomyslnie zmienione. Prosze zaloguj sie ponownie.." << endl << endl;
            system("pause");
            logOutUser();
        }
    }
}

