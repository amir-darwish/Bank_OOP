#pragma once
#include <iostream>
#include <iomanip>
#include "clsCurrency.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
class clsUpdateRateScreen : protected clsScreen
{
private:
	static void _PrintCurrency(clsCurrency Currency) {
		cout << "\nCurrency Card : \n";
		cout << "_______________________________\n";
		cout << "Country : " << Currency.Country() << endl;
		cout << "Code : " << Currency.CurrencyCode() << endl;
		cout << "Name : " << Currency.CurrencyName() << endl;
		cout << "Rate (1$) : " << Currency.Rate() << endl;
		cout << "_______________________________\n";
	}
public:
	static void ShowUpdateCurrencyScreen() {
		_DrawScreenHeader("\tUpdate Currency Screen");
		string CurrencyCode;
		cout << "Please enter currency code : ";
		CurrencyCode = clsInputValidate::ReadString();
		clsCurrency CurrencyToUpdate = clsCurrency::FindByCode(CurrencyCode);
		while (CurrencyToUpdate.IsEmpty()) {
			cout << "Currency Not Found , Try Again : ";
			CurrencyCode = clsInputValidate::ReadString();
			clsCurrency CurrencyToUpdate = clsCurrency::FindByCode(CurrencyCode);
		}
		_PrintCurrency(CurrencyToUpdate);
		char Answer = 'n';
		cout << "Are you sure you want update rate of this currency  ? y/n ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y') {
			double Rate;
			cout << "Please enter new rate : ";
			cin >> Rate;

			CurrencyToUpdate.UpdateRate(Rate);
			cout << "\nCurrency Updated Successfully\n";
			_PrintCurrency(CurrencyToUpdate);
		
		}
	}
};

