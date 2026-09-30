#pragma once
#include<iostream>

#include"clsScreen.h"
#include"clsBook.h"
#include"clsListPendingOrdersScreen.h"


using namespace std;



class clsAddBookOrderScreen:protected clsScreen
{
private:
   
   static string _ConverBookObjectToLine(clsBook Book, string Seperator = "#//#")
    {


        string stDsataRecord = "";
        stDsataRecord += Book.IDAuther + Seperator;
        stDsataRecord += Book.NameAuther + Seperator;
        stDsataRecord += Book.ItemCode + Seperator;
        stDsataRecord += Book.NameItem + Seperator;
        stDsataRecord += Book.TypeItem + Seperator;
        stDsataRecord += to_string(Book.Price) + Seperator;
        stDsataRecord += to_string(Book.Quantity) + Seperator;
        stDsataRecord += to_string(Book.Tax) + Seperator;

        return stDsataRecord;

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
   static void _AddNew(clsBook Book,string FileName)
    {
      
        _AddDataLineToFile(_ConverBookObjectToLine(Book), FileName);
    }
  static  void _AddDataLineToFile(string  stDataLine,string FileName= "Items.txt")
    {


        fstream MyFile;
        MyFile.open(FileName, ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }

public :
    static void ShowAddBookFromPendingOrders() {

        _DrawScreenHeader("Add New Book From Pending Orders");
        
        string ItemCode = "";
        cout << "\nPlease Enter Item Book : ";
        ItemCode = clsInputValidate::ReadString();
       int i = 1;
       while (clsSale::IsItemExist(ItemCode) || clsBook::IsOrderExist(ItemCode))
        {
            cout << "\nItem Code Is Already Used, Choose another one: ";
            ItemCode = clsInputValidate::ReadString();
            if (i == 3) {
                return;
            }
            i++;
        }
        clsBook  Book = clsBook::FindInPendingOrder(ItemCode);
        _PrintBook(Book);
        if (clsInputValidate::IsYas("to Add This Book To File Items ")) {
            
            _AddNew(Book, "Items.txt");
            cout << "\nAccount Addeded Successfully :-)\n";
            
            _AddNew(Book, "ApplicationsApprovedInThisMonth.txt");
            Book.Delete();

        }else
            cout << "\nError account was not saved because it's Empty";
        


    }

};

