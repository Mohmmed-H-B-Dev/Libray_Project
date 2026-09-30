#pragma once
#include <iostream>
#include <iomanip>
#include"clsInputValidate.h";
#include"clsScreen.h";
#include"clsListUsersScreen.h";
#include"clsAddNewUserScreen.h";
#include"clsDeleteUserScreen.h";
#include"clsUdateUserScreen.h";
#include"clsFindUserScreen.h";
#include"clsMainSalesSellerScreen.h"
using namespace std;
class clsManageUsersMenueScreen :clsScreen
{
private:

    static  short _ReadManageUsersMenueOption()
    {

        short Choice = clsInputValidate::ReadNumberBetween<short>(1, 6, "Choose what do you want to do? [1 to 6]? ");


        return Choice;
    }
    enum _enManageUsersMenueOptions {
        eListUsers = 1, eAddNewUser = 2, eDeleteUser = 3,
        eUpdateUser = 4, eFindUser = 5, eMainMenue = 6
    };
    static void _GetBackToManageMenue() {
        cout << setw(37) << left << " " << "\n\tPress any ky to go Main Manger Menue...\n";
        system("pause>0");
        ShowManageUsersMenue();

    }

    static  void _ShowListUsersScreen() {
        //cout << "\nList Users Screen Will be here../\n";
        clsListUsersScreen::ShowUsersList();

    }
    static void _ShowAddNewUserScreen() {
        // cout << "\nAdd New Users Screen Will be here../\n";
        clsAddNewUserScreen::AddNewUser();
    }
    static void _ShowDeleteUserScreen() {
        //cout << "\nDelete Users Screen Will be here../\n
        clsDeleteUserScreen::ShowDeleteClient();
    }

    static void _ShowUpdateUserScreen() {

        //cout << "\nUpdate Users Screen Will be here../\n";
        clsUdateUserScreen::ShowUpdatUser();
    }
    static void _ShowFindUserScreen() {
        // cout << "\nFind Users Screen Will be here../\n";
        clsFindUserScreen::ShowFindUser();
    }
  
    static  void _PerfromManageUsersMenueOption(_enManageUsersMenueOptions ManageUsersMenueOption)
    {
        switch (ManageUsersMenueOption)
        {
        case _enManageUsersMenueOptions::eListUsers:
        {
            system("cls");
            _ShowListUsersScreen();
            _GetBackToManageMenue();
            break;
        }

        case _enManageUsersMenueOptions::eAddNewUser:
        {
            system("cls");
            _ShowAddNewUserScreen();
            _GetBackToManageMenue();
            break;
        }

        case _enManageUsersMenueOptions::eDeleteUser:
        {
            system("cls");
            _ShowDeleteUserScreen();
            _GetBackToManageMenue();
            break;
        }

        case _enManageUsersMenueOptions::eUpdateUser:
        {
            system("cls");
            _ShowUpdateUserScreen();
            _GetBackToManageMenue();
            break;
        }

        case _enManageUsersMenueOptions::eFindUser:
        {
            system("cls");

            _ShowFindUserScreen();
            _GetBackToManageMenue();
            break;
        }


    
        case _enManageUsersMenueOptions::eMainMenue:
        {
           
        }
        }

    }

public:
    static void ShowManageUsersMenue()
    {

        /*  if (!CheckAccessPermission(enMainMenuePermissions::pManageUsers))
          {
              ShowAccessDeniedMessage();
              GoBackToMainMenue();
              return;
          }*/

        system("cls");

        if (!CheckAccessReghts(clsUser::enPermissions::pManageUsers)) {

            return;
        }
        _DrawScreenHeader("Manage Users Menue Screen");
        cout << left << setw(37) << " " << "===========================================\n";
        cout << left << setw(37) << " " << "Manage Manger Menue Screen" << endl;
        cout << left << setw(37) << " " << "===========================================\n";

        cout << left << setw(37) << " " << "[1] Show User List.\n";

        cout << left << setw(37) << " " << "[2] Add New User.\n";

        cout << left << setw(37) << " " << "[3] Delete User.\n";

        cout << left << setw(37) << " " << "[4] Update User Info.\n";

        cout << left << setw(37) << " " << "[5] Find User.\n";

        cout << left << setw(37) << " " << "[6] Main Menue.\n";


        cout << left << setw(37) << " " << "===========================================\n";





        _PerfromManageUsersMenueOption((_enManageUsersMenueOptions)_ReadManageUsersMenueOption());
    }

};

