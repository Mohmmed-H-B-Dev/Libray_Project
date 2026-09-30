#pragma once
#include <iostream>
#include"clsInputValidate.h";
#include <vector>
#include"clsBook.h"
#include "clsScreen.h";
#include"clsUser.h"

using namespace std;

class clsAddNewBookScreen :protected clsScreen
{

private :
    static void _ReadBookInfo(clsBook& Book) {

        cout << "\nEnter Item Name : ";
        Book.NameItem = clsInputValidate::ReadString();

     
        Book.TypeItem = "Books";

        cout << "\nEnter Quantity : ";
        Book.Quantity = clsInputValidate::ReadNumber<short>();


        Book.Tax = 0.15;

        cout << "\nEnter Price : ";
        Book.Price = clsInputValidate::ReadNumber<double>();
        
    }


    static void _PrintBook(clsBook Book) {
        cout << "\nBook Card : ";
        cout << "\n-----------------------\n";
        cout << "ID Auther          :    " << Book.IDAuther << endl;
        cout << "Full Name Auther   :    " << Book.NameAuther << endl;
        cout << "Item Code          :    " << Book.ItemCode << endl;
        cout << "Name Book          :    " << Book.NameItem << endl;
        cout << "Type Item          :    " << Book.TypeItem << endl;
        cout << "Quantity           :    " << to_string(Book.Quantity) << endl;
        cout << "Tax                :   (" << to_string(Book.Tax) << "%)" << endl;
        cout << "Price              :    " << to_string(Book.Price) << endl;

        cout << "\n-----------------------\n";
    }
    static void _AddData(clsBook NewBook) {

        clsBook::enSaveResults SaveResult;
        SaveResult = NewBook.Save();

        if (clsInputValidate::IsYas("Add this Book ")) {
            switch (SaveResult)
            {
            case  clsBook::enSaveResults::svSucceeded:
            {
                cout << "\nAccount Addeded Successfully :-)\n";

                _PrintBook(NewBook);
                break;
            }
            case clsBook::enSaveResults::svFaildEmptyObject:
            {
                cout << "\nError account was not saved because it's Empty";
                break;

            }
            case clsBook::enSaveResults::svFaildAccountNumberExists:
            {
                cout << "\nError account was not saved because account number is used!\n";
                break;
                ;
            }
            case clsBook::enSaveResults::eNothing:
            {
                cout << "\n\t\t\tNoThing Happened\n";
                break;
                ;
            }
            }
        }
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
    static void _UpdataQuantity(clsSale UPdateItem) {

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
public :
    static void AddNewBook() {

        /* if (!CheckAccessReghts(clsUser::enPermissions::pAddNewClient)) {

             return;
         }*/

        _DrawScreenHeader("Add New Book");
        string ItemCode = "";
        string IDAuther =CurrentUser.UserName;
      if(CurrentUser.CurrentPosition !="A")  {
            cout << "\n_______";
            cout << "\n\t\tAdd Auther";
            cout << "\n_______\n\n";
            
          
            cout << "\nPlease Enter ID Auther ";
            IDAuther = clsInputValidate::ReadString();
           
        }
        int i = 1;
        clsUser User = clsUser::Find(IDAuther);

        while (!clsUser::IsUserExist(IDAuther))
        {
            cout << "\nId Auther Is Already Used, Choose another one: ";
            IDAuther = clsInputValidate::ReadString();
            User = clsUser::Find(IDAuther);
            if (i == 3) {
                return;
            }
            i++;
        }

        cout << "\n \t\t __________\n "<<
            "\t\t And Now \n\t\t __________"<<" \n\n Please Enter Item Code ";
        ItemCode = clsInputValidate::ReadString();
        i = 1;
        while (clsSale::IsItemExist(ItemCode))
        {
            cout << "\nItem Code Is Already Used, Do You Want Update Quantity? [y] Or [n]? ";
            char Answor = 'n';
            cin >> Answor;

            if (tolower(Answor) == 'y') {
                clsSale Item = clsSale::FindItemCode(ItemCode);

                cout << "\nEnter Quantity : ";
                Item.Quantity += clsInputValidate::ReadNumber<short>();
                _UpdataQuantity(Item);
                return;
            }
            else
                return;
        }
        string NameAuther = User.FirstName + " "+ User.LastName;
        clsBook NewBook = clsBook::GetAddNewBookObject(IDAuther,NameAuther,ItemCode);

       
        _ReadBookInfo(NewBook);

        _AddData(NewBook);
    }
};

