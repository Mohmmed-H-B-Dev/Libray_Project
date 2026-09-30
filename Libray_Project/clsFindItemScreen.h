#pragma once
#include <iostream>
#include"clsInputValidate.h";
#include <vector>
#include"clsSale.h"
#include "clsScreen.h";

using namespace std;

class clsFindItemScreen :protected clsScreen
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

public:
    static void FindItem() {

        /* if (!CheckAccessReghts(clsUser::enPermissions::pAddNewClient)) {

             return;
         }*/
        _DrawScreenHeader("Find Item");
        cout << "\n_______";
        cout << "\n\t\tFind Item";
        cout << "\n_______\n\n";
        string ItemCode = "";




        cout << "\nPlease Enter Item Code ";
        ItemCode = clsInputValidate::ReadString();
        while (clsSale::IsItemExist(ItemCode))
        {
            cout << "\nItem Code Is Already Used, Choose another one: ";
            ItemCode = clsInputValidate::ReadString();
        }

        clsSale FindItem = clsSale::FindItemCode(ItemCode);
        _PrintItem(FindItem);

    }
};

