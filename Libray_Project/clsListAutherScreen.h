#pragma once
#include<iostream>
#include"clsAuthers.h";
#include<iomanip>
#include"clsScreen.h";

class clsListAutherScreen : protected clsScreen
{

private:
    static void  _PrintAutherRecordLine(clsAuthers Auther) {

        cout << left << setw(8) << "" << left << setw(15) << "| " + Auther.IDAuther;
        cout << left << setw(20) << "| " + Auther.FirstName + " " + Auther.LastName;
        cout << left << setw(12) << "| " + Auther.Phone;
        cout << left << setw(20) << "| " + Auther.Email;
        cout << left << setw(10) << "| " +to_string( Auther.NOFB_Added);
        cout << left << setw(2) << "| ";
       
    }

public:

    static void ShowAuthersList() {
      /*  if (!CheckAccessReghts(clsUser::enPermissions::pListClients)) {

            return;
        }*/
        vector<clsAuthers>vAuthers = clsAuthers::GetAuthersList();

        string  Title = "Auther List";
        string SubTitle = "(" + to_string(vAuthers.size()) + ") Auther (s)";

        _DrawScreenHeader(Title, SubTitle);

        cout << left << setw(8) << "" << "\n\t____________________________________________________________________________________________\n";

        cout << left << setw(8) << "" << left << setw(15) << "| ID, Auther";
        cout << left << setw(20) << "| Auther Name";
        cout << left << setw(12) << "| Phone";
        cout << left << setw(20) << "| Email";
        cout << left << setw(10) << "| NoFB_Added";
        cout << left << setw(3) << " |";
        cout << left << setw(8) << "" << "\n\t____________________________________________________________________________________________\n";


        if (vAuthers.size() == 0) {
            cout << "\t\t\t\t No, Authers Available In the System!";
        }
        else {

            for (clsAuthers A : vAuthers) {
                _PrintAutherRecordLine(A);
                cout << endl;
            }
            cout << left << setw(8) << "" << "\n____________________________________________________________________________________________\n";

        }

    }
};

