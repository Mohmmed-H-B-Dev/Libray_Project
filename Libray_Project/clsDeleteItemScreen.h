#pragma once
#include <iostream>
#include"clsInputValidate.h";
#include <vector>
#include"clsSale.h"
#include "clsScreen.h";

using namespace std;

class clsDeleteItemScreen:protected clsScreen
{
private:
    static void _PrintItem(clsSale Item) {
        cout << "\nItem Card : ";
        cout << "\n-----------------------\n";
        cout << "Item Code          :    " << Item.ItemCode << endl;
        cout << "Name Book          :    " << Item.NameItem << endl;
        cout << "Type Item          :    " << Item.TypeItem << endl;
        cout << "Quantity           :    " << to_string(Item.Quantity) << endl;
        cout << "Tax                :   (" << to_string(Item.Tax) << "%)" << endl;
        cout << "Price              :    " << to_string(Item.Price) << endl;

        cout << "\n-----------------------\n";
    }


public :
    static void DeleteItemScreen() {
    /*  if (!CheckAccessReghts(clsUser::enPermissions::pDeleteClient)) {

          return;
      }*/
    _DrawScreenHeader("Delete Item");
    string ItemCode = "";
    cout << "\nEnter Item Code : ";
    ItemCode = clsInputValidate::ReadString();

    while (!clsSale::IsItemExist(ItemCode))
    {

        cout << "\nItem Code Is Not Fond , Enter Item code Again : ";
        ItemCode = clsInputValidate::ReadString();

    }

    clsSale  Item = clsSale::FindItemCode(ItemCode);


  
    _PrintItem(Item);
   

 
            if (clsInputValidate::IsYas(" To Delete ")) {
                if (clsInputValidate::IsYas(" Delete All Quantity Of Items ")) {
                    if (Item.Delete())
                    {
                        cout << "\nDelete Item Scceessfuly . \n\n";

                        _PrintItem(Item);
                    }
                    else {
                        cout << "\nError, Delete Item is Not Sccessded";
                    }
                }
                else {
                    short SpQua = 0;
                    cout << "\n\tPlease Slelect the amount You want to Delete : ";
                    cin >> SpQua;
                    Item.DeleteSPecifiedQuantity(SpQua);

                    _PrintItem(Item);
                }

            }
          
        
       
    }
    static void DeleteItemAfterPurchaseProcess(string ItemCode, short SpQua) {




        while (!clsSale::IsItemExist(ItemCode))
        {

            cout << "\nItem Code Is Not Fond , Enter Item code Again : ";
            ItemCode = clsInputValidate::ReadString();

        }

        clsSale  Item = clsSale::FindItemCode(ItemCode);

        if (Item.Quantity == 0) {
            Item.Delete();
            return;
        }else
        Item.DeleteSPecifiedQuantity(SpQua);



    }
};

