#pragma once
#include<iostream>
#include"clsUser.h";
#include<ioManip>
#include"clsScreen.h";
#include <vector>

using namespace std;
class clsListUsersScreen :protected clsScreen
{


private:
    static void  _PrintUserRecordLine(clsUser User) {

        cout << left << setw(8) << "" << left << setw(15) << "| " + User.UserName;
        cout << left << setw(20) << "| " + User.FirstName + " " + User.LastName;
        cout << left << setw(12) << "| " + User.Phone;
        cout << left << setw(20) << "| " + User.Email;
        cout << left << setw(10) << "| " + User.Password;
        cout << left << setw(2) << "| ";
        cout << left << setw(11) << User.Permissions;
        cout << left << setw(2) << "| ";
        cout << left << setw(10) << User.CurrentPosition;
        cout << left << setw(3) << " |";

    }

public:

    static void ShowUsersList() {

        vector<clsUser> vUser1 = clsUser::GetUsersList();

        string  Title = "Users List";
        string SubTitle = "(" + to_string(vUser1.size()) + ") User (s)";

        _DrawScreenHeader(Title, SubTitle);

        cout << left << setw(8) << "" << "\n\t____________________________________________________________________________________________\n";

        cout << left << setw(8) << "" << left << setw(15) << "| User Name";
        cout << left << setw(20) << "| Full Name";
        cout << left << setw(12) << "| Phone";
        cout << left << setw(20) << "| Email";
        cout << left << setw(10) << "| Password";
        cout << left << setw(13) << "| Permissions";
        cout << left << setw(10) << "| Position";
        cout << left << setw(3) << " |";
        cout << left << setw(8) << "" << "\n\t____________________________________________________________________________________________\n";


        if (vUser1.size() == 0) {
            cout << "\t\t\t\t No, Users Available In the System!";
        }
        else {

            for (clsUser U : vUser1) {
                _PrintUserRecordLine(U);
                cout << endl;
            }
            cout << left << setw(8) << "" << "\n____________________________________________________________________________________________\n";

        }

    }

};

