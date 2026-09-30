#pragma once
#include<iostream>
#include"clsDate.h";
#include"clsScreen.h"
using namespace std;

class clsPrintInvoiceScreen:protected clsScreen
{
    string ItemsBuyed = "ItemsBuyed.txt";

public :

	static void ShowPrintInvoice() {

		_DrawScreenHeader("Print Invoice");
        //   ãáÇÌÙå ÈÌá Úãá ÈÍË ÇÕäÇİ İí ÔÇÔÉ ÇáÈÇÆÚ 


        //åäÇ ÓíÊã ÊÎÒíä Úãáíå ÇáÏİÚ æÊåÒíäåÇ İí ãáİ ÇáÇíÕÇáÇÊ  ÇáİæÇÊíÑ

        //  
        //    ÇáÈíÇäÇÊ ÇáÊí ÓíÊã ÊÎÒíäåÇ İí ãáİ ÇáÇíÕÇáÇÊ
        //    1 ÊÇÑíÎ ÇáİÇÊæÑÉ  good
        //    2 ØÑíŞÉ ÇáÏİÚ   good
        //    3 ÑŞã ÇÔÊÑß ÇáÚãíá  good
        //    4 ÇáÚäæÇä 
        //    5 ÑŞã ÇáİÇÊæÑÉ 
        // 
        //    6 ÑŞã ÇáßÇÔíÑ good
        //    7 ÇáÇÕäÇİ ÇáãÈÇÚÉ vItemsBayed    good
        //    8 ÑŞã ÇáÎÒíäÉ(ÈãÚäì íæÌÏ ÇßËÑãä ÎÒäÉ ááÔÑßå  æßá ãäØŞÉ áÏíåÇ ÎÒäÉ)

        //    9 æÇáãÈáÛ ÇáãÏİæÚ  æÊİÇÕíá Úä ÇáÓÚÑ ŞÈá æÈÚÏ ÇáÖÑíÈÉ

        cout << "\n\t\t\t\t\t  " << clsDate::GetSystemDateTimeString();
        
        cout << endl;
        if (DLLStoragePayMetheds.IsEmpty()) {
          //   ÊæÌÏ ãÔßáÉ İí ÇáãÓÊŞÈá æåí ÚäÏ ÇÖÇİÉ ØÑíŞÉ æÇÍÏÉ Çæ ÇßËÑ İí ŞÇÚÏÉ ÇáÈíÇäÇÊ 
         //   Íá åĞå ÇáãÔßáÉ Úãá äÙÇã á ÇÏÎÇá ÇäæÇÚ ØÑŞ ÇáÏİÚ ÈÇáÊÑÊíÈ  .... ÈãÚäÆ ÇÎÑ Úãá ÇæáæíÇÊ áßá ØÑíŞå ÏİÚ 
            cout << "\n\t\t\t\t\t  " << PaymentMethod;
            cout << "\n\t\t\t\t\t  " << amount;

        }
        else {
            DLLStoragePayMetheds.PrintList();
            cout << endl;
        }
        cout << "\n\t\t\t\t\t  " << CurrentClient.AccountNumber;

        cout << "\n\t\t\t\t\t  " << "Riyadh";
        cout << "\n\t\t\t\t\t  " <<"ELT_" + to_string(NumberOfInvoice);
        if (vItemsBuyed.empty()) {
            cout << "\n\t\t\t\t\t  No thing";
        }
        else {
            for (clsSale I : vItemsBuyed) {
                cout << "\n\t\t\t\t\t  " << I.NameItem;
                cout << "\n\t\t\t\t\t  " << I.Price;

            }
        }
        //Price After Tax   ... Doun

       // cout << "\n\t\t\t\t\t  " << TotalPrice;
	}
    //ÇáãÔßáÉ ÇáÇåã Ííä ÇÏÎá ÔÇÔÉ ÚãáíÉ ÇÎÑÆ æÇáÎÑæÌ ãäåÇ íËã ãÖÇÚİÉ ÇáÖÑíÈå æÇáÓÚÑ
};

