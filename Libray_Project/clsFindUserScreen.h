#pragma once
#include <iostream>
#include"clsInputValidate.h";
#include <vector>
#include"clsUser.h";
#include "clsScreen.h";

class clsFindUserScreen :protected clsScreen
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
    static void ShowFindUser() {

        _DrawScreenHeader("Find User Screen");
        string UserName = "";

        cout << "Enter User Name : " << endl;
        cin >> UserName;
        while (!clsUser::clsUser::IsUserExist(UserName)) {

            cout << "Enter Account Number : " << endl;
            UserName = clsInputValidate::ReadString();
        }

        clsUser User =
            clsUser::Find(UserName);

        if (!User.IsEmpty()) {

            cout << "\nUser Found :-) \n";
        }
        else {
            cout << "\nUser Is Not Found :-( /n";
        }
        _PrintUser(User);






    }
};

