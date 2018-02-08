/***********************************************************************
* Program:
*    Lab 05, The stack
*    Brother Helfrich, CS470
* Author:
*    your name
* Summary: 
*    This program is designed to illustrate weaknesses in the stack.
*
************************************************************************/

#include <stdlib.h>    // for malloc()
#include <iostream>
#include <iomanip>
#include <cassert>
#include <string>
using namespace std;

int* q = new int(13);

void partOne(int); // Find the address of the stack, heap, and code segments
void partTwo(char *, long);    // Manipulate the stack to find a weakness
void partThree();  // Demonstrate a variety of vulnerabilities

/******************************************************
 * MAIN
 * This function will only take you to one of the three parts
 * of Assignment 05
 *****************************************************/
int main()
{
   char text[] = "%%main%%";
   long number = 1234567;
   &number;
   
   // prompt
   cout << "Please select an option:\n";
   cout << "  1.  Find the address\n";
   cout << "  2.  Display the contents of the stack\n";
   cout << "  3.  Manipulate the stack\n";
   cout << "> ";

   int selection;
   cin >> selection;

   switch (selection)
   {
      case 1:
         partOne(1);
         break;
      case 2:
         partTwo(text, number + 1111111);
         break;
      case 3:
         partThree();
         break;
      default:
         cout << "Unknown option\n";
         return 1;
   }

   return 0;
}

/**************************************************************
 **************************************************************
 **************************** PART 1 **************************
 **************************************************************
 **************************************************************/


/**********************************************
 * Part 1
 *
 * Find the address of the stack, heap, and code.
 * Note that it will be in a different location with
 * every execution
 **********************************************/
void partOne(int byValueParameter)
{
   void *pStack = NULL;
   void *pHeap  = NULL;
   void *pCode  = NULL;

   ////////////////////////////////////////////////
   // put your magic code between here...

   int s;
   int *h = new int;
   pStack = &s;
   pHeap = h;
   pCode = &q;

   // ... and here
   ////////////////////////////////////////////////

   // display the results
   cout << "Stack: " << pStack << endl;
   cout << "Heap:  " << pHeap  << endl;
   cout << "Code:  " << pCode  << endl;

   return;
}

/**************************************************************
 **************************************************************
 **************************** PART 2 **************************
 **************************************************************
 **************************************************************/

/************************************************
 * CONVERT TO STRING
 * Convert the data from p into a human-readable string
 * by removing all the unprintable characters and replacing
 * them with a dot
 ***********************************************/
string displayCharArray(const char * p)
{
   string output;
   for (int i = 0; i < 8; i++)
      output += string(" ") + (p[i] >= ' ' && p[i] <= 'z' ? p[i] : '.');
   return output;
}

/*************************************************
 * PART 2
 *
 * Display the contents of the stack. This will be from
 * slot -4 to slot 20.
 *************************************************/
void partTwo(char *text, long number)
{
   // start your display of the stack from this point
   long bow = number + 1111111;
   // header for our table. Use these setw() offsets in your table
   cout << "[" << setw(2) << 'i' << ']'
        << setw(15) << "address"
        << setw(20) << "hexadecimal"
        << setw(20) << "decimal"
        << setw(18) << "characters"
        << endl;
   cout << "----+"
        << "---------------+"
        << "-------------------+"
        << "-------------------+"
        << "-----------------+\n";
   for (int i = -4; i <= 20; i++)
   {
      
      ////////////////////////////////////////////////
      // put your magic code between here...

	   cout << "[" << setw(2) << i << ']'
		   << setw(15) << &bow + i
                << setw(20) << hex << (long)*(&bow + i)
                << setw(20) << dec << (long)*(&bow + i)
                << setw(6);
	   for (int j = 0; j < 8; j++) {
		   if ((int)(*(((char*)(&bow + i)) + j)) >= 33) {
                      cout <<  *(((char*)(&bow + i)) + j) << ' ';
		   } else {
                      cout << ". ";
		   }
	   } 
           cout << endl;

      // ... and here
      ////////////////////////////////////////////////
   }
}

/**************************************************************
 **************************************************************
 **************************** PART 3 **************************
 **************************************************************
 **************************************************************/

void fail(char grade);
void pass(char grade);

/**********************************************************************
 * All your code needs to exist in this function below the comment
 *********************************************************************/
void readStack()
{
   int   number;
   char  text[16];
   
   ////////////////////////////////////////////////
   // put your magic code between here...
   short p = 5;
   void (*f)() = &partThree;
   cout << "fun head " << &f << "\n\n";
   void (*pointerFunction)(char) = (void (*)(char))(&p + 53);
   cout << &pointerFunction;
   //*pointerFunction = pass;
   for (int i = 0; i < 16; i++) {
      text[i] = *(((char*)(&p + 57)) + i);
   }
   number = (int)*(&p + 69);
   *(((char*)(&p + 72)) + 1) = 'A';

   for (int i = 0; i <= 150; i++)
   {
      cout << '[' << setw(5) << i << ']'
           << setw (15) << (&p + i) << '\t';
      for (int j = 0; j < 2; j++) {
         if ((int)(*(((char*)(&p + i)) + j)) >= 33) {
            cout <<  *(((char*)(&p + i)) + j) << ' ';
         } else {
            cout << ". ";
         }
      }
      cout << endl;
   }
   // ... and here
   ////////////////////////////////////////////////

   // output the goods
   cout << "\tnumber: "
        << number
        << endl;
   cout << "\ttext:   "
        << text
        << endl;

   return;
}

/*******************************************************************
 * Part 3
 *
 * This function contains the data that you are trying to manipulate.
 * Please don't modify partTwo() in any way
 ********************************************************************/
void partThree()
{
   int   number;   // first local variable that you need to read
   char  text[16]; // second

   char  letterGrade;
   void (*pointerFunction)(char);

   // get the values
   cout << "number: ";
   cin  >> number;
   cout << "text:   ";
   cin  >> text;
   
   // Call the function and display the results.
   pointerFunction = fail;
   letterGrade = 'B';
   cout << "\nNumber " << &number << endl << endl
      //<< "text" << &(*text[0]) << "\n\n"
      //<< "grade" << &letterGrade << "\n\n"
   << "funct " << &pointerFunction << "\n\n";
   readStack();            // vulnerability is here 
   (*pointerFunction)(letterGrade);

   return;
}


/**********************************************************************
 * The failure case. Don't touch this function
 *********************************************************************/
void fail(char grade)
{
   cout << "\tI am sorry, but you got a 'F'\n";
}

/**********************************************************************
 * I think you would really rather call this function.  This
 * is read-only also
 *********************************************************************/
void pass(char grade)
{
   cout << "\tGood job, you got a(n) '" << grade << "'\n";
}


