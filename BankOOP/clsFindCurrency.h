#pragma once
#include <iostream>
#include <iomanip>
#include "clsCurrency.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
class clsFindCurrency : protected clsScreen
{
private :
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
	static void ShowFindCurrencyScreen() {
		_DrawScreenHeader("\tFind Currency Screen");
		
		short choix = 0;
		cout << "Find By : [1] Country Or [2] Code ? ";
		choix = clsInputValidate::ReadIntNumberBetween(1, 2);

		if (choix == 1) {
			string CountryName;
			cout << "Please enter country name : ";
			CountryName = clsInputValidate::ReadString();

			clsCurrency Currency = clsCurrency::FindByCountry(CountryName);
			if (!Currency.IsEmpty()) {
				cout << "\nCurrency Found ! \n";
				_PrintCurrency(Currency);
			}
			else {
				cout << "\nCurrency Is Not Found ! \n";

			}
		}
		else if (choix == 2) {
			string CountryCode;
			cout << "Please enter country code : ";
			CountryCode = clsInputValidate::ReadString();

			clsCurrency Currency = clsCurrency::FindByCode(CountryCode);
			if (!Currency.IsEmpty()) {
				cout << "Currency Found ! \n";
				_PrintCurrency(Currency);
			}
			else {
				cout << "Currency Is Not Found ! \n";

			}
		}
	}
};

