#pragma once
#include<iostream>
#include<iomanip>

#include"clsInputValidate.h"
#include"clsScreen.h"
#include"clsUpdateAuthortScreen.h"

#include"clsTransactoinsScreen.h"

#include"Global.h"
using namespace std;

class clsMainAutherScreen:protected clsScreen
{

protected:
    enum enMainAutherOptions
    {
         eTransactions = 1, eUpdateProfile = 2, eLogout = 3
    };


    static short _ReadMainMenueOption()
    {

        short Choice = clsInputValidate::ReadNumberBetween<short>(1, 3, "\n\t\t\t\t\tEnter Number Between 1 and 3 : ");



        return Choice;
    }


    static void _GetBackToMainMenue() {
        cout << setw(37) << left << " " << "\n\tPress any ky to go Main Menue...\n";
        system("pause>0");
        ShowMainAutherMenue();

    }enum _enUseres { eManager = 'M', eAuthers = 'A', eSalesMan = 'S' };


    static void _ShowUpdateProfileScreen() {

         //cout << "\nFind Client Screen Will be here../\n";
        clsUpdateAuthortScreen::ShowUpdatAuthor();
    }
    static void _ShowTransactoinsMenue() {
        /*    cout << "\ntransactoins menue screen will be here../\n";*/
        clsTransactoinsScreen::ShowTransactionsMenue();


    }
   /* static   void _ShowManageUsersMenue() {
       cout << "\nUsers Menue Screen Will be here../\n";
        clsManageUsersMenueScreen::ShowManageUsersMenue();
    }*/
    /* static void _ShowEndScreen() {
         cout << "\nEnd Screen Will be here...\n";
     }*/
    static  void _Login() {

    }
    static void _Logout() {
        CurrentUser = clsUser::Find("", "");

    }
    static  void _PerfromMainAuOptiothern(enMainAutherOptions MainMenueOption)

    {

        switch (MainMenueOption)

        {

        case enMainAutherOptions::eUpdateProfile:

        {

            system("cls");

            _ShowUpdateProfileScreen();
            _GetBackToMainMenue();

            break;

        }

    

        case enMainAutherOptions::eTransactions:

            system("cls");

            _ShowTransactoinsMenue();
            _GetBackToMainMenue();
            break;

      
        case enMainAutherOptions::eLogout:
            try {
                system("cls");
                if (to_string(_enUseres::eAuthers) ==  CurrentUser.CurrentPosition) {
                    _Logout();
                }
            }
            catch (exception) {
                // clsLoginScreen::ShowLoginScreen();
            }
            break;

        }

    }

public:

    static void ShowMainAutherMenue()

    {

        system("cls");


        _DrawScreenHeader("Main Menue");
        cout << left << setw(37) << " " << "===========================================\n";
        cout << left << setw(37) << " " << "Main Menue" << endl;
        cout << left << setw(37) << " " << "===========================================\n";

        cout << left << setw(37) << " " << "[1] Transactions.\n";
       
        cout << left << setw(37) << " " << "[2] Update Profile.\n";

   

        cout << left << setw(37) << " " << "[3] Logout.\n";

        cout << left << setw(37) << " " << "===========================================\n";

        _PerfromMainAuOptiothern((enMainAutherOptions)_ReadMainMenueOption());

    }

};

