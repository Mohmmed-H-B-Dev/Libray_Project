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

class clsUser : public  clsPerson
{
public:
	struct stLoginRegisterData {
		string _UserName;
		string _Password;
		string _Permissions;
		string _DateTime;
	};

private:

	enum _enMode { EmptyMode = 0, UpdateMode = 1, AddClient = 3 };

	_enMode _Mode;
	string _UserName;
	string _Password;
	int _Permissions;
	string _CurrentPosition;
	bool _MarkedForDelete = false;




	string _PreparLogInToRecord(string Sepretor = "#//#") {


		string sDateLine = "";

		sDateLine = clsDate::GetSystemDateTimeString() + Sepretor;
		sDateLine += UserName + Sepretor;
		sDateLine += clsUtil::EncryptText(Password) + Sepretor;
		sDateLine += to_string(Permissions) + Sepretor;


		return sDateLine;

	}
	static stLoginRegisterData _PreparLogInRecordToOpject(string Line, string Sepretor = "#//#") {
		vector<string > vUser = clsString::Split(Line, Sepretor);
		stLoginRegisterData LogRegDate;
		LogRegDate._DateTime = vUser[0];
		LogRegDate._UserName = vUser[1];
		LogRegDate._Password = clsUtil::DecryptText(vUser[2]);
		LogRegDate._Permissions = vUser[3];
		return LogRegDate;


	}
	static clsUser _ConverLineToOpjectUser(string Line, string Sepretor = "#//#") {

		vector<string > vUser = clsString::Split(Line, Sepretor);

		return clsUser(_enMode::UpdateMode, vUser[0], vUser[1], vUser[2], vUser[3], vUser[4], clsUtil::DecryptText(vUser[5]), stoi(vUser[6]) , vUser[7]);
	}

	static clsUser _GetEmptyOpjectUser() {
		return clsUser(_enMode::EmptyMode, "", "", "", "", "", "", 0,"");
	}
	static vector<clsUser> _LoadUserDateFromFile() {

		vector<clsUser> vUser;

		fstream MyFile;
		MyFile.open("Users.txt", ios::in);

		if (MyFile.is_open()) {

			string Line;
			while (getline(MyFile, Line)) {

				clsUser User = _ConverLineToOpjectUser(Line);

				vUser.push_back(User);
			}
			MyFile.close();
		}

		return vUser;


	}
	static string _ConverOpjectUserToLine(clsUser User, string Sepretor = "#//#") {


		string sDateLine;
		sDateLine = User.FirstName + Sepretor;
		sDateLine += User.LastName + Sepretor;
		sDateLine += User.Email + Sepretor;
		sDateLine += User.Phone + Sepretor;
		sDateLine += User.UserName + Sepretor;
		sDateLine += clsUtil::EncryptText(User.Password) + Sepretor;
		sDateLine += to_string(User.Permissions) + Sepretor;
		sDateLine += User.CurrentPosition + Sepretor;
		
		return sDateLine;

	}
	static void _SaveUserDateToFile(vector<clsUser>  vUser) {




		fstream MyFile;
		MyFile.open("Users.txt", ios::out);

		if (MyFile.is_open()) {

			string Line;

			for (clsUser U : vUser) {
				if (U._MarkedForDelete == false) {
					Line = _ConverOpjectUserToLine(U);
					MyFile << Line << endl;
				}
			}



			MyFile.close();
		}
	}
	void _Update() {
		vector <clsUser> vUser = _LoadUserDateFromFile();

		for (clsUser& U : vUser) {

			if (U.GetUserName() == GetUserName()) {

				U = *this;
				break;
			}

		}
		_SaveUserDateToFile(vUser);

	}
	void _AddNew() {

		_AddDateLineToFile(_ConverOpjectUserToLine(*this));
	}
	static void _AddDateLineToFile(string DateLine)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::out | ios::app);

		if (MyFile.is_open()) {

			MyFile << DateLine << endl ;

			MyFile.close();
		}


	}


