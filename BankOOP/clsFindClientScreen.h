#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"

class clsFindClientScreen : protected clsScreen
{
private:
    void static _PrintClient(clsBankClient Client) {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.FirstName;
        cout << "\nLastName    : " << Client.LastName;
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.Email;
        cout << "\nPhone       : " << Client.Phone;
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nPassword    : " << Client.PinCode;
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";
    }
public:
    void static ShowFindClientScreen() {
        _DrawScreenHeader("\tFind Client Screen");

        string AccountNumber = "";
        cout << "Please enter account number to find :";
        AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber)) {
            cout << "Accoun Number not found ! Please try again : ";
            AccountNumber = clsInputValidate::ReadString();
        }
        clsBankClient C = clsBankClient::Find(AccountNumber);
        if (!C.IsEmpty()) {
            cout << "\nAccount Found :)\n";
        }
        else {
            cout << "\nAccount Not Found \n";

        }
        _PrintClient(C);
    }

};

