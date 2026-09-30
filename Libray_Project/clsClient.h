#pragma once
#include<iostream>
#include<fstream>
#include"clsPerson.h";
#include "clsString.h";
#include"string";
#include<vector>
#include"clsInputValidate.h";
#include"clsUtil.h"
using namespace std;


class clsClient : public  clsPerson
{
public:
	struct sTransferLogRegisterData {

		string Source_Account;
		string Destination_Account;
		string Amount;
		string Source_Balance;
		string Destination_Balance;
		string DateTime;
		string UserName;
	};
	static clsClient GetEmptyOpjectClient() {
		return clsClient(_enMode::EmptyMode, "", "", "", "", "", 0);
	}
private:

	string _AccountNumber;
	
	double _AccountBalance;
	bool _MarkedForDelete = false;

	enum _enMode { EmptyMode = 0, UpdateMode = 1, AddClient = 3 };
	_enMode _Mode;
	static sTransferLogRegisterData _PreparLogInRecordToOpject(string Line, string Sepretor = "#//#") {
		vector<string > vUser = clsString::Split(Line, Sepretor);
		sTransferLogRegisterData LogRegDate;
		LogRegDate.DateTime = vUser[0];
		LogRegDate.Source_Account = vUser[1];
		LogRegDate.Destination_Account = vUser[2];
		LogRegDate.Amount = vUser[3];
		LogRegDate.Source_Balance = vUser[4];
		LogRegDate.Destination_Balance = vUser[5];
		LogRegDate.UserName = vUser[6];

		return LogRegDate;


	}
	/*string _PreparTransferToRecord(double Amount, clsBankClient DestintionClient, string UserName, string Sepretor = "#//#") {


		string sDateLine = "";

		sDateLine = clsDate::GetSystemDateTimeString() + Sepretor;
		sDateLine += AccountNumber + Sepretor;
		sDateLine += DestintionClient.AccountNumber + Sepretor;
		sDateLine += to_string(Amount) + Sepretor;
		sDateLine += to_string(AccountBalance) + Sepretor;
		sDateLine += to_string(DestintionClient.AccountBalance
		) + Sepretor;
		sDateLine += UserName + Sepretor;


		return sDateLine;

	}

	void _RegisterTransfer(double Amount, clsBankClient& DestinationClient, string UserName) {

		string DateLine = _PreparTransferToRecord(Amount, DestinationClient, UserName);
		fstream MyFile;

		MyFile.open("TransferLog.txt", ios::out | ios::app);

		if (MyFile.is_open()) {

			MyFile << DateLine << endl;

			MyFile.close();
		}
	}*/

	static clsClient _ConverLineToOpjectClient(string Line, string Sepretor = "#//#") {

		vector<string> vClient = clsString::Split(Line, Sepretor);

		return clsClient(_enMode::UpdateMode, vClient[0], vClient[1], vClient[2], vClient[3], vClient[4], stod(vClient[5]));
	}

	static clsClient _GetEmptyOpjectClient() {
		return clsClient(_enMode::EmptyMode, "", "", "", "", "", 0);
	}
	static vector<clsClient> _LoadClientDateFromFile() {

		vector<clsClient> vClient;

		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open()) {

			string Line;
			while (getline(MyFile, Line)) {

				clsClient Client = _ConverLineToOpjectClient(Line);

				vClient.push_back(Client);
			}
			MyFile.close();
		}

		return vClient;


	}
	static string _ConverOpjectClientToLine(clsClient Client, string Sepretor = "#//#") {


		string sDateLine;
		sDateLine = Client.FirstName + Sepretor;
		sDateLine += Client.LastName + Sepretor;
		sDateLine += Client.Email + Sepretor;
		sDateLine += Client.Phone + Sepretor;
		sDateLine += Client.AccountNumber + Sepretor;
		
		sDateLine += to_string(Client.AccountBalance) + Sepretor;
	
		return sDateLine;

	}
	static void _SaveClientDateToFile(vector<clsClient> vClient) {




		fstream MyFile;
		MyFile.open("Clients.txt", ios::out);

		if (MyFile.is_open()) {

			string Line;

			for (clsClient C : vClient) {
				if (C._MarkedForDelete == false) {
					Line = _ConverOpjectClientToLine(C);
					MyFile << Line << endl;
				}
			}



			MyFile.close();
		}
	}
	void _Update() {
		vector <clsClient> vClient = _LoadClientDateFromFile();

		for (clsClient& C : vClient) {

			if (C.GetAccountNumber() == GetAccountNumber()) {

				C = *this;
				break;
			}

		}
		_SaveClientDateToFile(vClient);

	}
	void _AddNew() {

		_AddDateLineToFile(_ConverOpjectClientToLine(*this));
	}

	static void _AddDateLineToFile(string DateLine)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out | ios::app);

		if (MyFile.is_open()) {

			MyFile << DateLine << endl;

			MyFile.close();
		}


	}

