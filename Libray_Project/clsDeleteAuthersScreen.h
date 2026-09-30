#pragma once
#include<iostream>
#include"clsScreen.h";
#include"clsInputValidate.h";
#include"clsAuthers.h";

using namespace std;

class clsDeleteAuthersScreen : protected clsScreen
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

    static void ShowDeleteAuther() {
      /*  if (!CheckAccessReghts(clsUser::enPermissions::pDeleteClient)) {

            return;
        }*/
        _DrawScreenHeader("Delete Auther");
        string IDAuther = "";
        cout << "\nEnter IDA uther : ";
        IDAuther = clsInputValidate::ReadString();

        while (!clsAuthers::IsAutherExist(IDAuther))
        {

            cout << "\nID Auther Is Not Fond , Enter ID Auther Again : ";
            IDAuther = clsInputValidate::ReadString();

        }

        clsAuthers  Auther = clsAuthers::Find(IDAuther);

        _PrintAuther(Auther);

        if (clsInputValidate::IsYas("Delete this Auther ")) {

            if (Auther.Delete())
            {
                cout << "\nDelete Auther Scceessfuly . \n\n";
                _PrintAuther(Auther);
            }
            else {
                cout << "\nError, Delete Auther is Not Sccessded";
            }
        }
    }


};

