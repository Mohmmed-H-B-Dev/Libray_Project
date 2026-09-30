#pragma once
#include <iostream>
#include"clsInputValidate.h";
#include <vector>
#include"clsSale.h"
#include "clsScreen.h";

using namespace std;

class clsUpdateItemScreen :protected clsScreen
{

private:
    static void _ReadItemInfo(clsSale& Item) {
        cout << "\nEnter Item Type : ";
        Item.TypeItem = clsInputValidate::ReadString();

        cout << "\nEnter Item Name : ";
        Item.NameItem = clsInputValidate::ReadString();

        cout << "\nEnter Quantity : ";
        Item.Quantity = clsInputValidate::ReadNumber<short>();


        Item.Tax = 0.15;

        cout << "\nEnter Price : ";
        Item.Price = clsInputValidate::ReadNumber<double>();

    }


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
    static void UpDateItem() {

        /* if (!CheckAccessReghts(clsUser::enPermissions::pAddNewClient)) {

             return;
         }*/
        _DrawScreenHeader("Update Item");
        cout << "\n_______";
        cout << "\n\t\tUpdate Item";
        cout << "\n_______\n\n";
        string ItemCode = "";




        cout << "\nPlease Enter Item Code ";
        ItemCode = clsInputValidate::ReadString();
        while (clsSale::IsItemExist(ItemCode))
        {
            cout << "\nItem Code Is Already Used, Choose another one: ";
            ItemCode = clsInputValidate::ReadString();
        }

        clsSale UPdateItem = clsSale::FindItemCode(ItemCode);


        _ReadItemInfo(UPdateItem);



        if (clsInputValidate::IsYas("Update this Book ")) {

            clsSale::enSaveResults SaveResult = UPdateItem.Save();
            switch (SaveResult)
            {
            case clsSale::svFaildEmptyObject:
                cout << "Error account Was not Saved Because it`s Epmty : \n";
                break;
            case clsSale::svSucceeded:


                cout << "Account Update Successfuly : \n";
                _PrintItem(UPdateItem);
                break;

            }
        }
    }
};

