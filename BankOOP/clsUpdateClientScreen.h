#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
class clsUpdateClientScreen:protected clsScreen
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
    void static _ReadClientInfo(clsBankClient& Client) {
        cout << "\nEnter FirstName: ";
        Client.FirstName = clsInputValidate::ReadString();

        cout << "\nEnter LastName: ";
        Client.LastName = clsInputValidate::ReadString();

        cout << "\nEnter Email: ";
        Client.Email = clsInputValidate::ReadString();

        cout << "\nEnter Phone: ";
        Client.Phone = clsInputValidate::ReadString();

        cout << "\nEnter PinCode: ";
        Client.PinCode = clsInputValidate::ReadString();

        cout << "\nEnter Account Balance: ";
        Client.AccountBalance = clsInputValidate::ReadFloatNumber();
    };
public:

    void static ShowUpdateClientScreen() {
        if (!CheckAccessRights(clsUser::pUpdateClients)) {
            return;
        }
        _DrawScreenHeader("\tUpdate Client Screen");

        string AccountNumber = "";
        cout << "Please enter account number to update :";
        AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber)) {
            cout << "Accoun Number not found ! Please try again : ";
            AccountNumber = clsInputValidate::ReadString();
        }
        clsBankClient Client = clsBankClient::Find(AccountNumber);
        _PrintClient(Client);

        cout << "\nAre you sure you want to update this client y/n? ";
        char answer = 'n';
        cin >> answer;
        if (answer == 'y' || answer == 'Y') {

            cout << "\n\nUpdate Client Info:";
            cout << "\n____________________\n";

            _ReadClientInfo(Client);
            clsBankClient::enSaveResults SaveResult = Client.Save();
            switch (SaveResult)
            {
                case  clsBankClient::enSaveResults::svSucceeded:
                {
                    cout << "\nAccount Addeded Successfully :-)\n";
                    _PrintClient(Client);
                    break;
                }
                case clsBankClient::enSaveResults::svFaildEmptyObject:
                {
                    cout << "\nError account was not saved because it's Empty";
                    break;

                }
                case clsBankClient::enSaveResults::svFaildAccountNumberExists:
                {
                    cout << "\nError account was not saved because account number is used!\n";
                    break;

                }
            }
        }
    }

};

