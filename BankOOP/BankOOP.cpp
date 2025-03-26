
#include <iostream>
#include "clsInputValidate.h"

#include "clsBankClient.h"
void ReadClientInfo(clsBankClient& Client)
{       
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
}

void AddNewClient() {
    cout << "Please enter client account number : ";
    string AccountNumber = clsInputValidate::ReadString();
    while (clsBankClient::IsClienExist(AccountNumber)) {
        cout << "Error Account Number is exist ! please enter again : ";
        AccountNumber = clsInputValidate::ReadString();
    }
   
    clsBankClient Client1 = clsBankClient::GetAddNewClientObject(AccountNumber);
    ReadClientInfo(Client1);

    clsBankClient::enSaveResults SaveResults;

    SaveResults = Client1.Save();
    switch (SaveResults) {
    case clsBankClient::enSaveResults::svSucceeded: {
        cout << "\nAccount Added Successfully :-)\n";
        Client1.Print();
        break;
    }
    case clsBankClient::enSaveResults::svFaildEmptyObject: {
        cout << "\nError account was not saved because it's Empty";
        break;
    }
    case clsBankClient::svFaildAccountNumberExist: {
        cout << "\nError account was not saved because it's exist";
        break;
    }
    }

}
using namespace std;


int main()
{

    AddNewClient();
}

