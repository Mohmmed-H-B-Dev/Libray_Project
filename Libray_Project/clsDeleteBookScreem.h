#pragma once
#include<iostream>

#include"clsInputValidate.h"
#include"clsScreen.h"
#include"clsBook.h"
class clsDeleteBookScreem :  protected clsScreen
{

private:
    static void _PrintBook(clsSale Book) {
        cout << "\nBook Card : ";
        cout << "\n-----------------------\n";
        cout << "Item Code          :    " << Book.ItemCode << endl;
        cout << "Name Book          :    " << Book.NameItem << endl;
        cout << "Type Item          :    " << Book.TypeItem << endl;
        cout << "Quantity           :    " << to_string(Book.Quantity) << endl;
        cout << "Tax                :   (" << to_string(Book.Tax) << "%)" << endl;
        cout << "Price              :    " << to_string(Book.Price) << endl;

        cout << "\n-----------------------\n";
    }



public :
    static void DeleteBookScreen() {
        /*  if (!CheckAccessReghts(clsUser::enPermissions::pDeleteClient)) {

              return;
          }*/
        _DrawScreenHeader("Delete Book");
        string ItemCode = "";
        cout << "\nEnter Item Code : ";
        ItemCode = clsInputValidate::ReadString();
        
        while (!clsSale::IsItemExist(ItemCode))
        {

            cout << "\nItem Code Is Not Fond , Enter Item code Again : ";
            ItemCode = clsInputValidate::ReadString();

        }

        clsSale  Book = clsSale::FindItemCode(ItemCode);
     





       
            
        

        
        _PrintBook(Book);
        if (clsInputValidate::IsYas("To Delete ")) {


            if (clsInputValidate::IsYas(" Delete All Quantity Of Books ")) {

                if (Book.Delete())
                {
                    cout << "\nDelete Book Scceessfuly . \n\n";

                    _PrintBook(Book);
                }
                else {
                    cout << "\nError, Delete Book is Not Sccessded";
                }
            }
            else {
                short SpQua = 0;
                cout << "\n\tPlease Slelect the amount You want to Delete : ";
                cin >> SpQua;
                Book.DeleteSPecifiedQuantity(SpQua);

                _PrintBook(Book);
            }
        }
            else {
                cout << "\nError, Delete Book is Not Sccessded!! Because There is no Auther of this Book!!!!!!!!!!!";
            }
        
    }

};

