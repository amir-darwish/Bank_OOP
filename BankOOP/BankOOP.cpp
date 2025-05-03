
#include <iostream>
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include "clsUtil.h"
#include "clsMainScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsLoginUser.h"
#include <iomanip>

using namespace std;



int main()
{
	//clsMainScreen::ShowMainMenue();
	while (true) {
		clsLoginUser::ShowLoginScreen();
	}
	
}

