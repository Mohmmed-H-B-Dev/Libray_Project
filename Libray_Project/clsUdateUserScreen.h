#pragma once

#include<iostream>
#include"clsScreen.h";
#include"clsInputValidate.h";
#include"clsUser.h";

using namespace std;
class clsUdateUserScreen : protected clsScreen
{

private:


    static  int ReadPermissionsToSet()
    {

        int Permissions = 0;
        char Answer = 'n';


        cout << "\nDo you want to give full access? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            return -1;
        }

        cout << "\nDo you want to give access to : \n ";

        cout << "\nShow User List? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {


            Permissions += clsUser::enPermissions::pListClients;
        }


        cout << "\nAdd New User? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pAddNewClient;
        }

        cout << "\nDelete User? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pDeleteClient;
        }

        cout << "\nUpdate User? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pUpdateClients;
        }

        cout << "\nFind User? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pFindClient;
        }

        cout << "\nTransactions? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pTranactions;
        }

        cout << "\nManage Users? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pManageUsers;
        }

        cout << "\nShow Login Register? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pListLoginRegister;
        }

        return Permissions;

    }


    static void _ReadUserInfo(clsUser& User) {



        cout << "\nEnter First Name : ";
        User.FirstName = clsInputValidate::ReadString();

        cout << "\nEnter Last Name : ";
        User.LastName = clsInputValidate::ReadString();

        cout << "\nEnter Phone : ";
        User.Phone = clsInputValidate::ReadString();

        cout << "\nEnter Email : ";
        User.Email = clsInputValidate::ReadString();

        cout << "\nEnter Password : ";
        User.Password = clsInputValidate::ReadString();

        cout << "\nEnter Parmissions : \n";
        User.Permissions = ReadPermissionsToSet();


    }

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

    static void ShowUpdatUser() {

        _DrawScreenHeader("\tUpdate User Screen");
        string UserName = "";

        cout << "Enter User Name : " << endl;
        cin >> UserName;
        while (!clsUser::clsUser::IsUserExist(UserName)) {

            cout << "Enter Account Number : " << endl;
            UserName = clsInputValidate::ReadString();
        }

        clsUser User =
            clsUser::Find(UserName);
        _PrintUser(User);

        cout << "\n    Updata Client Info    \n";

        _ReadUserInfo(User);


        if (clsInputValidate::IsYas("Update this User ")) {

            clsUser::enSaveResults SaveResult = User.Save();
            switch (SaveResult)
            {
            case clsUser::svFaildEmptyObject:
                cout << "Error account Was not Saved Because it`s Epmty : \n";
                break;
            case clsUser::svSucceeded:


                cout << "Account Update Successfuly : \n";
                _PrintUser(User);
                break;

            }
        }

    }

};

