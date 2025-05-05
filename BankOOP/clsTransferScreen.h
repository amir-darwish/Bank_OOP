#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include <iomanip>
class clsTransferScreen:protected clsScreen
{
private:
    void static _PrintClient(clsBankClient Client) {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";
    }
    static string _ReadAcoountNumber() {

        cout << "Please enter account number : ";
        string AccNum = clsInputValidate::ReadString();
        return AccNum;
    }
public:
    static void ShowTransferScreen() {
        _DrawScreenHeader("Transfer Screen");

        cout << "Please Enter Account Number to Transfer From : ";
        string AccNum = "";
        AccNum = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccNum)) {
            cout << " Error Not Found , Please Enter Account Number to Transfer From : ";
            AccNum = clsInputValidate::ReadString();
        }
        clsBankClient TransferFrom = clsBankClient::Find(AccNum);

        _PrintClient(TransferFrom);


        cout << "Please Enter Account Number to Transfer TO : ";
        AccNum = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccNum)) {
            cout << " Error Not Found , Please Enter Account Number to Transfer TO : ";
            AccNum = clsInputValidate::ReadString();
        }
        clsBankClient TransferTO = clsBankClient::Find(AccNum);

        _PrintClient(TransferTO);

        double Amount = 0;
        cout << "Please Enter Amount To Transfer it ? ";
        Amount = clsInputValidate::ReadDblNumber();

        while (TransferFrom.GetAccountBalance() < Amount){
            cout << "Amount Exceeds the available Balance, Enter another amount ? ";
            Amount = clsInputValidate::ReadDblNumber();
        }
        char Answer = 'n';
        cout << "Are you sure you want to perform this operation? y/n?";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y') {

            if (TransferFrom.Transfer(Amount,TransferTO) && (TransferFrom.AccountNumber() != TransferTO.AccountNumber())) {
                cout << "Transfer Done Successfully .\n";
                _PrintClient(TransferFrom);
                _PrintClient(TransferTO);
            }
            else {
                cout << "Error Check And Try Again !";
            }
            
        }


    }
};

