#pragma once
#include<iostream>

#include"clsScreen.h"
#include"clsBook.h"
#include"clsInputValidate.h"
#include"clsBookListScreen.h"
#include"clsAddNewBookScreen.h"
#include"clsDeleteBookScreem.h"
#include"clsFindItemScreen.h"
#include"clsUpdateItemScreen.h"

using namespace std;

class clsTransactoinsScreen : protected clsScreen
{
private:

    enum _enTransactionsMenueOptions { eShowBooklist = 1, eAddNewBook=2, eDelete=3 ,eUpdate = 4,eFind=5, eMainMenue = 6 };

    static short _ReadTransactionsMenueOption()
    {

        short Choice = clsInputValidate::ReadNumberBetween<short>(1, 6, "Enter Number Between 1 and 6 : ");


        return Choice;
    }
    static void _ShowAllBooksScreen() {

        //cout << "\nDeposit Screen Will be here../\n";
        clsBookListScreen::BookList();
    }
    static void _ShowAddNewBookScreen() {
        //cout << "\nAdd New Book Screen Will be here../\n";
        clsAddNewBookScreen::AddNewBook();
    }
    static void _ShowDeleteBookScreen() {
       // cout << "\nDelete Screen Will be here../\n";
        clsDeleteBookScreem::DeleteBookScreen();
    }

    static void _ShowUpdateBookScreen() {
       //  cout << "\nUpdate Book Screen Will be here../\n";
        clsUpdateItemScreen::UpDateItem();
    }
    static void _ShowFindBookScreen() {

        // cout << "\nFind Book Screen Will be here../\n";
        clsFindItemScreen::FindItem();
    }
    static void _GoBackTOTransactionsMenue() {
        cout << setw(37) << left << " " << "\nPress any ky to go Main Menue...\n";
        system("pause>0");
        ShowTransactionsMenue();

    }


    static  void _PerfromTransactionsMenueOption(_enTransactionsMenueOptions TransactionsMenueOption)

    {

        switch (TransactionsMenueOption)

        {

        case _enTransactionsMenueOptions::eShowBooklist:

        {

            system("cls");

          _ShowAllBooksScreen();
            _GoBackTOTransactionsMenue();

            break;

        }

        case _enTransactionsMenueOptions::eAddNewBook:

            system("cls");

          _ShowAddNewBookScreen();

            _GoBackTOTransactionsMenue();

            break;



        case _enTransactionsMenueOptions::eDelete:

            system("cls");

            _ShowDeleteBookScreen();

            _GoBackTOTransactionsMenue();

            break;

        case _enTransactionsMenueOptions::eUpdate:

            system("cls");

            _ShowUpdateBookScreen();

            _GoBackTOTransactionsMenue();

            break;
        case _enTransactionsMenueOptions::eFind:

            system("cls");

            _ShowFindBookScreen();

            _GoBackTOTransactionsMenue();

            break;
        case _enTransactionsMenueOptions::eMainMenue:



            break;

        }
    }

public:

    static void ShowTransactionsMenue() {


        system("cls");

        //if (!checkaccessreghts(clsuser::enpermissions::ptranactions)) {

        //    return;
        //}
        _DrawScreenHeader("\tTransactions Menue");
        cout << left << setw(37) << " " << "===========================================\n";
        cout << left << setw(37) << " " << "Transactions Menue" << endl;
        cout << left << setw(37) << " " << "===========================================\n";

        cout << left << setw(37) << " " << "[1] Book List.\n";

        cout << left << setw(37) << " " << "[2] Add New Book.\n";

        cout << left << setw(37) << " " << "[3] Delete Book.\n";

        cout << left << setw(37) << " " << "[4] Update Book.\n";

        cout << left << setw(37) << " " << "[5] Find Book.\n";

        cout << left << setw(37) << " " << "[6] Main Menue.\n";

        cout << left << setw(37) << " " << "===========================================\n";

        _PerfromTransactionsMenueOption((_enTransactionsMenueOptions)_ReadTransactionsMenueOption());
    }
};