public:
	enum enPermissions {
		eAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4,
		pUpdateClients = 8, pFindClient = 16, pTranactions = 32, pManageUsers = 64
		, pListLoginRegister = 128
	};



	clsUser(_enMode Mode, string FirstName, string LastName, string Email, string Phone, string UserName, string Password, int Permissions,string CurrentPosition) :

		clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_UserName = UserName;
		_Password = Password;
		_Permissions = Permissions;
		_CurrentPosition = CurrentPosition;
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
	void SetUserName(string UserName)
	{
		_UserName = UserName;
	}

	string GetUserName()
	{
		return _UserName;
	}
	__declspec(property(get = GetUserName, put = SetUserName)) string  UserName;

	void SetCurrentPosition(string CP)
	{
		_CurrentPosition = CP;
	}

	string GetCurrentPosition()
	{
		return _CurrentPosition;
	}
	__declspec(property(get = GetCurrentPosition, put = SetCurrentPosition)) string  CurrentPosition;

	void SetPermissions(int Permissions)
	{
		_Permissions = Permissions;
	}

	int GetPermissions()
	{
		return _Permissions;
	}

	__declspec(property(get = GetPermissions, put = SetPermissions)) int  Permissions;

	void SetPassword(string Password)
	{
		_Password = Password;
	}

	string GetPassword()
	{
		return _Password;
	}
	__declspec(property(get = GetPassword, put = SetPassword)) string  Password;

	//lokijuhy


	static clsUser Find(string UserName) {

		fstream MyFile;
		MyFile.open("Users.txt", ios::in);

		if (MyFile.is_open()) {

			string Line;
			while (getline(MyFile, Line)) {

				clsUser User = _ConverLineToOpjectUser(Line);
				if (User.UserName == UserName) {
					MyFile.close();
					return User;
				}
			}



		}


		return _GetEmptyOpjectUser();
	}

	static clsUser Find(string UserName, string Password) {

		fstream MyFile;
		MyFile.open("Users.txt", ios::in);

		if (MyFile.is_open()) {

			string Line;
			while (getline(MyFile, Line)) {

				clsUser User = _ConverLineToOpjectUser(Line);
				if (User.UserName == UserName && User.Password == Password) {
					MyFile.close();
					return User;
				}
			}



		}


		return _GetEmptyOpjectUser();
	}


	bool Delete() {


		vector<clsUser>vUsers;
		vUsers = _LoadUserDateFromFile();

		for (clsUser& U : vUsers) {

			if (U.GetUserName() == _UserName) {

				U._MarkedForDelete = true;
				break;

			}


		}
		_SaveUserDateToFile(vUsers);

		*this = _GetEmptyOpjectUser();
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
			if (IsUserExist(_UserName)) {

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


		//«·„‘ﬂ·Â «‰Â ⁄‰œ ’»«⁄œ ›« Ê—Â «·‘—«¡  Ì „ Õ–› Ã„Ì⁄ «·«’‰«› „‰ ﬁ«⁄œ… «·Ì«‰« 

	}

	static clsUser GetAddNewUser(string UserName) {
		
		
		return clsUser(_enMode::AddClient, "", "", "", "", UserName, "", 0,"");

	}

	static vector<clsUser> GetUsersList() {

		return _LoadUserDateFromFile();
	}
	static bool IsUserExist(string UserName) {
		clsUser User = clsUser::Find(UserName);
		
		return (!User.IsEmpty() && User.CurrentPosition == "A");

	}
	static vector<stLoginRegisterData> GetListLoginRegister() {

		vector<stLoginRegisterData> vLoginRegisterData;

		fstream MyFile;
		MyFile.open("LoginRegister.txt", ios::in);

		if (MyFile.is_open()) {

			string Line;
			while (getline(MyFile, Line)) {

				stLoginRegisterData User = _PreparLogInRecordToOpject(Line);

				vLoginRegisterData.push_back(User);
			}
			MyFile.close();
		}

		return vLoginRegisterData;
	}
	bool ChechAccesspermissions(enPermissions Permission) {

		if (this->Permissions == enPermissions::eAll) {
			return true;
		}
		if ((Permission & this->Permissions) == Permission)
			return true;
		else
			return false;

	}
	void RegisterLogIn() {

		string DateLine = _PreparLogInToRecord();
		fstream MyFile;

		MyFile.open("LoginRegister.txt", ios::out | ios::app);

		if (MyFile.is_open()) {

			MyFile << DateLine << endl;

			MyFile.close();
		}
	}
};
