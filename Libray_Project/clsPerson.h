#pragma once
#include <iostream>
using namespace std;

class clsPerson
{
private:
	string _FirstName;
	string _LastName;
	string _Email;
	string _Phone;
public:

	clsPerson(string FirstName, string LastName, string Email, string Phone)
	{
		_FirstName = FirstName;
		_LastName = LastName;
		_Email = Email;
		_Phone = Phone;
	}
	void SetFirstName(string FirstName)
	{
		_FirstName = FirstName;
	}

	string GetFirstName()
	{
		return _FirstName;
	}
	__declspec(property(get = GetFirstName, put = SetFirstName)) string  FirstName;


	void SetLastName(string LastName)
	{
		_LastName = LastName;
	}

	string GetLastName()
	{
		return _LastName;
	}
	__declspec(property(get = GetLastName, put = SetLastName)) string  LastName;

	void SetEmail(string Email)
	{
		_Email = Email;
	}

	string GetEmail()
	{
		return _Email;
	}
	__declspec(property(get = GetEmail, put = SetEmail)) string  Email;

	void SetPhone(string Phone)
	{
		_Phone = Phone;
	}

	string GetPhone()
	{
		return _Phone;
	}
	_declspec(property(get = GetPhone, put = SetPhone)) string  Phone;

	void SetFullName(string FullName) {
		 FullName=_FirstName + " " + _LastName;
	}
	string GetFullName() {
		return _FirstName + " " + _LastName;
	}

	__declspec(property(get = GetFullName, put = SetFullName)) string  FullName;




    void SendEmail(string Subject, string Body) {

        cout << "\n\n The following Message sent Successfully To Email : " << _Email;
        cout << "\nSubject : " << Subject;
        cout << "\nBody : " << Body << "\n";
    }

    void SendSMS(string Body) {

        cout << "\n\n The following SMS sent Successfully To Phone : " << _Phone;
        cout << "\nBody : " << Body << "\n";
    }
};