public:

	clsClient(_enMode Mode, string FirstName, string LastName, string Email, string Phone, string AccountNumber, double AccountBalance) :

		clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_AccountBalance = AccountBalance;
		 
	};

	bool IsEmpty() {
		return (_Mode == _enMode::EmptyMode);
	}

	void SetMarkedForDelete(bool MarkedForDelete) {
		_MarkedForDelete = MarkedForDelete;
	}
	bool GetMarkedForDelete() {
		return _MarkedForDelete;
	}
	void SetAccountNumber(string AccountNumber)
	{
		_AccountNumber = AccountNumber;
	}

	string GetAccountNumber()
	{
		return _AccountNumber;
	}
	__declspec(property(get = GetAccountNumber, put = SetAccountNumber)) string  AccountNumber;

	void SetAccountBalance(double AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}

	double GetAccountBalance()
	{
		return _AccountBalance;
	}
	__declspec(property(get = GetAccountBalance, put = SetAccountBalance)) double  AccountBalance;
	
	/*void Print() {

		cout << "\n--------------------------------------------\n";
		cout << "First Name   :    " << FirstName << endl;
		cout << "Last Name    :    " << LastName << endl;
		cout << "Email        :    " << Email << endl;
		cout << "Phone        :    " << Phone << endl;
		cout << "Acc. Number  :    " << AccountNumber << endl;
		cout << "Password     :    " << PinCode << endl;
		cout << "Balance      :    " << AccountBalance << endl;
	}*/


	static clsClient Find(string AccountNumber) {

		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open()) {

			string Line;
			while (getline(MyFile, Line)) {

				clsClient Client = _ConverLineToOpjectClient(Line);
				if (Client.AccountNumber == AccountNumber) {
					MyFile.close();
					return Client;
				}
			}



		}


		return _GetEmptyOpjectClient();
	}
	
	static clsClient FindByPhone(string PhoneNumber) {

		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open()) {

			string Line;
			while (getline(MyFile, Line)) {

				clsClient Client = _ConverLineToOpjectClient(Line);
				if (Client.GetPhone() == PhoneNumber) {
					MyFile.close();
					return Client;
				}
			}



		}


		return _GetEmptyOpjectClient();
	}
	/*static clsClient Find(string AccountNumber, string PinCode) {

		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open()) {

			string Line;
			while (getline(MyFile, Line)) {

				clsClient Client = _ConverLineToOpjectClient(Line);
				if (Client.AccountNumber == AccountNumber && Client.PinCode == PinCode) {
					MyFile.close();
					return Client;
				}
			}



		}


		return _GetEmptyOpjectClient();
	}*/


	bool Delete() {


		vector<clsClient>vClient;
		vClient = _LoadClientDateFromFile();

		for (clsClient& C : vClient) {

			if (C.GetAccountNumber() == _AccountNumber) {

				C._MarkedForDelete = true;
				break;

			}


		}
		_SaveClientDateToFile(vClient);

		*this = _GetEmptyOpjectClient();
		return true;
	}



	enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFailAccountNumberExists = 2 };


	enSaveResults Save()
	{

		switch (_Mode)
		{
		case _enMode::EmptyMode:
		{

			return enSaveResults::svFaildEmptyObject;
		}

		case _enMode::UpdateMode:
		{


			_Update();

			return enSaveResults::svSucceeded;

			break;


		}

		case _enMode::AddClient:
		{
			if (IsClientExist(_AccountNumber)) {

				return enSaveResults::svFailAccountNumberExists;
			}
			else {

				_AddNew();
				_Mode = UpdateMode;
				return enSaveResults::svSucceeded;
			}
			break;

		}
		}




	}
	static clsClient GetAddNewClient(string AccountNumber) {


		return clsClient(_enMode::AddClient, "", "", "", "", AccountNumber, 0);

	}

	static vector<clsClient> GetClientsList() {

		return _LoadClientDateFromFile();
	}

	static double TotalAccountBalance(vector < clsClient> vClient) {

		double TotalBalance = 0;
		for (clsClient C : vClient) {

			TotalBalance += C.AccountBalance;

		}
		return TotalBalance;
	}


	static bool IsClientExist(string AccountNumber) {
		clsClient Client = clsClient::Find(AccountNumber);
		return (!Client.IsEmpty());

	}
	static bool IsClientByPhoneExist(string PhoneNumber) {
		clsClient Client = clsClient::FindByPhone(PhoneNumber);
		
		return (!Client.IsEmpty());

	}
	void AddPoints(double Points) {
		AccountBalance += Points;
		Save();
	}
	void DiscountPoints(double Points) {
		AccountBalance -= Points;
		Save();
	}
	bool Deposit(double Amount, bool caseDeposit = true) {
		if (caseDeposit == false)
		{
			AccountBalance += Amount;
			Save();
			return true;
		}

		if (clsInputValidate::Is50_OR100OToEnd(Amount)) {
			_AccountBalance += Amount;
			Save();
			return true;
		}

		return false;
	}
	bool Withdrow(double Amount, bool caseWithdrow = true) {

		if (Amount > _AccountBalance) {
			return false;
		}

		if (caseWithdrow == false)
		{
			_AccountBalance -= Amount;
			Save();
			return true;
		}

		if (clsInputValidate::Is50_OR100OToEnd(Amount)) {
			_AccountBalance -= Amount;
			Save();
			return true;
		}
		return false;
	}
	/*bool Transfer(float Amount, clsClient& DestinationClient, string UserName) {

		if (Amount > _AccountBalance) {
			return false;
		}
		Withdrow(Amount, false);
		DestinationClient.Deposit(Amount, false);
		_RegisterTransfer(Amount, DestinationClient, UserName);
		return true;
	}*/
	//bool ChangePassword(string PassWord) {

	//	_PinCode = PassWord;
	//	Save();
	//}

	static vector<sTransferLogRegisterData> GetListTransferLogRegister() {

		vector<sTransferLogRegisterData> vTransferLogRegisterData;

		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::in);

		if (MyFile.is_open()) {

			string Line;
			while (getline(MyFile, Line)) {

				sTransferLogRegisterData User = _PreparLogInRecordToOpject(Line);

				vTransferLogRegisterData.push_back(User);
			}
			MyFile.close();
		}

		return vTransferLogRegisterData;
	}

};

