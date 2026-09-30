#pragma once

#include"clsInputValidate.h"
#include<iomanip>

#include"clsUser.h"
#include"clsScreen.h"
#include"Global.h"
#include"clsListItemScreen.h";
#include"clsAddNewItemScreen.h"
#include"clsDeleteItemScreen.h"
#include"clsUpdateItemScreen.h"
#include"clsFindItemScreen.h"
#include "clsListItemsScreen.h"

using namespace std;

class clsInventoryManagementHomeScreen: protected clsScreen
{
private:
    enum enMainMenueOptions
    {
        eListItems = 1, eAddItem = 2,
        eDeleteItem = 3, eUpdateItem = 4,
        eFindItem = 5, eTransferBonds = 6, eLogout=7
    };
    static short _ReadMainSellingOption()
    {

        short Choice = clsInputValidate::ReadNumberBetween<short>(1, 7, "\n\t\t\t\t\tEnter Number Between 1 and 7 : ");



        return Choice;
    }

    static void _GetBackToMainMenue() {
        cout << setw(37) << left << " " << "\n\tPress any ky to go Main Menue...\n";
        system("pause>0");
        ShowMainInventoryMangement();

    }

    static void _ShowAllItemsScreen() {
        //cout << "\nAll Items Screen Will be here../\n"; 
        clsListItemScreen::ItemsList();

    }

    static void _ShowAddNewItemScreen() {
        // cout << "\nAdd New Item Screen Will be here../\n";

        clsAddNewItemScreen::AddNewItem();
    }

    static void _ShowDeleteItemScreen() {
       // cout << "\nDelete Item  Screen Will be here../\n";
        clsDeleteItemScreen::DeleteItemScreen();
    }
    static void _ShowUpdateItemScreen() {
        //cout << "\nUpdate Item Screen Will be here../\n";

        clsUpdateItemScreen::UpDateItem();
    }
    static void _ShowFindItemScreen() {

       // cout << "\nFind Item Screen Will be here../\n";
        clsFindItemScreen::FindItem();
    }
    static void _ShowTransferBondsScreen() {
        cout << "\nTransfer Bonds Screen Will be here../\n";

   }
   
    /* static void _ShowEndScreen() {
         cout << "\nEnd Screen Will be here...\n";
     }*/
    static  void _Login() {

    }
    static void _Logout() {
         CurrentUser = clsUser::Find("", "");

    }
    static  void _PerfromMainMenueSellingOption(enMainMenueOptions MainMenueOption)

    {

        switch (MainMenueOption)

        {

        case enMainMenueOptions::eListItems:

        {

            system("cls");

            _ShowAllItemsScreen();
            _GetBackToMainMenue();

            break;

        }

        case enMainMenueOptions::eAddItem:

            system("cls");

            _ShowAddNewItemScreen();

            _GetBackToMainMenue();

            break;



        case enMainMenueOptions::eDeleteItem:

            system("cls");

            _ShowDeleteItemScreen();

            _GetBackToMainMenue();

            break;



        case enMainMenueOptions::eUpdateItem:

            system("cls");

            _ShowUpdateItemScreen();

            _GetBackToMainMenue();

            break;



        case enMainMenueOptions::eFindItem:

            system("cls");

            _ShowFindItemScreen();

            _GetBackToMainMenue();

            break;

        case enMainMenueOptions::eTransferBonds:

            system("cls");

            _ShowTransferBondsScreen();

            _GetBackToMainMenue();

            break;

        case enMainMenueOptions::eLogout:
            try {
                system("cls");
              
            }
            catch (exception) {
                // clsLoginScreen::ShowLoginScreen();
            }
            break;

        }

    }

public:

    static void ShowMainInventoryMangement()

    {

        system("cls");

        
        _DrawScreenHeader("Inventory Mangement Screen");
        cout << left << setw(37) << " " << "===========================================\n";
        cout << left << setw(37) << " " << "Main  Selling Screen" << endl;
        cout << left << setw(37) << " " << "===========================================\n";

        cout << left << setw(37) << " " << "[1] Show Items List.\n";

        cout << left << setw(37) << " " << "[2] Add New Item.\n";

        cout << left << setw(37) << " " << "[3] Delete Item.\n";

        cout << left << setw(37) << " " << "[5] Find Item.\n";
       
        cout << left << setw(37) << " " << "[6} Tranfer Bonds.\n";

        cout << left << setw(37) << " " << "[7} Main Menue.\n";

        cout << left << setw(37) << " " << "===========================================\n";

        _PerfromMainMenueSellingOption((enMainMenueOptions)_ReadMainSellingOption());

    }

};

