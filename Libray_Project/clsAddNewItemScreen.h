#pragma once
#include <iostream>
#include"clsInputValidate.h";
#include <vector>
#include"clsSale.h"
#include "clsScreen.h";
#include"clsAddNewBookScreen.h"
using namespace std;

class clsAddNewItemScreen :protected clsScreen
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

public:
    static void AddNewItem() {

        /* if (!CheckAccessReghts(clsUser::enPermissions::pAddNewClient)) {

             return;
         }*/
        _DrawScreenHeader("Add New Item");
        string TypeItem = "";
        cout << "\nPlease Enter Type Item Do You want you Stored : ";
        TypeItem = clsInputValidate::ReadString();
        if (clsSale::IsTypeItemBook(TypeItem)) {
            system("cls");
            clsAddNewBookScreen::AddNewBook();
            return;
        }
           
        string ItemCode = "";
       
        
           cout<< "\nPlease Enter Item Code : ";
        ItemCode = clsInputValidate::ReadString();
        while (clsSale::IsItemExist(ItemCode))
        {
            cout << "\nItem Code Is Already Used, Choose another one: ";
            ItemCode = clsInputValidate::ReadString();
        }

      
        clsSale NewItem = clsSale::GetAddNewItemObject(ItemCode);


        _ReadItemInfo(NewItem);

        clsSale::enSaveResults SaveResult;
        SaveResult = NewItem.Save();

        if (clsInputValidate::IsYas("Add this Item ")) {
            switch (SaveResult)
            {
            case  clsSale::enSaveResults::svSucceeded:
            {
                cout << "\nAccount Addeded Successfully :-)\n";
               
                _PrintItem(NewItem);
                break;
            }
            case clsSale::enSaveResults::svFaildEmptyObject:
            {
                cout << "\nError account was not saved because it's Empty";
                break;

            }
            case clsSale::enSaveResults::svFaildAccountNumberExists:
            {
                cout << "\nError account was not saved because account number is used!\n";
                break;
                ;
            }
            case clsSale::enSaveResults::eNothing:
            {
                cout << "\n\t\t\tNoThing Happened\n";
                break;
                ;
            }
            }
        }
    }
};

