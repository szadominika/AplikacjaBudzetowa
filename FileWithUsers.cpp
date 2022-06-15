#include <iostream>
#include "FileWithUsers.h"
#include "Markup.h"

using namespace std;

void FileWithUsers::addUserToFile(User user) {

    CMarkup xml;
    string fileNameWithUsers = XmlFile :: getFileName();
    bool fileExists = xml.Load(fileNameWithUsers);

    if (!fileExists) {

        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem( "UserID", user.getUserId() );
    xml.AddElem( "Login", user.getLogin() );
    xml.AddElem( "Password", user.getPassword() );
    xml.AddElem( "Name", user.getName() );
    xml.AddElem( "Surname", user.getSurname() );

    xml.Save(fileNameWithUsers);

}


vector <User> FileWithUsers::loadUserFromFile() {

    User user;
    vector <User> users;

    CMarkup xml;

    if (fileExists(xml)) //(fileExists == true)
    {
        xml.FindElem();
        xml.IntoElem();
        while ( xml.FindElem("User") == true) {

            xml.IntoElem();
            xml.FindElem( "UserID");
            int userId = atoi(xml.GetData().c_str());
            user.setUserId(userId);
            xml.FindElem( "Login");
            string login = xml.GetData();
            user.setLogin(login);
            xml.FindElem( "Password");
            string password = xml.GetData();
            user.setPassword(password);
            xml.FindElem( "Name");
            string userName = xml.GetData();
            user.setName(userName);
            xml.FindElem( "Surname");
            string userSurname = xml.GetData();
            user.setSurname(userSurname);
            users.push_back(user);

            xml.OutOfElem();
        }
    }
    return users;
}

bool FileWithUsers::changeUserPassword(vector <User>::iterator itr) {

    CMarkup xml;
    string fileNameWithUsers = XmlFile :: getFileName();
    bool fileExists = xml.Load(fileNameWithUsers);

    if (fileExists == true) {

        xml.FindElem();
        xml.IntoElem();

        while(xml.FindElem("User"))
        {
            xml.IntoElem();
            xml.FindElem("UserID");
            int userId = AuxiliaryMethod::convertStringToInt(xml.GetData());
            if (userId == itr -> getUserId())
            {
            system("pause");
                xml.FindElem("Password");
                xml.SetData(itr -> getPassword());
                xml.Save(fileNameWithUsers);
                return true;
            }
            xml.OutOfElem();
        }
    }
    else
    {
        cout << "Cannot open the " << getFileName() << " file." << endl;
        return false;
    }

}

