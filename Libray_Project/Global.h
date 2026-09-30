#pragma once

#include"clsUser.h"
#include<vector>
#include"clsSale.h"
#include "clsClient.h"
#include "clsDblLinkedList.h"

clsUser CurrentUser = clsUser::Find("", "");

clsClient  CurrentClient = clsClient::GetEmptyOpjectClient();

bool AcceptShowClient = false; 

enum _enUseres { eManager = 'M', eAuthers = 'A', eSalesMan = 'S' };

double GTax = 0;

clsDblLinkedList<int> DLLStoragePayMetheds;

vector<clsSale> vCart;

bool ForCalculetorAPrice = true;

vector<clsSale> vItemsBuyed;

double TotalPrice = 0.0;
double _TempTotalePrice = 0;
string PaymentMethod; double amount=0; int NumberOfInvoice = 0;


double ItemsList = 0.0; double  PriceExTax = 0.0, Tax = 0.0, TotalPriceExTax = 0.0;