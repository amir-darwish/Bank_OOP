#pragma once
#include <iostream>
#include <string>
#include "clsString.h"
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include <vector>
#include "clsInputValidate.h"
class clsDeleteUserScreen:protected clsScreen
{
private:
    static void _PrintUser(clsUser User)
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.FirstName;
        cout << "\nLastName    : " << User.LastName;
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.Email;
        cout << "\nPhone       : " << User.Phone;
        cout << "\nUser Name   : " << User.UserName;
        cout << "\nPassword    : " << User.Password;
        cout << "\nPermissions : " << User.Permissions;
        cout << "\n___________________\n";

    }

public:
    static void ShowDeleteScreen() {
        _DrawScreenHeader("Delete User Screen");
        string UserName = "";
        cout << "Please enter username for delete it :";
        UserName = clsInputValidate::ReadString();
        while (!clsUser::IsUserExist(UserName)) {
            cout << "User not found , please try again : ";
            UserName = clsInputValidate::ReadString();
        }
        clsUser NewUser = clsUser::Find(UserName);

        _PrintUser(NewUser);

        char answer = 'n';
        cout << "Are you want delete this user ? y/n";
        cin >> answer;
        if (answer == 'Y' || answer == 'y') {
            if (NewUser.Delete()) {
                cout << "\nDeleted Successfully \n";
                _PrintUser(NewUser);

            }
            else {
                cout << "\nError !! Try again \n";

            }

        }
    }
};

