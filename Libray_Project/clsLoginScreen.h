#pragma once
#include<iostream>
#include"clsUser.h"
#include"clsScreen.h";
#include "Global.h"
#include"clsMainAutherScreen.h"
#include"clsMainMenueScreen.h"
class clsLoginScreen :protected clsScreen
{
private:
	enum _enUseres{eManager='M',eAuthers='A',eSalesMan='S' };
	static bool _Login() {
		string UserName, Password;
		bool LoginFaild = false;
		short FaildLoginCount = 0;


		do {

			if (LoginFaild) {
				FaildLoginCount++;
				cout << "\nInvlaid UserName / Password ...\n\n";
				cout << "\nYou Have [" << 3 - FaildLoginCount
					<< "] \Trials to loing...\n\n";
			}
			if (FaildLoginCount == 3) {
				cout << "\nYour are locked after 3 faild trils \n\n";
				return false;
			}
			cout << "\nEnter User Name? ";
			cin >> UserName;

			cout << "\nEnter Password? ";
			cin >> Password;
			CurrentUser = clsUser::Find(UserName, Password);

			LoginFaild = CurrentUser.IsEmpty();

			

		} while (LoginFaild);
		CurrentUser.RegisterLogIn();

		if (UserName == "Admin") {
			clsMainMenueScreen::ShowMainMenue();
			return true;
	}
		char CurrentPosition = clsString::GetFirstLetterOfEachWord(CurrentUser.CurrentPosition);
			
			switch (toupper(CurrentPosition))
			{
			case clsLoginScreen::eManager:
				clsMainMenueScreen::ShowMainMenue();
				return true;
				break;
			case clsLoginScreen::eAuthers:
				clsMainAutherScreen::ShowMainAutherMenue();
				return true;
				break;
			case clsLoginScreen::eSalesMan:
				return true;
				break;
			default:
				break;
			}
	

		return false;
	}


public:
	static bool ShowLoginScreen() {

		_DrawScreenHeader("Login Screen");
		return _Login();


	}

};

