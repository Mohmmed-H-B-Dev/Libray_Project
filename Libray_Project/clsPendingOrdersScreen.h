#pragma once
#include<iostream>
#include"clsUser.h"
#include"clsScreen.h";
#include "Global.h"
#include"clsListPendingOrdersScreen.h"
#include"clsMainMenueScreen.h"
#include"clsAddBookOrderScreen.h"
using namespace std;

class clsPendingOrdersScreen:protected clsScreen
{
//	ÌÊÃœ ŒÌ«—Ì‰ ›Ì ‘«‘… «·ÿ·»«  «·„‰ ÿ—…  
	//	1 ·Ì «÷«›… ⁄‰’— Ê«Õœ »”
		//2 ·Ì «÷«›… ﬂ· «·⁄‰«’— «· Ì ›Ì „·› «·ÿ·»«  «·„‰ ÿ—… «·Ì „·› («·⁄‰«’— ) 

private:

    static  short _ReadPendingOrdersMenueOption()
    {

        short Choice = clsInputValidate::ReadNumberBetween<short>(1, 4, "Choose what do you want to do? [1 to 4]? ");


        return Choice;
    }
    enum _enPendingOrdersMenueOptions {
        eListOrders = 1, eAddOrder = 2, eAddAllOrders = 3,eMainMenue=4
      
    };
    static void _GetBackToPendingOrdersMenue() {
        cout << setw(37) << left << " " << "\n\tPress any ky to go Main Manger Menue...\n";
        system("pause>0");
        ShowPendingOrdersMenue();

    }
    static void _ShowListPendingOrdersMenue() {
        clsListPendingOrdersScreen::ShowPedingBooks();

    }
    static void _ShowAddOrderMenue() {
        clsAddBookOrderScreen::ShowAddBookFromPendingOrders();
    }
    static void _ShowAddAllPendingOrdersMenue() {

    }

    static  void _PerfromMainMenueOptiothern(_enPendingOrdersMenueOptions PendingOrdersOption)

    {

        switch (PendingOrdersOption)

        {

        case _enPendingOrdersMenueOptions::eListOrders:

        {

            system("cls");

            _ShowListPendingOrdersMenue();
            _GetBackToPendingOrdersMenue();

            break;

        }

        case _enPendingOrdersMenueOptions::eAddOrder:

        {

            system("cls");

            _ShowAddOrderMenue();
            _GetBackToPendingOrdersMenue();

            break;

        }

        case _enPendingOrdersMenueOptions::   eAddAllOrders:

        {

            system("cls");

            _ShowAddAllPendingOrdersMenue();
            _GetBackToPendingOrdersMenue();

            break;

        }

        case _enPendingOrdersMenueOptions:: eMainMenue:

        {
      

        }

        }
    }
public:
    static void ShowPendingOrdersMenue() {

        system("cls");


        _DrawScreenHeader("Main  Menue Screen");
        cout << left << setw(37) << " " << "===========================================\n";
        cout << left << setw(37) << " " << "Main  Menue Screen" << endl;
        cout << left << setw(37) << " " << "===========================================\n";

        cout << left << setw(37) << " " << "[1] List Orders.\n";

        cout << left << setw(37) << " " << "[2] Approve a Request.\n";

        cout << left << setw(37) << " " << "[3] Approve All Requests.\n";

        cout << left << setw(37) << " " << "[4] Main Menue.\n";

        cout << left << setw(37) << " " << "===========================================\n";

        _PerfromMainMenueOptiothern((_enPendingOrdersMenueOptions)_ReadPendingOrdersMenueOption());

}
};

