#pragma once
#include<iostream>

#include"clsScreen.h"
#include"clsInputValidate.h"
using namespace std;

class clsUpdateAuthortScreen : protected clsScreen

{

private:
    static void _ReadAuthorProfile(clsUser& Author) {



        cout << "\nEnter First Name : ";
        Author.FirstName = clsInputValidate::ReadString();

        cout << "\nEnter Last Name : ";
        Author.LastName = clsInputValidate::ReadString();

        cout << "\nEnter Password : ";
        Author.Password = clsInputValidate::ReadString();

        cout << "\nEnter Phone : ";
        Author.Phone = clsInputValidate::ReadString();

        cout << "\nEnter Email : ";
        Author.Email = clsInputValidate::ReadString();




    


    }

    static void _PrintProfileAuthor(clsUser Author) {
        cout << "\nAuther Card : ";
        cout << "\n-----------------------\n";
        cout << "First Name   :    " << Author.FirstName << endl;
        cout << "Last Name    :    " << Author.LastName << endl;
        cout << "Full Name    :    " << Author.GetFullName() << endl;
        cout << "Password     :    " << Author.Password << endl;
        cout << "Email        :    " << Author.Email << endl;
        cout << "Phone        :    " << Author.Phone << endl;
        cout << "User Name    :    " << Author.UserName << endl;
        cout << "\n-----------------------\n";
    }

public :

    static void ShowUpdatAuthor() {
       /* if (!CheckAccessReghts(clsUser::enPermissions::pUpdateClients)) {

            return;
        }*/
        _DrawScreenHeader("\tUpdate Profile Author Screen");
        string UserName = "";
        if (CurrentUser.UserName == "Admin" || CurrentUser.CurrentPosition == "M") {
            cout << "\nEnter User Name";
            UserName = clsInputValidate::ReadString();
            while (!clsUser::IsUserExist(UserName)) {
                cout << "\nEnter User Name";
                UserName = clsInputValidate::ReadString();
                cout << "\n\nDo You want Stop Search Author? [y] OR [n] ? ";
                char Answor = 'n';
                cin >> Answor;
                if (tolower(Answor) == 'y') {
                    return;
                }
            }
        }
        else {
            UserName = CurrentUser.UserName;
        }
      
      

        clsUser  Author =
            clsUser::Find(UserName);
        _PrintProfileAuthor(Author);

        cout << "\n    Updata  Profile Author    \n";

        _ReadAuthorProfile(Author);


        if (clsInputValidate::IsYas("Update Profile Author ")) {

            clsUser::enSaveResults SaveResult = Author.Save();
            switch (SaveResult)
            {
            case clsUser::svFaildEmptyObject:
                cout << "Error account Was not Saved Because it`s Epmty : \n";
                break;
            case clsUser::svSucceeded:


                cout << "Account Update Successfuly : \n";
                _PrintProfileAuthor(Author);
                break;

            }
        }

    }


};

