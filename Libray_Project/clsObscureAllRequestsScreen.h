#pragma once
#include<iostream>

#include"clsScreen.h"
#include"clsBook.h"
#include"clsListPendingOrdersScreen.h"


using namespace std;

class clsObscureAllRequestsScreen :protected clsScreen
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
    static void _AddNew(clsBook Book, string FileName)
    {

        _AddDataLineToFile(_ConverBookObjectToLine(Book), FileName);
    }
    static  void _AddDataLineToFile(string  stDataLine, string FileName = "Items.txt")
    {


        fstream MyFile;
        MyFile.open(FileName, ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }
public:
    static void ShowAddBookFromPendingOrders() {

        _DrawScreenHeader(" Obscure All Requsts From Pending Orders");

        vector <clsBook> vBooks = clsBook::GetPendingBooksList();
      
      
    
        if (clsInputValidate::IsYas("to Obscure All Requsts To File Items ")) {
            for (clsBook& Book : vBooks) {
                cout << endl;
                if (clsInputValidate::IsYas("to Add This Book To File Items ")) {
                    cout << endl;
                    _AddNew(Book, "Items.txt");
                    cout << "\nAccount Addeded Successfully :-)\n";

                    _AddNew(Book, "ApplicationsApprovedInThisMonth.txt");
                    Book.Delete();
                }
            }
        }
        else
            cout << "\nError account was not saved because it's Empty";



    }
};

