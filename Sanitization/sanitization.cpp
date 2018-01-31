/***********************************************************************
 * Program:
 *    Assignment 04, Lab 04
 *    Brother Wilson, CS470
 * Author:
 *    Joshua Pattullo
 * Summary:
 *      Sanitizes html tags based on a whitelist
 ************************************************************************/

#include <iostream>
#include <string>
#include <stack>
using namespace std;

void sanitize(string &input, int &findLoc) {
   int sim = findLoc - 1;
   input.replace(sim, 1, "&lt;");
   while (input[sim] != '>' || sim >= input.length()) {
      sim++;
   }
   input.replace(sim, 1, "&gt;");
}

bool nested(string temp, stack<string> &nestStack) {
	if (temp[0] == '/') {
		temp.erase(0, 1);
		if (nestStack.top() != temp) {
			return false;
		} else {
			nestStack.pop();
			return true;
		}
	} else {
		nestStack.push(temp);
		return true;
	}
}

string whiteList() {
	int findLoc = 0;
	bool good = false;
	string temp;
	string whiteList[13] = { "a", "abbr", "acronym", "b", "blockquote", "cite",
		"code", "del", "em", "i", "q", "strike", "strong" };
	stack<string> nestStack;
	string input;
	input = "";
	findLoc = 0;
	cout << "> ";
	getline(cin, input);
	while (findLoc != -1) {
		findLoc = input.find('<', findLoc);
		if (findLoc != -1) {
			temp = "";
			for (int i = ++findLoc; input[i] != '>'; i++) {
				if (input[i] == ' ')
					break;
				temp += input[i];
			}
			for (int i = 0; i < 13; i++) {
				if (temp == whiteList[i] || temp == ('/' + whiteList[i])) {
					good = true;
				}
			}
			if (!good) {
				sanitize(input, findLoc);
			} else {
				if (!nested(temp, nestStack)) {
					sanitize(input, findLoc);
				}
				good = false;
			}
		}
	}
	while (!nestStack.empty()) {
		input += ("</" + nestStack.top() + ">");
		nestStack.pop();
	}
	return input;
}


int main() {
	string san;
	while (san != "quit") {
		san = whiteList();
	   cout << "\t" << san << endl;
	}
   return 0;
}
