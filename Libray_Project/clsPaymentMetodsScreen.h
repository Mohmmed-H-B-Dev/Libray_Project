
#pragma once

#include"clsInputValidate.h"
#include<iomanip>

#include"clsUser.h"
#include"clsScreen.h"
#include"clsDeleteItemScreen.h"
#include"Global.h"

using namespace std;

class clsPaymentMetodsScreen:protected clsScreen
{

private:
    

    
	enum _enPaymentMethods{eCadh=1,eMade=2,ePointsClient=3};

    static short _ReadPaymentMethodsOption()
    {

        short Choice = clsInputValidate::ReadNumberBetween<short>(1, 3, "\n\t\t\t\t\tChooce  Number to Specify the Payment Method  Between 1 and 3 : ");



        return Choice;
    }

   static double  _ReadAllPrice()
    {
       cout << "\nSelect Amount : ";
     double  Amount = clsInputValidate::ReadNumber<double>();
       return Amount;
       
    }
     
    static void _IfQuantityIsEmpty() {
        vector <clsSale> vItem = clsSale::GetItemsList();

        for (clsSale& item : vItem) {
            if (item.Quantity == 0) {
                item.Delete();
               
            }
        }
       
    }
    
    static void PaymentProcess(string PaymentMethods="", double Amount=0.0) {
        short i = 0;
        PaymentMethod = PaymentMethods; NumberOfInvoice++;
        
        for (clsSale Item : vCart) {

            clsDeleteItemScreen::DeleteItemAfterPurchaseProcess(Item.ItemCode,Item.Quantity);
            }
     
      
        vCart.clear();
   
        
    }

    static  void CalculationPoints(double &Points) {
         Points = TotalPrice * 0.045;
        CurrentClient.AddPoints(Points);
        AcceptShowClient = false;
        CurrentClient = clsClient::FindByPhone("");
}

    static bool SelectAmount(double Amount) {
      if (Amount == TotalPrice)
          return true;
      else 
          return false;
  }

    static void _PerfromPaymentMethodsOption(_enPaymentMethods PayMentMethods, double &Points) {
        double Amount = _ReadAllPrice();
        switch (PayMentMethods)
        {

       //    ÌÊÃœ ﬁ’Ê— ›Ì œﬁ… «·„»·€ «·„œ›Ê⁄ Ê«·”⁄— «·«”«”Ì ›Ì ﬂ· «·ÿ—ﬁ Ì—œ∆ „—«Ã⁄… ÿ—ﬁ «·œ›⁄ Ê»œﬁ… ⁄«·Ì… Ê»Õ—›Ì…

        case clsPaymentMetodsScreen::eCadh:
          
            if (!SelectAmount(Amount)) {
                DLLStoragePayMetheds.InsertAtEnd(Amount, "Cash");
                if (_TempTotalePrice == 0) {
                    PaymentProcess();
                }
                _TempTotalePrice -= Amount;
            }
            else{
                _TempTotalePrice = 0;
                PaymentProcess("Cash", TotalPrice);

            }


           
           /// _IfQuantityIsEmpty();
          
            if (clsClient::IsClientExist(CurrentClient.AccountNumber)) {
                CalculationPoints(Points);
            }

            break;
        case clsPaymentMetodsScreen::eMade:
          
            if (!SelectAmount(Amount)) {
                DLLStoragePayMetheds.InsertAtEnd(Amount, "Made");
                if (_TempTotalePrice == 0) {
                    PaymentProcess();
                }
                _TempTotalePrice -=Amount;
            }
            else {
                _TempTotalePrice = 0;
                PaymentProcess("Made", TotalPrice);

            }
          
            //_IfQuantityIsEmpty();
            if (clsClient::IsClientExist(CurrentClient.AccountNumber)) {
                CalculationPoints(Points);
            }
            break;

        case clsPaymentMetodsScreen::ePointsClient:

          

            if (!CurrentClient.Withdrow(Amount)) {

                if (!SelectAmount(Amount)) {

                    DLLStoragePayMetheds.InsertAtEnd(Amount, "Points Client");

                    if (_TempTotalePrice == 0) {
                        PaymentProcess();
                    }
                    _TempTotalePrice -= Amount;                  
                }
                else {
                    _TempTotalePrice = 0;
                    PaymentProcess("Points Client", TotalPrice);

                }

                if (clsClient::IsClientExist(CurrentClient.AccountNumber)) {
                    CalculationPoints(Points);
                }
            }
            //_IfQuantityIsEmpty();

           

           
            break;
        default:
            break;
        }

    }


public:

    static void ShowPaymentMethods()

    {

        system("cls");

        _DrawScreenHeader("Payment Methods");
        _TempTotalePrice = TotalPrice;
        cout << left << setw(20) << " " << "========================================================================================\n\n";

        cout << left << setw(22) << " " << "[1]  Cash.";

        cout << left << setw(22) << " " << "[2]  Made.";
        
        cout << left << setw(22) << " " << "[2]  Points Clinet.\n";
        
    
        double Points = 0.0;
        cout << left << setw(20) << " " << "========================================================================================\n";

        cout << left << setw(18) << " " << "========================================================================================\n\n";
        cout << left << setw(22) << " " << "|Total     : " << _TempTotalePrice << "|\n";
        cout << left << setw(18) << " " << "========================================================================================\n";
        while ((int) _TempTotalePrice != 0) {
            _PerfromPaymentMethodsOption((_enPaymentMethods)_ReadPaymentMethodsOption(), Points);

        }
       
        TotalPrice = 0;
        PriceExTax = 0.0, Tax = 0.0, TotalPriceExTax = 0.0;
    }
};

