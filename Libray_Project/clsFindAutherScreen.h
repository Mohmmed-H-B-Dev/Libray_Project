#pragma once
#include<iostream>

#include"clsScreen.h"
#include"clsAuthers.h"
#include"clsInputValidate.h"
using namespace std;


class clsFindAutherScreen : protected clsScreen
{

private: 
    static void _PrintAuther(clsAuthers Auther) {
    cout << "\nAuther Card : ";
    cout << "\n-----------------------\n";
    cout << "First Name   :    " << Auther.FirstName << endl;
    cout << "Last Name    :    " << Auther.LastName << endl;
    cout << "Full Name    :    " << Auther.GetFullName() << endl;
    cout << "Email        :    " << Auther.Email << endl;
    cout << "Phone        :    " << Auther.Phone << endl;
    cout << "ID. Auther   :    " << Auther.IDAuther << endl;
    cout << "NofB_Added   :    " << Auther.NOFB_Added << endl;

    cout << "\n-----------------------\n";
}

public:

    static void ShowFindAuther() {
       /* if (!CheckAccessReghts(clsUser::enPermissions::pFindClient)) {

            return;
        }*/
        _DrawScreenHeader("\Find Auther Screen");
        string IDAuther = "";

        cout << "Enter ID Auther : " << endl;
        cin >> IDAuther;
        while (!clsAuthers::clsAuthers::IsAutherExist(IDAuther)) {

            cout << "Enter ID Auther : " << endl;
            IDAuther = clsInputValidate::ReadString();
        }

        clsAuthers Auther =
            clsAuthers::Find(IDAuther);

        if (!Auther.IsEmpty()) {

            cout << "\nAuther Found :-) \n";
        }
        else {
            cout << "\nAuther Is Not Found :-( /n";
        }
        _PrintAuther(Auther);






    }
};

