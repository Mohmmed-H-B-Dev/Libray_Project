#pragma once
#include <iostream>
#include"clsInputValidate.h";
#include <vector>
#include"clsClient.h"
#include "clsScreen.h"


using namespace std;

class clsAddNewClientScreen : protected clsScreen
{

private:
    static void _ReadClientInfo(clsClient& Client ) {



        cout << "\nEnter First Name : ";
        Client.FirstName = clsInputValidate::ReadString();

        cout << "\nEnter Last Name : ";
        Client.LastName = clsInputValidate::ReadString();

        cout << "\nEnter Phone : ";
        Client.Phone = clsInputValidate::ReadString();

        cout << "\nEnter Email : ";
        Client.Email = clsInputValidate::ReadString();

       

       
        Client.AccountBalance = 0;


    }

    static void _PrintClient(clsClient Client) {
        cout << "\nClient Card : ";
        cout << "\n-----------------------\n";
        cout << "First Name   :    " << Client.FirstName << endl;
        cout << "Last Name    :    " << Client.LastName << endl;
        cout << "Full Name    :    " << Client.GetFullName() << endl;
        cout << "Email        :    " << Client.Email << endl;
        cout << "Phone        :    " << Client.Phone << endl;
        cout << "Acc. Number  :    " << Client.AccountNumber << endl;
        cout << "Balance      :    " << Client.AccountBalance << endl;
        cout << "\n-----------------------\n";
    }

public:
    static void AddNewClient() {

        _DrawScreenHeader("Add New Client");
        string AccountNumber = "C";
        cout << "\nPlease Enter Account Number : ";
        AccountNumber = clsInputValidate::ReadString();
       

        while (clsClient::IsClientExist(AccountNumber)) {
            cout << "\nAccount Number Exists , Please Enter Account Number : ";
            AccountNumber = clsInputValidate::ReadString();
        }


        clsClient NewClient = clsClient::GetAddNewClient(AccountNumber);



        _ReadClientInfo(NewClient);
        clsClient::enSaveResults SaveResult;
        if (clsInputValidate::IsYas("Add this Client ")) {

            SaveResult = NewClient.Save();

            switch (SaveResult)
            {
            case clsClient::svFaildEmptyObject:
                cout << "Error account Was not Saved Because it`s Epmty : \n";
                break;
            case clsClient::svSucceeded:
                cout << "Client Add Succeessfuly. " << endl;
                CurrentClient = NewClient;
                _PrintClient(NewClient);
                break;
            case clsClient::svFailAccountNumberExists:
                cout << "Account Number Exists . " << endl;
                break;
            default:
                break;
            }


        }

    }
};

