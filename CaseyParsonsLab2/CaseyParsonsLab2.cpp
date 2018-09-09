// CaseyParsonsLab2.cpp 
// Name: Casey Parsons
// Class: CSCI 2021-01 Machine Architecture and Organization
// Date: 9-6-18
// Lab: Lab Experience Two
// Objectives: 1. Practice array manipulation in C++ 2: Using Functions in C++


#include <iostream>
//#include "pch.h"
using namespace std;

//Function Prototypes
void convertToBinary(unsigned long int);
void displayBinary();
void displayOctal();
void displayHexadecimal();
void displayBase10();
void binaryAddition();

int main()
{
	const unsigned long int num1 = 78;
	const unsigned long int num2 = 345;
	
	convertToBinary(num1);

}

//Purpose:Convert a 32 bit unsigned integer into its binary representation
//Preexisting conditions: A valid 32bit unsigned integer is required
//Return Values: A string array that represents the binary value of the 32bit unsigned integer
void convertToBinary(unsigned long int num1)
{
	int convertedNumberInBinary[32];

	for (int i = 0; i < 32; i++)
	{
		convertedNumberInBinary[i] = 0;
	}



	for (int i = 0; i < 32; i++)
	{
		cout << convertedNumberInBinary[i];
	}

}

//Purpose: Display the binary value of the 32bit unsigned integer
//Preexisting conditions: The 32bit unsigned integer has been converted to a string array
//Return Values:Does not return anything only displays the value to the screen
void displayBinary()
{
	int test = 3;
	cout << "The binary value  is ";
}


//Purpose:Displays the octal value of the 32bit unsigned integer
//Preexisting conditions: The 32bit unsigned integer has been converted to a string array
//Return Values:Does not return anything only displays the value to the screen
void displayOctal()
{
	cout << "The octal value is ";

}

//Purpose:Displays the Hexadecimal value of the 32bit unsigned integer
//Preexisting conditions:The 32bit unsigned integer has been converted to a string array
//Return Values:Does not return anything only displays the value to the screen
void displayHexadecimal()
{
	cout << "The Hexadecimal value is ";

}

//Purpose:Displays the base 10 value of the 32bit unsigned integer
//Preexisting conditions:The 32bit unsigned integer has been converted to a string array
//Return Values:Does not return anything only displays the value to the screen
void displayBase10()
{
	cout << "The base 10 value is ";

}



//Purpose: Add two 32bit unsigned integers and display their values and result in binary and as unsigned integers
//Preexisting conditions:Two valid 32bit unsigned integers are required
//Return Values:Does not return anything, only displays the values to the screen
void binaryAddition()
{


}
