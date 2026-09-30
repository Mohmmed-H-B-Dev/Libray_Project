#pragma once
#include<iostream>

#include"clsScreen.h"
#include"clsBook.h"


using namespace std;

class clsBookListScreen : protected clsScreen
{
private:

    static void  _PrintBookRecordLine(clsSale Items) {

        cout << left << setw(8) << "" << left << setw(15) << "| " + Items.ItemCode;
        cout << left << setw(17) << "| " + Items.NameItem;

        cout << left << setw(15) << "| " + Items.TypeItem;
        cout << left << setw(12) << "| " + to_string(Items.Quantity);
        cout << left << setw(10) << "| (" + to_string(Items.Tax) + "%)";

        cout << left << setw(12) << "| " + to_string((Items.GetPrice()));
        cout << left << setw(2) << "| ";

    }

public:

	static void BookList() {
       
            /*  if (!CheckAccessReghts(clsUser::enPermissions::pListClients)) {

                  return;
              }*/
            vector<clsSale>vBook = clsSale::GetItemsList();

            string  Title = "Book List";
            string SubTitle = "(" + to_string(vBook.size()) + ") Book (s)";

            _DrawScreenHeader(Title, SubTitle);

            cout << left << setw(6) << "" << "\n\t______________________________________________________________________________________________________________\n";

            cout << left << setw(8) << "" << left << setw(15) << "| Item Code";
            cout << left << setw(17) << "| Name Item";
            cout << left << setw(15) << "| Type Item";
            cout << left << setw(12) << "| Quantity";
            cout << left << setw(10) << "| Tax(%)";
            cout << left << setw(12) << "| Price";
            cout << left << setw(3) << "|";
            cout << left << setw(6) << "" << "\n\t______________________________________________________________________________________________________________\n";


            if (vBook.size() == 0) {
                cout << "\t\t\t\t No, Books Available In the System!";
            }
            else {

                for (clsSale B : vBook) {
                    if (B.TypeItem == "Books") {
                        _PrintBookRecordLine(B);
                        cout << endl;
                    }
                }
                cout << left << setw(8) << "" << "\n____________________________________________________________________________________________\n";

            }

        
	}

};

