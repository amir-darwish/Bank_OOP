#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
class clsDeleteClientScreen : protected clsScreen {
private :
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
    void static ShowDeleteClientScreen() {
        _DrawScreenHeader("\tDelete Client Screen");
        string AccountNumber = "";
        char Answer = 'n';
        cout << "Please enter the account number to delete it ? ";
        AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber)) {
            cout << "\nAccount number is not exist, please enter account number again again : ";
            AccountNumber = clsInputValidate::ReadString();
        }
        clsBankClient Client = clsBankClient::Find(AccountNumber);
        _PrintClient(Client);

        cout << "Are you sure you want delete it  ? y/n : ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y') {
            Client.Delete();
            cout << "\nDelete Done :)\n";
            _PrintClient(Client);
        }
       

    }
};

