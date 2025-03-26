#pragma once
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>

class clsBankClient :public clsPerson
{
private:
	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNew=3};
	enMode _Mode;

	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;

	static clsBankClient _ConvertLineToClientObject(string Line, string Seperator = "#//#") {

		vector<string>vClientData;
		vClientData = clsString::Split(Line, Seperator);

		return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2],
			vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));

	}

	static clsBankClient _GetEmptyClientObject() {
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	static vector <clsBankClient> _LoadClientDataFromFile() {
		vector <clsBankClient> vClients;
		fstream MyFile;

		MyFile.open("Clients.txt", ios::in);
		if (MyFile.is_open()) {
			string Line;
			while (getline(MyFile, Line)) {
				clsBankClient Client = _ConvertLineToClientObject(Line);
				vClients.push_back(Client);
			}
			MyFile.close();
		}
		return vClients;
	}
	static string _ConvertClientObjectToLine(clsBankClient Client, string Seperator = "#//#") {

		string stClientRecord = "";
		stClientRecord += Client.FirstName + Seperator;
		stClientRecord += Client.LastName + Seperator;
		stClientRecord += Client.Email + Seperator;
		stClientRecord += Client.Phone + Seperator;
		stClientRecord += Client.AccountNumber() + Seperator;
		stClientRecord += Client.PinCode + Seperator;
		stClientRecord += to_string(Client.AccountBalance);

		return stClientRecord;
	}
	static void _SaveClientsDataToFile(vector<clsBankClient> vClients) {
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out);

		if (MyFile.is_open()) {
			string DataLine;
			for (clsBankClient C : vClients) {
				DataLine = _ConvertClientObjectToLine(C);
				MyFile << DataLine << endl;
			}
			MyFile.close();
		}
	}
	void _AddNewDataLineToFile(string DataLine) {
		fstream MyFile;
		MyFile.open("Clients.txt", ios::app);
		if (MyFile.is_open()) {
			MyFile << DataLine << endl;
			MyFile.close();
		}
	}
	void _AddNew() {
		_AddNewDataLineToFile(_ConvertClientObjectToLine(*this));
	}
	void _Update() {
		vector <clsBankClient> vClients = _LoadClientDataFromFile();

		for (clsBankClient &C : vClients) {
			if (C.AccountNumber() == AccountNumber()) {
				C = *this; // this is the pointer to my updated object
				break;
			}
		}
		_SaveClientsDataToFile(vClients);
	}

public:
	clsBankClient(enMode Mode, string FirstName, string LastName,
		string Email, string Phone, string AccountNumber, string PinCode,
		float AccountBalance) :
		clsPerson(FirstName, LastName, Email, Phone) {
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
	}

	bool isEmpty() {
		return (_Mode == enMode::EmptyMode);
	}

	string AccountNumber() {
		return _AccountNumber;
	}

	void SetPinCode(string PinCode) {
		_PinCode = PinCode;
	}
	string GetPinCode() {
		return _PinCode;
	}
	__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;
	void SetAccountBalance(float AccountBalance) {
		_AccountBalance = AccountBalance;
	}

	float GetAccountBalance() {
		return _AccountBalance;
	}
	__declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;

	void Print() {
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << FirstName;
		cout << "\nLastName    : " << LastName;
		cout << "\nFull Name   : " << FullName();
		cout << "\nEmail       : " << Email;
		cout << "\nPhone       : " << Phone;
		cout << "\nAcc. Number : " << _AccountNumber;
		cout << "\nPassword    : " << _PinCode;
		cout << "\nBalance     : " << _AccountBalance;
		cout << "\n___________________\n";
	}

	static clsBankClient Find(string AccountNumber) {

		fstream MyFile;

		MyFile.open("Clients.txt",ios::in); // read mode

		if (MyFile.is_open()) {
			string Line;
			while (getline(MyFile, Line)) {
				clsBankClient Client = _ConvertLineToClientObject(Line);
				if (Client.AccountNumber() == AccountNumber) {
					MyFile.close();
					return Client;
				}
			}
			MyFile.close();
		}
		return _GetEmptyClientObject();
	}

	static clsBankClient Find(string AccountNumber, string PinCode) {
		fstream MyFile;

		MyFile.open("Clients.txt", ios::in); // read mode

		if (MyFile.is_open()) {
			string Line;
			while (getline(MyFile, Line)) {
				clsBankClient Client = _ConvertLineToClientObject(Line);
				if (Client.AccountNumber() == AccountNumber && Client.GetPinCode() == PinCode) {
					MyFile.close();
					return Client;
				}
			}
			MyFile.close();
		}
		return _GetEmptyClientObject();
	}

	static bool IsClienExist(string AccountNumber) {

		clsBankClient Client = Find(AccountNumber);
		return (!Client.isEmpty());
	}

	static clsBankClient GetAddNewClientObject(string AccountNumber) {
		
		return clsBankClient(enMode::AddNew, "", "", "", "", AccountNumber, "", 0);
	}

	enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildAccountNumberExist = 2 };

	enSaveResults Save() {
		switch (_Mode)
		{
		case clsBankClient::EmptyMode: {

			return enSaveResults::svFaildEmptyObject;
		}

		case clsBankClient::UpdateMode: {


			_Update();
			return enSaveResults::svSucceeded;

			break;
		}
		case clsBankClient::AddNew: {
			if (IsClienExist(AccountNumber())) {
				return enSaveResults::svFaildAccountNumberExist;
			}
			else {
				_AddNew();
				_Mode = UpdateMode;
				return svSucceeded;
			}
			break;
		}


		default:
			break;
		}
	}
	

};

