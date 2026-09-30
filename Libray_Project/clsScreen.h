#pragma once
#include <iostream>
#include"clsUser.h"
#include"clsDate.h"
#include"Global.h"
class clsScreen
{

protected:
    static void _DrawScreenHeader(string Title, string SubTitle = "",bool AcceptShowClient=false)
    {
        cout << "\t\t\t\t\t______________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________\n\n";

       ShowDateInScreen();
       if (AcceptShowClient) {
           ShowDataClient();
       }

    }
    static void ShowDataClient() {
        cout << "\n\t\t\t\tAccount Client:" << CurrentClient.GetAccountNumber();
        cout << "\n\t\t\t\tName    Client:" << CurrentClient.GetFullName();
        cout << "\n\t\t\t\tPoints  Client:" << CurrentClient.AccountBalance;
       
    }
    static void ShowDateInScreen() {

        cout << "\n\t\t\t\tUser:" << CurrentUser.GetUserName();
        clsDate Date;
        cout << "\n\t\t\t\tDate:" << Date.DateToString() << "\n" << endl;

    } 
    static bool CheckAccessReghts(clsUser::enPermissions Permissons) {

        if (!CurrentUser.ChechAccesspermissions(Permissons)) {
            cout << "\t\t\t\t\t______________________________";
            cout << "\n\t\t\t\t\t  Access Denied!  Counact Your Admin...";
            cout << "\n\t\t\t\t\t______________________________\n\n";
            return false;
        }
        else
            return true;

    }
};

