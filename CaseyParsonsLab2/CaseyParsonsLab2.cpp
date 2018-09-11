// CaseyParsonsLab2.cpp 
// Name: Casey Parsons
// Class: CSCI 2021-01 Machine Architecture and Organization
// Date: 9-6-18
// Lab: Lab Experience Two
// Objectives: 1. Practice array manipulation in C++ 2: Using Functions in C++
// Assumptions: After talking with Professor Wrenn my assumptions for this program are as such:
// The user of this program would be competent and would be either entering valid unsigned integers
// or there was an upstream mechanism that would be checking for that already. With that assumption
// I have hard-coded the values I want to test as constants. I tested with multiple values for each 
// To check for that the program was working correctly. At this time it seems to be working correctly
// At both ends of the allowable values for an unsigned long int


#include <iostream>
#include <string>
using namespace std;

//Function Prototypes
string convertToBinary(unsigned long int);
void displayBinary(string);
void displayOctal(string);
void displayHexadecimal();
void displayBase10();
void binaryAddition();

int main()
{
	const unsigned long int num1 = 4294967295;
	const unsigned long int num2 = 345;
	
	cout << "Your first number is " << num1 << "." << endl;
	displayBinary(convertToBinary(num1));
	displayOctal(convertToBinary(num1));
	cin.get();
	
	
	return 0;
}

//Purpose:Convert a 32 bit unsigned integer into its binary representation
//Preexisting conditions: A valid 32bit unsigned integer is required
//Return Values: A string array that represents the binary value of the 32bit unsigned integer
string convertToBinary(unsigned long int num1)
{
	
	string binaryRepresentation = "";

	int bit;
	int quotient;

	while (num1 > 0)
	{
		bit = num1 % 2;
		quotient = num1 / 2;

		binaryRepresentation = to_string(bit) + binaryRepresentation;
		num1 = quotient;
	}

	//adds padding to the left of the number to make working with it in other forms more reliable
	int padding = 32 - binaryRepresentation.length();
	binaryRepresentation.insert(0, padding, '0');
	
	return binaryRepresentation;
}

//Purpose: Display the binary value of the 32bit unsigned integer
//Preexisting conditions: The 32bit unsigned integer has been converted to a string array
//Return Values:Does not return anything only displays the value to the screen
void displayBinary(string binaryValue )
{
	
	cout << "It has a binary value of "<< binaryValue << "." << endl;
}


//Purpose:Displays the octal value of the 32bit unsigned integer
//Preexisting conditions: The 32bit unsigned integer has been converted to a string array
//Return Values:Does not return anything only displays the value to the screen
void displayOctal(string binaryValue)
{
	//way to convert it from a string into its int value again if I want to go that route
	//int binaryThing = stoi(binaryValue);
	
	
	//string string1 = binaryValue;
	string string2 = binaryValue.substr((binaryValue.size() - 3), 3);
	
	string octalString = "";

	//debated between using a switch statement in the for loop or using the if else
	//settled on the if else due to having to convert the character values into their integer representations
	//via the built in stoi() function and also having to use more cases for the four cases that I end up with
	//when evaluating the final 2 characters that are left over when working with a 32 bit value and breaking it
	//into octal


	for (int i = 0; i < 11; i++)
	{
		if (string2 == "000" || string2 == "00")
			octalString = "0" + octalString;
		else if (string2 == "001" || string2 == "01")
			octalString = "1" + octalString;
		else if (string2 == "010" || string2 == "10")
			octalString = "2" + octalString;
		else if (string2 == "011" || string2 == "11")
			octalString = "3" + octalString;
		else if (string2 == "100")
			octalString = "4" + octalString;
		else if (string2 == "101")
			octalString = "5" + octalString;
		else if (string2 == "110")
			octalString = "6" + octalString;
		else if (string2 == "111")
			octalString = "7" + octalString;

	
		
		binaryValue = binaryValue.substr(0, (binaryValue.size() - 3));
			
		if (binaryValue.size() == 2)
		{
			string2 = binaryValue;
		}
		else
		{
			string2 = binaryValue.substr((binaryValue.size() - 3), binaryValue.size());
			cout << octalString << endl;
		}
		
		
	}
	cout << octalString << endl;

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
