#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include"clsPerson.h";
#include <ctype.h>

class clsAuther : public clsPerson {

private:
    string _AutherName;
    string _IDAuther;
public:

    clsAuther(string Id, string FirstName, string LastName, string Email, string Phone)
        :clsPerson(FirstName, LastName, Email, Phone) {

        _AutherName = FirstName + " " + LastName;
        _IDAuther = Id;

    }

    void setAutherName(string AutherName) {

        _AutherName = AutherName;
    }
    string AutherName()
    {
        return _AutherName;
    }

    //__declspec(property(get = AutherName, put = setAutherName)) string  AutherName;

    //void SetIDAuther(string Id) {

    //    _IDAuther = Id;
    //}
    //string IDAuther()
    //{
    //    return _IDAuther;
    //}
    //__declspec(property(get = IDAuther, put = SetIDAuther)) string  IDAuther;

    void SetIDAuther(string Id)
    {
        _IDAuther = Id;
    }

    string GetIDAuther()
    {
        return _IDAuther;
    }
    __declspec(property(get = GetIDAuther, put = SetIDAuther)) string  IDAuther;

};

