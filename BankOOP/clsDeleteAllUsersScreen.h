#pragma once
#include <iostream>
#include <string>
#include "clsString.h"
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include <vector>
#include "clsInputValidate.h"
#include "Global.h"
class clsDeleteAllUsersScreen:protected clsScreen
{
public:
	static void ShowDeleteAllUsersScreen() {
		
		vector<clsUser> vUsers = clsUser::GetUsersList();
		string Title = "Delete All Users Screen";
		_DrawScreenHeader(Title);
		char Answer = 'n';

		cout << "You Have " << to_string(vUsers.size() - 1) << " Users (excluding the current user) .\n";
		cout << "Are You Sure You Want To Delete All User ? y/n ";
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y') {
			if (clsUser::DeleteAllUsers(CurrentUser.UserName)) {
				cout << "All users have been successfully deleted.\n";
			}
			else {
				cout << "All users are still present — none have been deleted.";
			}
		}
	}
};

