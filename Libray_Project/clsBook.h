#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <ctype.h>
#include"clsString.h";
#include <string>
#include"clsitems.h"
#include"clsUtil.h"

class clsBook : public clsitems {
private:

    string _IDAuther;
    string _NameAuther;

    string _NameFile = "RequsestsAddBooks.txt";
    bool _MarketForDelete = false;

    enum _enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };

    _enMode _Mode;


    static clsBook _ConvertLinetoBookObject(string Line, string Seperator = "#//#")
    {
        
        
        vector<string> vBookData;
        vBookData = clsString::Split(Line, Seperator);

        clsBook B = clsBook(_enMode::UpdateMode, vBookData[0], vBookData[1], vBookData[2],
            vBookData[3], vBookData[4],stod(vBookData[5]), stoi(vBookData[6]), stoi(vBookData[7]));

        return B;

    }
    static clsBook _GetEmptyBookObject() {

        return clsBook(_enMode::EmptyMode, "", "", "", "", "", 0, 0, 0);

    }
    static  vector <clsBook>   _LoadPendingBooksDataFromFile()
    {

        vector <clsBook> vBook;


        fstream MyFile;
        MyFile.open("RequsestsAddBooks.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;


            while (getline(MyFile, Line))
            {

                clsBook Book = _ConvertLinetoBookObject(Line);
                if (clsString::UpperAllString(Book.GetTypeItem()) == clsString::UpperAllString("Books")) {
                    vBook.push_back(Book);
                }
            }

            MyFile.close();

        }

        return vBook;

    }

    static  vector <clsBook>   _LoadBooksDataFromFile()
    {

        vector <clsBook> vBook;


        fstream MyFile;
        MyFile.open("Items.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;


            while (getline(MyFile, Line))
            {

                clsBook Book = _ConvertLinetoBookObject(Line);
                if (clsString::UpperAllString(Book.GetTypeItem()) == clsString::UpperAllString("Books")) {
                    vBook.push_back(Book);
                }
            }

            MyFile.close();

        }

        return vBook;

    }
   
    string _ConverBookObjectToLine(clsBook Book, string Seperator = "#//#")
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
 
    void _SaveBooksObjectToFile(vector<clsBook> vBook) {

        fstream MyFile;
        string DataLine = "";
        MyFile.open("RequsestsAddBooks.txt", ios::out);

        if (MyFile.is_open()) {

            for (clsBook B : vBook) {

                if (B._MarketForDelete == false) {


                    DataLine = _ConverBookObjectToLine(B);

                    MyFile << DataLine << endl;



                }


            }

            MyFile.close();
        }


    }
    void _Update() {
        vector <clsBook> vBook = _LoadBooksDataFromFile();
      
        for (clsBook& B : vBook) {
            
            if (B.GetItemCode() == GetItemCode()) {

                B = *this;
                break;
            }

        }
        _SaveBooksObjectToFile(vBook);

    }

    void _AddNew()
    {

            _AddDataLineToFile(_ConverBookObjectToLine(*this));
    }
    void _AddDataLineToFile(string  stDataLine)
    {


        fstream MyFile;
        MyFile.open(_NameFile, ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }


public:

    clsBook(_enMode Mode,string IDAuther,string NameAuther, string ItemCode, string NameItem , string TypeItem, double Price, int Quantity, short Tax)
        :clsitems(NameItem, TypeItem, ItemCode, Price, Quantity,Tax)
    {
        _IDAuther = IDAuther;
        _NameAuther = NameAuther;
        _Mode = Mode;
    }

    void SetIDAuther(string IDAuther) {

        _IDAuther = IDAuther;
    }
    string GetIDAuther()
    {
        return _IDAuther;
    }
    __declspec(property(get = GetIDAuther, put = SetIDAuther)) string  IDAuther;
    void SetNameAuther(string NameAuther) {

        _NameAuther = NameAuther;
    }
    string GetNameAuther()
    {
        return _NameAuther;
    }
    __declspec(property(get = GetNameAuther, put = SetNameAuther)) string  NameAuther;


  

    
    _enMode Mode() {

        return _Mode;
    }



    bool IsEmpty() {

        return (_Mode == _enMode::EmptyMode);
    }

   
    static clsBook FindInPendingOrder(string ItemCode)
    {

        fstream MyFile;
        MyFile.open("RequsestsAddBooks.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBook Book = _ConvertLinetoBookObject(Line);


                if (Book.GetItemCode() == ItemCode)
                {
                    if (clsString::UpperAllString(Book.GetTypeItem()) == clsString::UpperAllString("Books")) {
                        MyFile.close();
                        return Book;
                    }
                    else {
                        return _GetEmptyBookObject();
                    }
                }

            }

            MyFile.close();

        }

        return _GetEmptyBookObject();
    }


   

        static clsBook GetAddNewBookObject(string IdAuther,string NameAuther, string ItemCode)
    {
        return clsBook(_enMode::AddNewMode

            , IdAuther, NameAuther, ItemCode, "", "",0, 0, 0);
    }


        bool Delete() {

            vector<clsBook>vBooks = _LoadBooksDataFromFile();


            for (clsBook& B : vBooks) {

                if (B.ItemCode == ItemCode) {

                    B._MarketForDelete = true;


                    break;
                }

            }
            _SaveBooksObjectToFile(vBooks);

            *this = _GetEmptyBookObject();
            return true;
        }
    enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildAccountNumberExists = 2, eNothing = -1 };


    enSaveResults Save()
      {
  
          switch (_Mode)
          {
          case _enMode::EmptyMode:
          {
          if (IsEmpty())
              {
  
                  return enSaveResults::svFaildEmptyObject;
  
              }
  break;
          }
          
          case _enMode::AddNewMode:
          {
              //This will add new record to file or database
              if (clsBook::IsOrderExist(ItemCode)&& !clsUser::IsUserExist(IDAuther))
              {
                  return enSaveResults::svFaildAccountNumberExists;
              }
              else
              {
                  _AddNew();
  
                  //We need to set the mode to update after add new
                  _Mode = _enMode::UpdateMode;
                  return enSaveResults::svSucceeded;
              }
  
              break;
          }
          
         
  
         case _enMode::UpdateMode:
          {
  
  
             _Update();
  
              return enSaveResults::svSucceeded;
  
              break;
          }
  
          
          }
  return enSaveResults::eNothing;
      }
  
    void DeleteSPecifiedQuantity(short Quan) {

        Quantity -= Quan;
        Save();
    }


    static vector<clsBook> GetBooksList() {
        return _LoadBooksDataFromFile();
    }
    static vector<clsBook> GetPendingBooksList() {
        return _LoadPendingBooksDataFromFile();
    }
 
  static bool IsOrderExist(string ItemCode)
  {

      clsBook Book1 = clsBook::FindInPendingOrder(ItemCode);

      return (!Book1.IsEmpty());
  }

};




