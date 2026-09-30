//ProgrammingAdivces.com
//Mohammed Abu-Hadhoud

#pragma once
#include <iostream>
#include <string>
#include "clsString.h"
#include "clsDate.h"

using namespace std;

class clsInputValidate
{

public:
	template <typename T> static T ReadNumber(string ErrorMessage = "Invalid Number, Enter again\n") {
		T Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}

	template <typename T> static T IsNumberBetween(T Number, T From, T To) {

		if (Number >= From && Number <= To)
			return true;
		else
			return false;
	}

	template <typename T> static T ReadNumberBetween(T From, T To, string Massage) {
		T Number = 0;
		cout << endl;

		do {
			cout << "\n\t\t\t\t\t" << Massage;
			cin >> Number;
			if (!IsNumberBetween<int>(Number, From, To)) {
				cout << "\n\t\t\t\t\t" << "Invalid Number, Enter again\n";
			}

			while (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid Number, Enter again,  " << Massage << "\n";
				cin >> Number;
			}

		} while (!IsNumberBetween<int>(Number, From, To));


		return Number;
	}



	static bool IsDateBetween(clsDate Date, clsDate From, clsDate To)
	{
		//Date>=From && Date<=To
		if ((clsDate::IsDate1AfterDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From))
			&&
			(clsDate::IsDate1BeforeDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To))
			)
		{
			return true;
		}

		//Date>=To && Date<=From
		if ((clsDate::IsDate1AfterDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To))
			&&
			(clsDate::IsDate1BeforeDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From))
			)
		{
			return true;
		}

		return false;
	}

	static bool IsYas(string Title_AfffirmationOf) {

		cout << "\n\tAre You Sure You Want  " << Title_AfffirmationOf << " ?  [y] Or [n] ? : ";
		char Answor = 'n';
		cin >> Answor;
		if (tolower(Answor) == 'y')
			return true;
		else
			return false;
	}

	static bool Is50_OR100OToEnd(double Number) {

		if ((int)Number % 50 == 0) {
			return true;
		}
		return false;
	}

	static bool IsTrue(bool True) {

		if (True)
			return true;

		return false;
	}

	static bool IsValideDate(clsDate Date)
	{
		return	clsDate::IsValidDate(Date);
	}

	static string ReadString() {

		string S1;
		getline(cin >> ws, S1);
		return S1;
	}




};


