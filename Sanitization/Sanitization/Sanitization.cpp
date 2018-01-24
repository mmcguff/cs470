// Sanitization.cpp : main project file.

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace System;
using namespace std;

bool isValid(string targetString)
{
	//We should have the logic here to deteremine if the HTML tag is valid.  
	return true;
}



int main()
{
	string input;
	bool ans;
	cout << "Please enter HTML to validate"; cout << endl;
	
	cin >> input;
	getchar();
	
	ans = isValid(input);
	
	cout << "You input is " + to_string(ans);
	


	getchar();
	
	return 0;
}

