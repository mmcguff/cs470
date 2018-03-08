/***********************************************************************
* Program:
*    Week 09, name
*    Brother Wilson, CS470
* Author:
*    Matthew McGuff
* Summary: 
*    Please include a detailed description of:
*    1. What this program is designed to do
*    2. How this program will go about solving the problem
*    3. What assumptions about input (file or user) is made
*    4. Citations if the algorithm was borrowed or inspired from any source
************************************************************************/
#include <iostream>   // for CIN and COUT
#include <regex>      //Regular expressions
#include <math.h>     //POW
using namespace std;

int main() {
   
  string p;
  int a = 0;
  int pLength;
  
  std::cout << "Please enter the password:";
  cin >> p;
  pLength = p.size();
  
  //regex for numeric
  std::regex rNum("[\\[0-9]");
  if(regex_search(p, rNum))
  {
      a += 10;
  }
  
  //regex for lowercase letters
  std::regex rLower("[\\[a-z]");
  if(regex_search(p, rLower))
  {
      a += 26;
  }
  
  //regex for uppercase letters
  std::regex rUpper("[\\[A-Z]");
  if(regex_search(p, rUpper))
  {
      a += 26;
  }
  
  //regex for special(assuming all non alphanumerics are speical)
  std::regex rSpecial("[^[:alnum:]]");
  if(regex_search(p, rSpecial))
  {
      a += 32;
  }

 //std::cout << "alphabet: " << a << endl;

 int c = pow(a, pLength);
 int b = log2(c);
 
 std::cout << "There are " << c << " combinations" << endl;
 std::cout << "That is equivalent to a key of " << b << " bits" << endl;
 
}