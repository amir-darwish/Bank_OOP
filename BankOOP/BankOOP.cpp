
#include <iostream>
#include "clsInputValidate.h"

#include "clsBankClient.h"


void DeleteClient() {
    cout << "Please enter client account number : ";
    string AccountNumber = clsInputValidate::ReadString();
    while (!clsBankClient::IsClienExist(AccountNumber)) {
        cout << "Error Account Number is not found ! please enter again : ";
        AccountNumber = clsInputValidate::ReadString();
    }
    clsBankClient Client1 = clsBankClient::Find(AccountNumber);
    Client1.Print();

    cout << "\nAre you sure you want delete it y or n ? ";
    char Answer = 'n';
    cin >> Answer;
    if (Answer == 'y') {
        Client1.Delete();
    }
    Client1.Print();


}
using namespace std;


int main()
{

    DeleteClient();
}

