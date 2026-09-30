#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include"clsAuther.h";
#include <ctype.h>
#include"clsString.h";
#include <string>

using namespace std;

class clsitems 
{
private:
	string _NameItem_OR_Description;
	string _TypeItem;
	string _ItemCode;
	double _Price;
	short    _Quantity;
	double  _Tax;

public:
	clsitems( string NameItem_OR_Description, string TypeItem, string ItemCode, double Price, short Quantity, double Tax)
	
	{

		_NameItem_OR_Description = NameItem_OR_Description;
		_TypeItem = TypeItem;
		_ItemCode = ItemCode;
		_Price = Price;
		_Quantity = Quantity;
		_Tax = Tax;
	}

	void SetNameItem(string NameItem) {

		_NameItem_OR_Description = NameItem;
	}
	string GetNameItem()
	{
		return _NameItem_OR_Description;
	}
	__declspec(property(get = GetNameItem, put = SetNameItem)) string  NameItem;


	void SetTypeItem(string TypeItem) {

		_TypeItem = TypeItem;
	}
	string GetTypeItem()
	{
		return _TypeItem;
	}
	__declspec(property(get = GetTypeItem, put = SetTypeItem)) string  TypeItem;
	void SetItemCode(string ItemCode) {

		_ItemCode = ItemCode;
	}
	string GetItemCode()
	{
		return _ItemCode;
	}
	__declspec(property(get = GetItemCode, put = SetItemCode)) string  ItemCode;
	void SetPrice(double Price) {

		_Price = Price;
	}
	double GetPrice()
	{
		return _Price;
	}
	__declspec(property(get = GetPrice, put = SetPrice)) double  Price;
		void SetQuantity(short Quantity) {

		_Quantity = Quantity;
	}
	short GetQuantity()
	{
		return _Quantity;
	}
	__declspec(property(get = GetQuantity, put = SetQuantity)) short  Quantity;
	void SetTax(double Tax) {

		_Tax = Tax;
	}
	double GetTax()
	{
		return _Tax;
	}
	__declspec(property(get = GetTax, put = SetTax)) double  Tax;

};

