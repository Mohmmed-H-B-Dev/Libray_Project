#pragma once
#include<iostream>
#include<fstream>
#include"clsitems.h";
#include "clsString.h";
#include"string";
#include<vector>
#include"clsInputValidate.h";
#include"clsUtil.h"
#include"Global.h"
using namespace std;
class clsSale :  public clsitems
{
public:
  
private:

    enum _enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };

    _enMode _Mode;

    bool _MarketForDelete = false;

  

    

    static clsSale _ConvertLinetoItemsObject(string Line, string Seperator = "#//#")
    {


        vector<string> vItemData;



        vItemData = clsString::Split(Line, Seperator);
       
        clsSale I= GetEmptyItemObject();
       
        try {
         

             I = clsSale(_enMode::UpdateMode, vItemData[0],
                vItemData[1], vItemData[2], stod(vItemData[3]), stoi(vItemData[4]), stod(vItemData[5]));
        }
        catch (exception e) {
            I = clsSale(_enMode::UpdateMode, vItemData[2],
                vItemData[3], vItemData[4], stod(vItemData[5]) , stoi(vItemData[6]), stod(vItemData[7]));
        }

        return I;

    }
   
    static  vector <clsSale>   _LoadItemsDataFromFile()
    {

        vector <clsSale> vItems;


        fstream MyFile;
        MyFile.open("Items.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;


            while (getline(MyFile, Line))
            {

                clsSale Item = _ConvertLinetoItemsObject(Line);
              
                    vItems.push_back(Item);
                
            }

            MyFile.close();

        }

        return vItems;

    }

    string _ConverItemObjectToLine(clsSale Item, string Seperator = "#//#")
    {


        string stDsataRecord = "";
        
        
        stDsataRecord  = Item.ItemCode + Seperator;
        stDsataRecord += Item.NameItem + Seperator;
        stDsataRecord += Item.TypeItem + Seperator;
        stDsataRecord += to_string(Item.Price) + Seperator;
        stDsataRecord += to_string(Item.Quantity) + Seperator;
        stDsataRecord += to_string(Item.Tax) + Seperator;

        return stDsataRecord;

    }

    void _SaveItemsObjectToFile(vector<clsSale> vItems) {

        fstream MyFile;
        string DataLine = "";
        MyFile.open("Items.txt", ios::out);

        if (MyFile.is_open()) {

            for (clsSale S : vItems) {

                if (S._MarketForDelete == false) {


                    DataLine = _ConverItemObjectToLine(S);

                    MyFile << DataLine << endl;



                }


            }

            MyFile.close();
        }


    }
    void _Update() {
        vector <clsSale> vItems = _LoadItemsDataFromFile();

        for (clsSale& S : vItems) {

            if (S.GetItemCode() == GetItemCode()) {

                S = *this;
                break;
            }

        }
        _SaveItemsObjectToFile(vItems);

    }

    void _AddNew()
    {

        _AddDataLineToFile(_ConverItemObjectToLine(*this));
    }
    void _AddDataLineToFile(string  stDataLine)
    {


        fstream MyFile;
        MyFile.open("Items.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }


public:
    clsSale(_enMode Mode, string ItemCode, string NameItem, string TypeItem, double Price, int Quantity, double Tax)
        :clsitems(NameItem, TypeItem, ItemCode, Price, Quantity, Tax)
    {
        _Mode = Mode;

    }

    _enMode Mode() {

        return _Mode;
    }

    static clsSale GetEmptyItemObject() {

        return clsSale(_enMode::EmptyMode, "", "", "", 0, 0, 0);

    }

    bool IsEmpty() {

        return (_Mode == _enMode::EmptyMode);
    }

    static clsSale FindItemCode(string ItemCode)
    {


        fstream MyFile;
        MyFile.open("Items.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsSale Item = _ConvertLinetoItemsObject(Line);


                if (Item.GetItemCode() == ItemCode)
                {
                    
                        MyFile.close();
                        return Item;
                    
                   
                }

            }

            MyFile.close();

        }

        return GetEmptyItemObject();
    }
    static clsSale FindItemName(string ItemName)
    {


        fstream MyFile;
        MyFile.open("Items.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsSale Item = _ConvertLinetoItemsObject(Line);
               

                if (Item.GetNameItem() == ItemName)
                {

                    MyFile.close();
                    return Item;


                }

            }

            MyFile.close();

        }

        return GetEmptyItemObject();
    }
    static clsSale FindItemType(string ItemType)
    {


        fstream MyFile;
        MyFile.open("Items.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsSale Item = _ConvertLinetoItemsObject(Line);


                if (clsString::UpperAllString(Item.GetTypeItem()) == clsString::UpperAllString(ItemType))
                {

                    MyFile.close();
                    return Item;


                }

            }

            MyFile.close();

        }

        return GetEmptyItemObject();
    }




    static clsSale GetAddNewItemObject( string ItemCode)
    {
        return clsSale(_enMode::AddNewMode

           , ItemCode, "", "", 0, 0, 0);
    }


    bool Delete() {

        vector<clsSale>vItems = _LoadItemsDataFromFile();


        for (clsSale& S : vItems) {

            if (S.ItemCode == ItemCode) {

                S._MarketForDelete = true;


                break;
            }

        }
        _SaveItemsObjectToFile(vItems);

        *this = GetEmptyItemObject();
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
            if (clsSale::IsItemExist(ItemCode))
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
    static bool IsTypeItemBook(string TypeItem) {
        
        return (TypeItem == "Books");
    }
    static vector<clsSale> GetItemsList() {
        return _LoadItemsDataFromFile();
    }
    static bool IsItemNameExist(string Itemname)
    {
        
        clsSale Item = clsSale::FindItemName(Itemname);

        return (!Item.IsEmpty());
    }
    static bool IsItemExist(string ItemCode)
    {

        clsSale Item = clsSale::FindItemCode(ItemCode);

        return (!Item.IsEmpty());
    }

    void DeleteSPecifiedQuantity(short Quan) {

        Quantity -= Quan;
        Save();
    }

};

