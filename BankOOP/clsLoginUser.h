#pragma once
#include <iostream>
#include <string>
#include "clsString.h"
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsInputValidate.h"
#include "Global.h"
#include "clsMainScreen.h"


class clsLoginUser:protected clsScreen
{

private :
	static bool _Login() {

		bool LoginFaild = false;
		short FaildLoginCount = 0;
		string Username = "";
		string Password = "";
		do {
			if (LoginFaild) {
				FaildLoginCount++;
				cout << "\nInvlaid Username/Password!\n\n";
				cout << "\nYou have " << (3 - FaildLoginCount)
					<< " Trial(s) to login.\n\n";
			}
			if (FaildLoginCount == 3) {

				cout << "\nYour are Locked after 3 faild trails \n\n";
				return false;

			}
			cout << "Please Enter your Username : ";
			Username = clsInputValidate::ReadString();

			cout << "Please Enter your Password : ";
			Password = clsInputValidate::ReadString();

			CurrentUser = clsUser::Find(Username, Password);
			
			LoginFaild = CurrentUser.IsEmpty();

		}while (LoginFaild);

		clsMainScreen::ShowMainMenue();
		return true;
	}
public:

	static bool ShowLoginScreen() {
		system("cls");
		_DrawScreenHeader("\t  Login Screen");
		return _Login();
	}
};

