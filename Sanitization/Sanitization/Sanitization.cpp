// Sanitization.cpp : main project file.

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace System;
using namespace std;

bool isValidTag(string target)
{
	bool ans = false;

	//remove everything after the first space
	std::string tar = target.substr(0, target.find(" ", 0));

	//cout << t; cout << endl;
	
	//check against the white list. 
	string validTags[] =
	{
		"a"
		,"abbr"
		,"acronym"
		,"b"
		,"blockquote"
		,"cite"
		,"code"
		,"del"
		,"em"
		,"i"
		,"q"
		,"strike"
		,"strong"
	};

	for (const string &text : validTags)
	{
		if (text == tar)
		{
			ans = true;
			cout << "you are valid!\n";
		}
	}
	


	return ans;
}


bool isValid(string targetString)
{
	string tag;
	bool isTag = false;
	//We should have the logic here to deteremine if the HTML tag is valid.  
	for (std::string::size_type i = 0; i < targetString.size(); ++i) {
		if (targetString[i] == '<')
		{
			cout << "< is a opening tag\n";
			isTag = true;
			continue;
		}
		if (targetString[i] == '>')
		{
			cout << "> is a closing tag\n";
			isTag = false;
			continue;

		}
		if (isTag == true)
		{
			tag += targetString[i];
			cout << tag; cout << endl;
		}


		//cout << targetString[i]; cout << endl;
	}

	isTag = isValidTag(tag);

	return isTag;
}






int main()
{
	string input;
	bool ans;
	cout << "Please enter HTML to validate\n";
	
	cin >> input;
	getchar();
	
	ans = isValid(input);
	
	if (ans == true)
	{
		cout << "You input is valid\n";
	}
	else if (ans == false)
	{
		cout << "Your input is invalid\n";
	}
		
	return 0;
}

