#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include <iomanip>

class clsWithdrawScreen:protected clsScreen
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
    static string _ReadAcoountNumber() {

        cout << "Please enter account number : ";
        string AccNum = clsInputValidate::ReadString();
        return AccNum;
    }
public:


    static void ShowWithdrawScreen() {

        _DrawScreenHeader("\Withdraw Amount Screen");

        string AccountNum = _ReadAcoountNumber();

        while (!clsBankClient::IsClientExist(AccountNum)) {
            cout << "Client is not found try again :\n";
            AccountNum = _ReadAcoountNumber();

        }
        clsBankClient C = clsBankClient::Find(AccountNum);

        _PrintClient(C);
        cout << "\nHow much you want to perform this transaction ?";
        double Amount = clsInputValidate::ReadDblNumber();

        char answer = 'n';
        cout << "Are you sure you want add this amount ? y/n ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y') {
            if (C.Withdraw(Amount))
            {
                cout << "\nAmount Withdrew Successfully.\n";
                cout << "\nNew Balance Is: " << C.AccountBalance;
            }
            else
            {
                cout << "\nCannot withdraw, Insuffecient Balance!\n";
                cout << "\nAmout to withdraw is: " << Amount;
                cout << "\nYour Balance is: " << C.AccountBalance;
            }

        }
        else {
            cout << "Operation was cancelled";
        }
    }

};

