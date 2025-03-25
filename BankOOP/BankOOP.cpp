
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

void UpdateClient() {
    cout << "Please enter client account number : ";
    string AccountNumber = clsInputValidate::ReadString();
    while (!clsBankClient::IsClienExist(AccountNumber)) {
        cout << "Error Account Number is not found ! please enter again : ";
        AccountNumber = clsInputValidate::ReadString();
    }
    clsBankClient Client1 = clsBankClient::Find(AccountNumber);
    Client1.Print();
    cout << "\n\nUpdate Client Info:";
    cout << "\n____________________\n";
    ReadClientInfo(Client1);
    
    clsBankClient::enSaveResults SaveResults;

    SaveResults = Client1.Save();
    switch (SaveResults) {
    case clsBankClient::enSaveResults::svSucceeded: {
        cout << "\nAccount Updated Successfully :-)\n";
        Client1.Print();
        break;
    }
    case clsBankClient::enSaveResults::svFaildEmptyObject: {
        cout << "\nError account was not saved because it's Empty";
        break;
    }
    }

}
using namespace std;


int main()
{

    UpdateClient();
}

