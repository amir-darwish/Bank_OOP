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
	static void _Login() {

		bool LoginFaild = false;
		string Username = "";
		string Password = "";
		do {
			if (LoginFaild) {
				cout << "\nInvlaid Username/Password!\n\n";
			}
			cout << "Please Enter your Username : ";
			Username = clsInputValidate::ReadString();

			cout << "\nPlease Enter your Password : ";
			Password = clsInputValidate::ReadString();

			CurrentUser = clsUser::Find(Username, Password);
			
			LoginFaild = CurrentUser.IsEmpty();

		}while (LoginFaild);

		clsMainScreen::ShowMainMenue();
	}
public:

	static void ShowLoginScreen() {
		system("cls");
		_DrawScreenHeader("\t  Login Screen");
		_Login();
	}
};

