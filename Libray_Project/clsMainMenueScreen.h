#pragma once
#include <iostream>
#include <iomanip>
#include"clsInputValidate.h";
#include"clsScreen.h";
#include"clsInventoryManagementHomeScreen.h"
#include"clsManageUsersMenueScreen.h"
#include"clsMainSalesSellerScreen.h"
#include "clsMainAutherScreen.h"
#include"clsPendingOrdersScreen.h"

using namespace std; 
class clsMainMenueScreen: protected clsScreen
{

private:

    static  short _ReadMainMenueOption()
    {

        short Choice = clsInputValidate::ReadNumberBetween<short>(1, 6, "Choose what do you want to do? [1 to 6]? ");


        return Choice;
    }
    enum _enMainMenueOptions {
        eManageUsers = 1, eInventoryManagment = 2, AuthorWindow = 3,
        eSellerWindow = 4, ePendingOrders=5, eLogout = 6
    };
    static void _GetBackToMainMenue() {
        cout << setw(37) << left << " " << "\n\tPress any ky to go Main Manger Menue...\n";
        system("pause>0");
        ShowMainMenue();

    }
    static void _ShowManageUsersScreen() {
        clsManageUsersMenueScreen::ShowManageUsersMenue();
    }
    static void _ShowInventoryManagmentScreen() {
        clsInventoryManagementHomeScreen::ShowMainInventoryMangement();
    }
    static void _ShowAuthorWindowScreen() {
        clsMainAutherScreen::ShowMainAutherMenue();
    }
    static void _ShowSellerWindowScreen() {
        clsMainSalesSellerScreen::ShowMainSalesSeller();
    }
    static void _ShowPendingOrdersScreen() {
      //  cout << "\n Peding Orders it is Not her.\n";
        clsPendingOrdersScreen::ShowPendingOrdersMenue();
    }
    static void _Logout() {
        CurrentUser = clsUser::Find("", "");

    }

    static  void _PerfromMainMenueOptiothern(_enMainMenueOptions MainMenueOption)

    {

        switch (MainMenueOption)

        {

        case _enMainMenueOptions::eManageUsers:

        {

            system("cls");

             _ShowManageUsersScreen();
            _GetBackToMainMenue();

            break;

        }



        case _enMainMenueOptions::eInventoryManagment:

            system("cls");

            _ShowInventoryManagmentScreen();
            _GetBackToMainMenue();
            break;


        case _enMainMenueOptions::AuthorWindow:

        {

            system("cls");

            _ShowAuthorWindowScreen();
            _GetBackToMainMenue();

            break;

        }
        case _enMainMenueOptions::ePendingOrders:

        {

            system("cls");

            _ShowPendingOrdersScreen();
            _GetBackToMainMenue();

            break;

        }


        case _enMainMenueOptions::eSellerWindow:

            system("cls");

            _ShowSellerWindowScreen();
            _GetBackToMainMenue();
            break;


        case _enMainMenueOptions::eLogout:
            try {
                system("cls");
              
                    _Logout();
                
            }
            catch (exception) {
                // clsLoginScreen::ShowLoginScreen();
            }
            break;

        }

    }
public :
    static void ShowMainMenue() {


        system("cls");


        _DrawScreenHeader("Main  Menue Screen");
        cout << left << setw(37) << " " << "===========================================\n";
        cout << left << setw(37) << " " << "Main  Menue Screen" << endl;
        cout << left << setw(37) << " " << "===========================================\n";

        cout << left << setw(37) << " " << "[1] Manage Users.\n";

        cout << left << setw(37) << " " << "[2] Inventory Managment.\n";

        cout << left << setw(37) << " " << "[3] Author Window.\n";

        cout << left << setw(37) << " " << "[4] Seller Window.\n";

        cout << left << setw(37) << " " << "[5] Pending Orders.\n";

        cout << left << setw(37) << " " << "[6} Logout.\n";

       

        cout << left << setw(37) << " " << "===========================================\n";

        _PerfromMainMenueOptiothern((_enMainMenueOptions)_ReadMainMenueOption());

    }
};

