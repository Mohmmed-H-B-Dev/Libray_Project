#pragma once
#include<iostream>

#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsSale.h"
using namespace std;

class AddItemToCartScreen : protected clsScreen
{
private:
    static void _PrintItem(clsSale Item) {
        cout << "\nBook Card : ";
        cout << "\n-----------------------\n";
        cout << "Item Code          :    " << Item.ItemCode << endl;
        cout << "Name Book          :    " << Item.NameItem << endl;
        cout << "Type Item          :    " << Item.TypeItem << endl;
        cout << "Quantity           :    " << to_string(Item.Quantity) << endl;
        cout << "Tax                :   (" << to_string(Item.Tax) << "%)" << endl;
        cout << "Price              :    " << to_string(Item.Price) << endl;

        cout << "\n-----------------------\n";
    }
    static bool _IfQuantityIsEmpty(clsSale item) {
        if (item.Quantity == 0) {
            item.Delete();
            return true;
        }
        return false;
    }
    static void Wiate() {
        cout << setw(37) << left << " " << "\n\n\tPress any ky to go Main Menue...\n";
        system("pause>0");
    }
   
    static void _AddItemToCart(clsSale Item) {
        Tax = Item.Tax;
        PriceExTax += Item.Price;

        for (clsSale &I : vCart) {
           
            if (Item.ItemCode == I.ItemCode && I.Quantity < Item.Quantity) {

                    I.Quantity += 1;

                return;

            }
            else {
                cout << "\nThere Is Not enough Quantity\n";
                Wiate();
                PriceExTax -= Item.Price;
                return;
            }

        }
       
        clsSale p = Item;
        p.Quantity = (Item.Quantity- Item.Quantity)+1;
       
        vCart.push_back(p);
        
       
        Wiate();

    }
    static void  _PrintItemRecordLine(clsSale Item) {

        cout << left << setw(8) << "" << left << setw(15)<< "| " + Item.ItemCode;
        cout << left << setw(17) << "| " + Item.NameItem;
        cout << left << setw(15) << "| " + Item.TypeItem;
        cout << left << setw(12) << "| " + to_string(Item.Quantity);
        cout << left << setw(10) << "| (" +to_string(Item.Tax) + "%)";
        cout << left << setw(12) << "| " + to_string(Item.GetPrice());
        cout << left << setw(2) << "| ";



    }
    static bool _IsEmptyItem(vector<clsSale>vItem) {

        return (vItem.size() == 0);
    }

    static vector<clsSale> _ItemList() {

        /*  if (!CheckAccessReghts(clsUser::enPermissions::pListClients)) {

              return;
          }*/
        vector<clsSale>vItem = clsSale::GetItemsList();

        string  Title = " Search Item List";
        string SubTitle = "(" + to_string(vItem.size()) + ") Item (s)";

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


        if (_IsEmptyItem(vItem)) {
            cout << "\t\t\t\t No, Items Available In the System!";
        }
        else {

            for (clsSale B : vItem) {
                _PrintItemRecordLine(B);
                cout << endl;
            }
            cout << left << setw(8) << "" << "\n____________________________________________________________________________________________\n";

        }

        return vItem;
    }

public:
    static void AdditemToCartScreen() {
        vector<clsSale>vItem = _ItemList();
        if (_IsEmptyItem(vItem)) {
            cout << "\t\t\t\t No, Items Available In the System!\n";

            cout << setw(37) << left << " " << "\n\n\tPress any ky to go Main Menue...\n";
            system("pause>0");
            return;
        }
        cout << "\n\t---------------------------------------------------------------------------\n";
        cout << "\n\t---------------------------------------------------------------------------\n";
        _DrawScreenHeader("For Add New Item To Cart");

        string ItemName = "";
        string ItemCode = "";
        char AnsworAgain = 'y';
        while(tolower(AnsworAgain) == 'y') {

            cout << "\nFind Item By Name[n] Or By Code[c] : ";
            char Answor = 'y';
            cin >> Answor;
            if (tolower(Answor) == 'n') {

                cout << "\nPlease Enter Item Name : ";
                ItemName = clsInputValidate::ReadString();
                while (!clsSale::IsItemNameExist(ItemName))
                {
                    cout << "\nItem Name Is Not Fount, Choose another one: ";
                    ItemName = clsInputValidate::ReadString();
                }
                clsSale ItemByName = clsSale::FindItemName(ItemName);
                if (_IfQuantityIsEmpty(ItemByName))
                    return;

            
                _AddItemToCart(ItemByName);
                _IfQuantityIsEmpty(ItemByName);
            }
            else {
                cout << "\nPlease Enter Item Code : ";
                ItemCode = clsInputValidate::ReadString();
                while (!clsSale::IsItemExist(ItemCode))
                {
                    cout << "\nItem Code Is Not Found, Choose another one: ";
                    ItemCode = clsInputValidate::ReadString();
                }
                clsSale ItemByCode = clsSale::FindItemCode(ItemCode);
                if (_IfQuantityIsEmpty(ItemByCode))
                    return;
                _AddItemToCart(ItemByCode);
                _IfQuantityIsEmpty(ItemByCode);
            }
            
            cout << "\nDo You want Add Item  To Cart Again ? [y] Or [n] ?  ";
            cin >> AnsworAgain;
        }

        ForCalculetorAPrice = false;
        vItemsBuyed = vCart;
    }
};

