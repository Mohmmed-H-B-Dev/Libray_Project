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

class clsInvoice
{

 //«b4·Œÿ… ﬂ «·« Ì  ”ÌﬂÊ‰ ·ÿ—ﬁ «·œ›⁄ „·› Œ«’ »Â« „— »ÿ… »—ﬁ„ «·›« Ê—… Ê«· «—ÌŒ
 //    Ê ··«’‰«› „⁄ «”⁄«—Â« ﬁ»· «·÷—Ì»… Ê«·ﬂ„ÌÂ „·› Œ«’ „— »ÿ »—ﬁ„ «·›« Ê—… Ê«· «—ÌŒ

 //    ”Ì „ «÷«›… ﬂ· ’‰› ›Ì ”·… «·„‘ —«Ì«  «·Ì «·„·› «·Œ«’ ›ÌÂ 

private:
    enum _enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };

      /*string DateTime;
       string NumberInvoice;
       string PaymentMethod;
       string Amount; 

       string NameItems;
       string PricItems;  
       string Quantitiy;
       _enMode _Mode;*/
      

    static    class MyPaymentMethod
       {
       private:
           string _DateTime;
           string _NumberInvoice;
           string _PaymentMethod;
           double _Amount;
           _enMode _Mode;
           static MyPaymentMethod GetEmptyItemObject() {

               return MyPaymentMethod(_enMode::EmptyMode,"", "", 0, "");

           }
           static MyPaymentMethod _ConvertLinetoItemsObject(string Line, string Seperator = "#//#")
           {
               vector<string> vItemData;

               vItemData = clsString::Split(Line, Seperator);

               MyPaymentMethod I = GetEmptyItemObject();
               I = MyPaymentMethod(_enMode::UpdateMode,
                   vItemData[0], vItemData[1], stoi(vItemData[2]), vItemData[3]);

               return I;



           }
           string _ConverItemObjectToLine(MyPaymentMethod Item, string Seperator = "#//#")
           {


               string stDsataRecord = "";


               stDsataRecord = Item.NumberInvoice + Seperator;
               stDsataRecord += Item.PaymentMethod + Seperator;
               
               stDsataRecord += to_string(Item.Amount) + Seperator;
             
               stDsataRecord += Item._DateTime + Seperator;

               return stDsataRecord;

           }
           static  vector <MyPaymentMethod>   _LoadItemsDataFromFile()
           {

               vector <MyPaymentMethod> vItems;


               fstream MyFile;
               MyFile.open("PaymentMethod.txt", ios::in);//read Mode

               if (MyFile.is_open())
               {

                   string Line;


                   while (getline(MyFile, Line))
                   {

                       MyPaymentMethod Item = _ConvertLinetoItemsObject(Line);

                       vItems.push_back(Item);

                   }

                   MyFile.close();

               }

               return vItems;

           }
           void _AddNew()
           {

               _AddDataLineToFile(_ConverItemObjectToLine(*this));
           }
           void _AddDataLineToFile(string  stDataLine)
           {


               fstream MyFile;
               MyFile.open("PaymentMethod.txt", ios::out | ios::app);

               if (MyFile.is_open())
               {

                   MyFile << stDataLine << endl;

                   MyFile.close();
               }

           }
       public:
           MyPaymentMethod(_enMode Mode, string NumberInvoice, string PaymentMethod,  double Amount,
                string  DateTime) {

               _Mode = Mode;
           }
           enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildAccountNumberExists = 2, eNothing = -1 };

           bool IsEmpty() {

               return (_Mode == _enMode::EmptyMode);
           }_enMode Mode() {

               return _Mode;
           }
           void SetPaymentMethod(string PaymentMethod) {

               _PaymentMethod = PaymentMethod;
           }
           string GetPaymentMethod()
           {
               return _PaymentMethod;
           }
           __declspec(property(get = GetPaymentMethod, put = SetPaymentMethod)) string  PaymentMethod;
           void SetNumberInvoice(string NumberInvoice) {

               _NumberInvoice = NumberInvoice;
           }
           string GetNumberInvoice()
           {
               return _NumberInvoice;
           }
           __declspec(property(get = GetNumberInvoice, put = SetNumberInvoice)) string  NumberInvoice;
           void SetAmount(double Amount) {

               _Amount = Amount;
           }
           double GetAmount()
           {
               return _Amount;
           }
           __declspec(property(get = GetAmount, put = SetAmount)) double  Amount;
           ~MyPaymentMethod();




           enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildAccountNumberExists = 2, eNothing = -1 };

           static MyPaymentMethod FindItemCode(string NumberInvoice)
           {


               fstream MyFile;
               MyFile.open("PaymentMethod.txt", ios::in);//read Mode

               if (MyFile.is_open())
               {
                   string Line;
                   while (getline(MyFile, Line))
                   {
                       MyPaymentMethod Item = _ConvertLinetoItemsObject(Line);


                       if (Item.GetNumberInvoice() == NumberInvoice)
                       {

                           MyFile.close();
                           return Item;


                       }

                   }

                   MyFile.close();

               }

               return GetEmptyItemObject();
           }

           static bool IsItemExist(string ItemCode)
           {

               ItemsBuyed Item = ItemsBuyed::FindItemCode(ItemCode);

               return (!Item.IsEmpty());
           }
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
                   if (clsSale::IsItemExist(NumberInvoice))
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


                   cout << "\n\t\t\tNo Found Any Thing...................\n\n";

                   return enSaveResults::svSucceeded;

                   break;
               }


               }
               return enSaveResults::eNothing;
           }
       private:

       };

    static    class ItemsBuyed
       {
       private:
           string DateTime;
           string _NumberInvoice;
           string _ItemCode;
           string _NameItems;
           double _PricItems;
           int _Quantity;
           _enMode _Mode;
           static ItemsBuyed GetEmptyItemObject() {

               return ItemsBuyed(_enMode::EmptyMode, "", "", "", 0, 0,"");

           }
           static ItemsBuyed _ConvertLinetoItemsObject(string Line, string Seperator = "#//#")
           {
               vector<string> vItemData;

        vItemData = clsString::Split(Line, Seperator);

               ItemsBuyed I = GetEmptyItemObject();         
                  I = ItemsBuyed(_enMode::UpdateMode,
                       vItemData[0], vItemData[1], vItemData[2], stod(vItemData[3]), stoi(vItemData[4]), vItemData[5]);
              
               return I;



           }
           string _ConverItemObjectToLine(ItemsBuyed Item, string Seperator = "#//#")
           {


               string stDsataRecord = "";


               stDsataRecord = Item.NumberInvoice+ Seperator;
               stDsataRecord += Item.ItemCode + Seperator;
               stDsataRecord += Item.NameItem + Seperator;
               stDsataRecord += to_string(Item.Price) + Seperator;
               stDsataRecord += to_string(Item.Quantity) + Seperator;
               stDsataRecord +=Item.DateTime+ Seperator;

               return stDsataRecord;

           }
           void _AddNew()
           {

               _AddDataLineToFile(_ConverItemObjectToLine(*this));
           }
           void _AddDataLineToFile(string  stDataLine)
           {


               fstream MyFile;
               MyFile.open("ItemsBuyed.txt", ios::out | ios::app);

               if (MyFile.is_open())
               {

                   MyFile << stDataLine << endl;

                   MyFile.close();
               }

           }
           static  vector <ItemsBuyed>   _LoadItemsDataFromFile()
           {

               vector <ItemsBuyed> vItems;


               fstream MyFile;
               MyFile.open("ItemsBuyed.txt", ios::in);//read Mode

               if (MyFile.is_open())
               {

                   string Line;


                   while (getline(MyFile, Line))
                   {

                       ItemsBuyed Item = _ConvertLinetoItemsObject(Line);

                       vItems.push_back(Item);

                   }

                   MyFile.close();

               }

               return vItems;

           }
       public:
           ItemsBuyed(_enMode Mode, string _NumberInvoice,   string _ItemCode,
               string _NameItems,
               double _PricItems,
               int _Quantitiy,string  DateTime ) {

               _Mode = Mode;
           }
           
           ~ItemsBuyed();


           enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildAccountNumberExists = 2, eNothing = -1 };

           bool IsEmpty() {

               return (_Mode == _enMode::EmptyMode);
           }_enMode Mode() {

               return _Mode;
           }
           void SetNameItem(string NameItem) {

               _NameItems = NameItem;
           }
           string GetNameItem()
           {
               return _NameItems;
           }
           __declspec(property(get = GetNameItem, put = SetNameItem)) string  NameItem;
           void SetNumberInvoice(string NumberInvoice) {

               _NumberInvoice = NumberInvoice;
           }
           string GetNumberInvoice()
           {
               return _NumberInvoice;
           }
           __declspec(property(get = GetNumberInvoice, put = SetNumberInvoice)) string  NumberInvoice;
           void SetItemCode(string ItemCode) {

               _ItemCode = ItemCode;
           }
           string GetItemCode()
           {
               return _ItemCode;
           }
           __declspec(property(get = GetItemCode, put = SetItemCode)) string  ItemCode;
           void SetPrice(double Price) {

               _PricItems = Price;
           }
           double GetPrice()
           {
               return _PricItems;
           }
           __declspec(property(get = GetPrice, put = SetPrice)) double  Price;
           void SetQuantity(short Quantity) {

               _Quantity = Quantity;
           }
           short GetQuantity()
           {
               return _Quantity;
           }
           __declspec(property(get = GetQuantity, put = SetQuantity)) short  Quantity;
           static ItemsBuyed FindItemCode(string NumberInvoice)
           {


               fstream MyFile;
               MyFile.open("ItemsBuyed.txt", ios::in);//read Mode

               if (MyFile.is_open())
               {
                   string Line;
                   while (getline(MyFile, Line))
                   {
                       ItemsBuyed Item = _ConvertLinetoItemsObject(Line);


                       if (Item.GetNumberInvoice() == NumberInvoice)
                       {

                           MyFile.close();
                           return Item;


                       }

                   }

                   MyFile.close();

               }

               return GetEmptyItemObject();
           }

           static bool IsItemExist(string ItemCode)
           {

               ItemsBuyed Item = ItemsBuyed::FindItemCode(ItemCode);

               return (!Item.IsEmpty());
           }
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
                   if (clsSale::IsItemExist(NumberInvoice))
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


                   cout << "\n\t\t\tNo Found Any Thing...................\n\n";

                   return enSaveResults::svSucceeded;

                   break;
               }


               }
               return enSaveResults::eNothing;
           }
          static  string  GetLastNumInvoice() {
               vector<ItemsBuyed> vItems = _LoadItemsDataFromFile();
               vector<ItemsBuyed>::iterator  itor;
               /*for (itor = vItems.end() - 1; itor != vItems.begin(); itor--) {
                   ItemsBuyed it = *vItems.end();
               }*/
               ItemsBuyed Item=  *vItems.end();
               

               return Item.NumberInvoice;
           }
       };
    

       _enMode _Mode;

       bool _MarketForDelete = false;

      // »«ﬂ— ”Ì „ «÷«›… «·»Ì«‰«  «·Ì «·„·›«  «·Œ«’… »Â« 

      /* static clsInvoice GetEmptyItemObject() {

           return clsInvoice(_enMode::EmptyMode, "", "", "", 0, 0, "");

       }*/


   /*    static clsInvoice _ConvertLinetoItemsObject(string Line, string Seperator = "#//#")
       {


           vector<string> vItemData;



           vItemData = clsString::Split(Line, Seperator);

           clsInvoice I = GetEmptyItemObject();

           try {


               I = clsSale(_enMode::UpdateMode, vItemData[0],
                   vItemData[1], vItemData[2], stod(vItemData[3]), stoi(vItemData[4]), stod(vItemData[5]));
           }
           catch (exception e) {
               I = clsSale(_enMode::UpdateMode, vItemData[2],
                   vItemData[3], vItemData[4], stod(vItemData[5]), stoi(vItemData[6]), stod(vItemData[7]));
           }

           return I;

       }*/

      
     
public:
    clsInvoice(string DateTime,
    string NumberInvoice,
    string PaymentMethod,
    string Amount,  string NameItems,
    string PricItems, string Quantitiy)
    {
       

    }

    static   string  GetLastNumInvoice() {
        return  ItemsBuyed::GetLastNumInvoice();
    }

};

