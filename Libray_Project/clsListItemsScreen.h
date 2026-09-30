#pragma once
#include<iostream>

#include"clsScreen.h"
#include"clsSale.h"
#include<cmath>

using namespace std;


class clsListItemScreen : protected clsScreen
{
private:
    static void  _PrintItemRecordLine(clsSale Items) {
    
        cout << left << setw(8) << "" << left << setw(15) << "| " + Items.ItemCode;
        cout << left << setw(17) << "| " + Items.NameItem;
       
        cout << left << setw(15) << "| " + Items.TypeItem;
        cout << left << setw(12) << "| " + to_string(Items.Quantity);
        cout << left << setw(15) << "| (" + to_string(Items.Tax) + "%)";
    
        cout << left << setw(12) << "| " + to_string((Items.GetPrice()));
        cout << left << setw(2) << "| ";

    }
    static void _CalculetorPrices(double Price,short Quantity,double Tac) {
    
        PriceExTax += Quantity * Price;

        TotalPriceExTax = PriceExTax;
        Tax = Tac;
    }

    static void _ShowCalculetorPrices(bool MarcketToDelete) {


      
        if (!MarcketToDelete) {
            Tax = PriceExTax * Tax;
            TotalPrice = PriceExTax + Tax;
        }
       
 
   }
public:
    static void  ShowAllPriceItems(bool MarcketToDelete= true) {


        _ShowCalculetorPrices(MarcketToDelete);
          amount = TotalPrice;
        cout << left << setw(6) << "" << "\n\t_________________________________________________\n";

        cout << left << setw(8) << "" << left << setw(15) << "| Total Price";
        cout << left << setw(17) << "| Price eX Tax";
        cout << left << setw(18) << "| Tax(%)";
        cout << left << setw(3) << "|";
        cout << left << setw(6) << "" << "\n\t_________________________________________________\n";

        cout << left << setw(8) << "" << left << setw(15) << "| " + to_string(TotalPrice);
        cout << left << setw(17) << "| " + to_string(PriceExTax);

        cout << left << setw(18) << "| " + to_string(Tax) << "%)";

        cout << left << setw(2) << "| ";
      
        cout << left << setw(6) << "" << "\n\t_________________________________________________\n";
      
        cout << left << setw(6) << "" << "\n\t_________________________________________________\n";
    }
    static void ItemsList(vector<clsSale>vItems = clsSale::GetItemsList(),bool O=false ) {

        /*  if (!CheckAccessReghts(clsUser::enPermissions::pListClients)) {

              return;
          }*/
     

        string  Title = "Items List";
        string SubTitle = "(" + to_string(vItems.size()) + ") Item (s)";

        _DrawScreenHeader(Title, SubTitle, AcceptShowClient);

        cout << left << setw(6) << "" << "\n\t______________________________________________________________________________________________________________\n";

        cout << left << setw(8) << "" << left << setw(15) << "| Item Code";
        cout << left << setw(17) << "| Name Item";
        cout << left << setw(15) << "| Type Item";
        cout << left << setw(12) << "| Quantity";
        cout << left << setw(15) << "| Tax(%)";
        cout << left << setw(12) << "| Price";
        cout << left << setw(3) << "|";
        cout << left << setw(6) << "" << "\n\t______________________________________________________________________________________________________________\n";


        if (vItems.size() == 0) {
            cout << "\t\t\t\t No, Items Available In the System!";
        }
        else {

            for (clsSale I : vItems) {
                _PrintItemRecordLine(I);
                cout << endl;
            }
            cout << left << setw(8) << "" << "\n____________________________________________________________________________________________\n";
           

        }


    }

};

