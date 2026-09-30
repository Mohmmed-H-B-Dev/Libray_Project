#pragma once
#include<iostream>
#include"clsBook.h"
#include<vector>
#include"clsScreen.h"

class clsListPendingOrdersScreen : protected clsScreen
{

  
    private:
        static void  _PrintItemRecordLine(clsBook Items) {

            cout << left << setw(8) << "" << left << setw(15) << "| " + Items.IDAuther;
            cout << left << setw(20) << "| " + Items.NameAuther;
            cout << left << setw(15) << "| " + Items.ItemCode;
            cout << left << setw(17) << "| " + Items.NameItem;

            cout << left << setw(15) << "| " + Items.TypeItem;
            cout << left << setw(12) << "| " + to_string(Items.Quantity);
            cout << left << setw(10) << "| (" + to_string(Items.Tax) + "%)";

            cout << left << setw(12) << "| " + to_string((Items.GetPrice()));
            cout << left << setw(2) << "| ";

        }
public :
	static void ShowPedingBooks() {

		vector<clsBook> vBooks = clsBook::GetPendingBooksList();

        string  Title = "Books List";
        string SubTitle = "(" + to_string(vBooks.size()) + ") Book (s)";

        _DrawScreenHeader(Title, SubTitle);

        cout << left << setw(6) << "" << "\n\t______________________________________________________________________________________________________________\n";

        cout << left << setw(8) << "" << left << setw(15) << "| ID Author";
        cout << left << setw(20) << "| Name Author";
        cout << left << setw(15) << "| Item Code";
        cout << left << setw(17) << "| Name Item";
        cout << left << setw(15) << "| Type Item";
        cout << left << setw(12) << "| Quantity";
        cout << left << setw(10) << "| Tax(%)";
        cout << left << setw(12) << "| Price";
        cout << left << setw(3) << "|";
        cout << left << setw(6) << "" << "\n\t______________________________________________________________________________________________________________\n";


        if (vBooks.size() == 0) {
            cout << "\t\t\t\t No, Items Available In the System!";
        }
        else {

            for (clsBook B : vBooks) {
                _PrintItemRecordLine(B);
                cout << endl;
            }
            cout << left << setw(8) << "" << "\n____________________________________________________________________________________________\n";

        }
	}
};

