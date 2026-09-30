#pragma once
#include <iostream>
#include"clsInputValidate.h";
#include <vector>
#include"clsClient.h"
#include "clsScreen.h"
#include"clsAddNewClientScreen.h"

using namespace std;

class clsAddCustomerSubscriptionNumber:protected clsScreen
{

public:
	static void ShowAddClient() {

        _DrawScreenHeader("Add Client");
        string PhoneNumber = "";

        cout << "\nPlease Enter Phone Number : ";
        PhoneNumber = clsInputValidate::ReadString();

        if (!clsClient::IsClientByPhoneExist(PhoneNumber)) {
            cout<<"\nClient IS Not Exist.......\n";

            cout << "\n\tDo You Want Add New Client ?  [y] Or [n] ? : ";
            char Answor = 'n';
            cin >> Answor;
            if (tolower(Answor) == 'y') {

                clsAddNewClientScreen::AddNewClient();
            }
            else { return; }

        }
        else {
          
            
                AcceptShowClient = true;
                CurrentClient= clsClient::FindByPhone(PhoneNumber);
               
            }
        

       
	}
};

