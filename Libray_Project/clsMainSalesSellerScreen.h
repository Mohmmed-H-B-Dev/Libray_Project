#pragma once

#include"clsInputValidate.h"
#include<iomanip>

#include"clsUser.h"
#include"clsScreen.h"
#include"clsListItemsScreen.h"
#include"clsFindItemScreen.h"
#include"AddItemToCartScreen.h"
#include"clsPaymentMetodsScreen.h"
#include"clsAddCustomerSubscriptionNumber.h"
#include"clsPrintInvoiceScreen.h"
#include"Global.h"

using namespace std;

class clsMainSalesSellerScreen : protected clsScreen
{
private:
    enum enMainMenueOptions
    {
        eListItems = 1, eAddItem = 2,
        eDeleteItem = 3, eUpdateItem = 4,
        eFindItem = 5,ePaymentMethods=6, eDeleteInvoice = 7, eAddClinet = 8, eDeleteClient =9, eReceipts = 10, eLogout = 11
    };
    static short _ReadMainSellingOption()
    {

        short Choice = clsInputValidate::ReadNumberBetween<short>(1, 11, "\n\t\t\t\t\tEnter Number Between 1 and 11 : ");



        return Choice;
    }

    static void _GetBackToMainMenue() {
        cout << setw(37) << left << " " << "\n\tPress any ky to go Main Menue...\n";
        system("pause>0");
        ShowMainSalesSeller();

    }

    static void _ShowAllItemsScreen() {
        //cout << "\nAll Items Screen Will be here../\n";
        clsListItemScreen::ItemsList();
    }

    static void _ShowAddItemToCartScreen() {
        //cout << "\nAdd  Item Screen Will be here../\n";
        AddItemToCartScreen::AdditemToCartScreen();
        
    }

    static void _ShowDeleteItemFromCartScreen() {
        clsListItemScreen::ItemsList(vCart);
        Tax = 0;
        TotalPrice = 0;
        TotalPriceExTax = 0;
            clsListItemScreen::ShowAllPriceItems(true);
        
        _DrawScreenHeader("Delet Element");

        cout << "\nPlease Enter Item Code:";
        string ItemCode = clsInputValidate::ReadString();

        for (clsSale& S : vCart) {
            if (S.ItemCode == ItemCode) {
                S = clsSale::GetEmptyItemObject();
            }
        }
    }
    static void _ShowUpdateItemFromCartScreen() {
        cout << "\nUpdate Item Screen Will be here../\n";

        //clsUpdateAuthertScreen::ShowUpdatAuther();
    }
    static void _ShowFindItemByCodeScreen() {

        cout << "\nFind Item Screen Will be here../\n";
        // clsFindAutherScreen::ShowFindAuther();
    }
    static void _ShowPaymentMethodsScreen() {

       // cout << "\nFind Item Screen Will be here../\n";
        clsPaymentMetodsScreen::ShowPaymentMethods();
    }
    static void _ShowDeleteInvoiceScreen() {
        cout << "\nDelete Invoice  Screen Will be here../\n";
    }
    static void _ShowAddClinetScreen() {
       // cout << "\nAdd Client  Screen Will be here../\n";
        clsAddCustomerSubscriptionNumber::ShowAddClient();
    }
    static void _ShowDeleteClientScreen() {
        cout << "\nDelete Client  Screen Will be here../\n";
    }
    static void _ShowReceiptsScreen() {
        cout << "\nReceipts Screen Will be here../\n";
        //ÇáÇÔíÇÁ ÇáÊí Êã ÈíÚåÇ
        clsPrintInvoiceScreen::ShowPrintInvoice();
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

            _ShowAddItemToCartScreen();

            _GetBackToMainMenue();

            break;



        case enMainMenueOptions::eDeleteItem:

            system("cls");
            if (!vCart.empty()) {
                _ShowDeleteItemFromCartScreen();
            }
            _GetBackToMainMenue();

            break;



        case enMainMenueOptions::eUpdateItem:

            system("cls");
            if (vCart.size() != 0) {
                _ShowUpdateItemFromCartScreen();
            }
            _GetBackToMainMenue();

            break;



        case enMainMenueOptions::eFindItem:

            system("cls");
           
            _ShowFindItemByCodeScreen();

            _GetBackToMainMenue();

            break;

        case enMainMenueOptions::ePaymentMethods:

            system("cls");
            if (vCart.size() != 0) {
              
                _ShowPaymentMethodsScreen();
            }else
                cout << "\nYou can't Access Without Adding same Items..\n";
           

            _GetBackToMainMenue();

            break;
        case enMainMenueOptions::eDeleteInvoice:

            system("cls");
            if (vCart.size() != 0) {
                _ShowDeleteInvoiceScreen();
            }
            _GetBackToMainMenue();

            break;

        case enMainMenueOptions::eAddClinet:

            system("cls");
            if (vCart.size() != 0) {
                _ShowAddClinetScreen();
            }
            _GetBackToMainMenue();

            break;

        case enMainMenueOptions::eDeleteClient:

            system("cls");

            _ShowDeleteClientScreen();

            _GetBackToMainMenue();

            break;

        case enMainMenueOptions::eReceipts:

            system("cls");

            _ShowReceiptsScreen();

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

    static void ShowMainSalesSeller ()

    {

        system("cls");


     
        cout << left << setw(37) << " " << "===========================================\n";
        cout << left << setw(37) << " " << "Main  Selling Screen" << endl;
        cout << left << setw(37) << " " << "==========================================\n";
       
        clsListItemScreen::ItemsList(vCart);
        if(!vCart.empty())
        clsListItemScreen::ShowAllPriceItems(ForCalculetorAPrice);
        ForCalculetorAPrice = true;
   //     Íá ãÔßáÉ ØÈÇÚÉ ÑÞã æÇÍÏ Ýí ÔÇÔÉ ÇáÇÕäÇÝ ÇáÌÇåÒÉ ááÈíÚ
        cout<<"\n\n";
        cout << left << setw(37) << " " << "===========================================\n\n";

        cout << left << setw(22) << " " << "[1]  Show Items List.";
                                                 
        cout << left << setw(22) << " " << "        [2]  Add to Cart By Code Item.\n";
                                                 
        cout << left << setw(22) << " " << "[3]  Delete Items From Catr.";
                                                 
        cout << left << setw(22) << " " << " [4]  Update Items From Catr.\n";
                                                 
        cout << left << setw(22) << " " << "[5]  Find Item By Code Item .";

        cout << left << setw(22) << " " << "[6]  Payment Methods .\n";
                                                 
        cout << left << setw(22) << " " << "[7]  Delete Invoice .\n";
                                                 
        cout << left << setw(22) << " " << "[8]  Add Clinet .";
                                                 
        cout << left << setw(22) << " " << "            [9]  Delete Client .\n";
                                                 
        cout << left << setw(22) << " " << "[10]  Receipts .";

        cout << left << setw(22) << " " << "              [11] Main Menue.\n";

        cout << left << setw(37) << " " << "===========================================\n";

        _PerfromMainMenueSellingOption((enMainMenueOptions)_ReadMainSellingOption());

    }
};