// Sanitization.cpp : main project file.

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace System;
using namespace std;

int main()
{
	string input;

	cout << "Please enter HTML to validate"; cout << endl;
	
	cin >> input;
	getchar();
	cout << "You typed : " + input;
	
	getchar();
	
	return 0;
}