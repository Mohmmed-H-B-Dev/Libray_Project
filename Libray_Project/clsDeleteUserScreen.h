#pragma once
#include<iostream>
#include"clsScreen.h";
#include"clsInputValidate.h";
#include"clsUser.h";
#include"clsUtil.h"
using namespace std;
class clsDeleteUserScreen :protected clsScreen
{
private:
    static void _PrintUser(clsUser User) {
        cout << "\nUser Card : ";
        cout << "\n-----------------------\n";
        cout << "First Name   :    " << User.FirstName << endl;
        cout << "Last Name    :    " << User.LastName << endl;
        cout << "Full Name    :    " << User.GetFullName() << endl;
        cout << "Email        :    " << User.Email << endl;
        cout << "Phone        :    " << User.Phone << endl;
        cout << "User Name    :    " << User.UserName << endl;
        cout << "Password     :    " << User.Password << endl;
        cout << "Permissions  :    " << User.Permissions << endl;
        cout << "Permissions  :    " << User.CurrentPosition << endl;
        cout << "\n-----------------------\n";
    }

public:

    static void ShowDeleteClient() {

        _DrawScreenHeader("Delete Usser");
        string UserName = "";
        cout << "\nEnter User Name : ";
        UserName = clsInputValidate::ReadString();

        while (!clsUser::IsUserExist(UserName))
        {

            cout << "\nUser Name Is Not Fond , Enter User Name Again : ";
            UserName = clsInputValidate::ReadString();

        }

        clsUser  User = clsUser::Find(UserName);
        User.Password = clsUtil::EncryptText(User.Password, 270);
        _PrintUser(User);

        if (clsInputValidate::IsYas("Delete this User ")) {

            if (User.Delete())
            {
                cout << "\nDelete User Scceessfuly . ";
                _PrintUser(User);
            }
            else {
                cout << "\nError, Delete User is Not Sccessded";
            }
        }
    }



};

