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

// Note - I am pretty rusty with c++ as it has been over a years since I used it last. Please be kind
// and rewind.


#include <iostream>
#include <string>
using namespace std;

//Function Prototypes 
//Did not find any need to pass by reference in this code so I left everything pass by value
string convertToBinary(unsigned long int);
void displayBinary(string);
void displayOctal(string);
void displayHexadecimal(string);
void displayBase10(string);
void binaryAddition(string , string);

int main()
{
	//const unsigned long int num1 = 4294967295;
	//const unsigned long int num1 = 1;
	const unsigned long int num1 = 7989;
	const unsigned long int num2 = 7;
	
	cout << "Your first number is " << num1 << "." << endl;
	cout << "Your second number is " << num2 << "." << endl;
	cout << endl;

	string binaryString1 = convertToBinary(num1);
	string binaryString2 = convertToBinary(num2);

	cout << "Part B " << endl;
	displayBinary(binaryString1);
	displayOctal(binaryString1);
	displayHexadecimal(binaryString1);
	displayBase10(binaryString1);
	cout << endl;

	cout << "Part C " << endl;
	binaryAddition(binaryString1, binaryString2);
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
//Preexisting conditions: The 32bit unsigned integer has been converted to a string array representing
//the binary value of the integer
//Assumption: I approached the displayOctal, displayHex, and displayBase10 functions along the lines of the
//listed objective for the lab: practice array manipulation. There were a number of ways that I found that 
//could have been used to convert from the binary version of the number to the other bases via mathematical
//formulas but I didn't see that as in line with the lab objectives.
//Return Values:Does not return anything only displays the value to the screen
void displayOctal(string binaryValue)
{
	//way to convert it from a string into its int value again if I want to go that route in the future
	//int binaryThing = stoi(binaryValue);
	
	string subBinaryString = binaryValue.substr((binaryValue.size() - 3), 3);
	string octalString = "";

	//debated between using a switch statement in the for loop or using the if else
	//settled on the if else due to having to convert the character values into their integer representations
	//via the built in stoi() function and also having to use more cases for the four cases that I end up with
	//when evaluating the final 2 characters that are left over when working with a 32 bit value and breaking it
	//into octal
	for (int i = 0; i < 11; i++)
	{
		//sets the subBinaryString to either the last three bits or the remaining two bits left 
		if (binaryValue.size() > 2)
		{
			subBinaryString = binaryValue.substr((binaryValue.size() - 3), binaryValue.size());
			//cuts the binaryValue down by the values that we just checked and set
			binaryValue = binaryValue.substr(0, (binaryValue.size() - 3));
		}
		else
		{
			subBinaryString = binaryValue;
		}

		
		if (subBinaryString == "000" || subBinaryString == "00")
			octalString = "0" + octalString;
		else if (subBinaryString == "001" || subBinaryString == "01")
			octalString = "1" + octalString;
		else if (subBinaryString == "010" || subBinaryString == "10")
			octalString = "2" + octalString;
		else if (subBinaryString == "011" || subBinaryString == "11")
			octalString = "3" + octalString;
		else if (subBinaryString == "100")
			octalString = "4" + octalString;
		else if (subBinaryString == "101")
			octalString = "5" + octalString;
		else if (subBinaryString == "110")
			octalString = "6" + octalString;
		else if (subBinaryString == "111")  //this doesn't need to be an else if but makes it easer to understand
			octalString = "7" + octalString;

			
	}
	cout << "The octal value of the first number is " << octalString << "." << endl;

}

//Purpose:Displays the Hexadecimal value of the 32bit unsigned integer
//Preexisting conditions:The 32bit unsigned integer has been converted to a string array
//Return Values:Does not return anything only displays the value to the screen
void displayHexadecimal(string binaryValue)
{
	string subHexadecimalString = "";// = binaryValue.substr((binaryValue.size() - 4), 4);
	string hexString = "";

	//debated between using a switch statement in the for loop or using the if else
	//settled on the if else due to having to convert the character values into their integer representations
	//via the built in stoi() function and also having to use more cases for the four cases that I end up with
	//when evaluating the final 2 characters that are left over when working with a 32 bit value and breaking it
	//into hex
	for (int i = 0; i < 8; i++)
	{
		//sets the subHexadecimalString to either the last four bits in the binary value or sets it equal
		//to the binary value at the end - substr() doesn't like to work with when I tried to give it the entire
		//string
		if (binaryValue.size() > 4)
		{
			subHexadecimalString = binaryValue.substr((binaryValue.size() - 4), binaryValue.size());

			//cuts the binaryValue down by the values that we just set to the subHexadecimalString
			binaryValue = binaryValue.substr(0, (binaryValue.size() - 4));
		}
		else
		{
			subHexadecimalString = binaryValue;
		}
		
		
		if (subHexadecimalString == "0000")
			hexString = "0" + hexString;
		else if (subHexadecimalString == "0001")
			hexString = "1" + hexString;
		else if (subHexadecimalString == "0010")
			hexString = "2" + hexString;
		else if (subHexadecimalString == "0011")
			hexString = "3" + hexString;
		else if (subHexadecimalString == "0100")
			hexString = "4" + hexString;
		else if (subHexadecimalString == "0101")
			hexString = "5" + hexString;
		else if (subHexadecimalString == "0110")
			hexString = "6" + hexString;
		else if (subHexadecimalString == "0111")
			hexString = "7" + hexString;
		else if (subHexadecimalString == "1000")
			hexString = "8" + hexString;
		else if (subHexadecimalString == "1001")
			hexString = "9" + hexString;
		else if (subHexadecimalString == "1010")
			hexString = "A" + hexString;
		else if (subHexadecimalString == "1011")
			hexString = "B" + hexString;
		else if (subHexadecimalString == "1100")
			hexString = "C" + hexString;
		else if (subHexadecimalString == "1101")
			hexString = "D" + hexString;
		else if (subHexadecimalString == "1110")
			hexString = "E" + hexString;
		else if (subHexadecimalString == "1111")  //This doesn't have to be an else if but makes it easier to understand
			hexString = "F" + hexString;

	}

	cout << "The Hexadecimal value is " << hexString << "." << endl;;

}

//Purpose:Displays the base 10 value of the 32bit unsigned integer
//Preexisting conditions:The 32bit unsigned integer has been converted to a string array
//Return Values:Does not return anything only displays the value to the screen
void displayBase10(string binaryValue)
{
	//Here is a mathematical way to convert the binary number back to decimal - I couldn't think up a similar 
	//system to my hex or octal conversion system in the time I had available. I will be interested to see in
	//what the official answer shows up as to spark future creativity.
	unsigned long int decimalValue = 0;
	unsigned long int baseNumber = 1;

	for (int i = (binaryValue.length() - 1); i >= 0; i--)
	{
		if (binaryValue[i] == '1')
			decimalValue += baseNumber;
		baseNumber = baseNumber * 2;
	}

	cout << "The base 10 value is " << decimalValue << "." << endl;

}



//Purpose: Add two 32bit unsigned integers and display their values and result in binary and as unsigned integers
//The directions for this section were confusing but I understand it as take two base10 numbers turn them to binary
//Add them together as binary numbers and then display the resulting binary version as well as the base10 version
//Preexisting conditions:Two valid 32bit unsigned integers are required
//Return Values:Does not return anything, only displays the values to the screen
void binaryAddition(string binaryString1, string binaryString2)
{
	unsigned long int num1[32] = { };
	unsigned long int num2[32] = { };
	unsigned long int result[32] = { };
	int carry = 0;

	//step 1 Convert each character in the string binary representation for both numbers into its integer representation 
	//storing it in num1 and num2 respectively  - take both numbers we currently have in binary format and change them into 
	//integer format
	for (int i = 0; i <= 31; i++)
	{
		if (binaryString1[i] == '1')
		{
			num1[i] = 1;
		}
		else
			num1[i] = 0;

		if (binaryString2[i] == '1')
		{
			num2[i] = 1;
		}
		else
			num2[i] = 0;

	}
	cout << "Verifying that the numbers converted correctly" << endl;
	cout << "Num1 binary: ";
	for (int i = 0; i <= 31; i++)
		cout << num1[i];
	cout << endl;
	cout << "Num2 binary: ";
	for (int i = 0; i <= 31; i++)
		cout << num2[i];
	cout << endl;

	//step 2 Perform binary addition using the two integer arrays where the result of the addition is stored in result
	//Best quote ever: "Ten percent of nothin' is ...let me do the math here... nothin' into nothin' ... carry the nothin'"
	//By Jayne - Firefly








	//step 3 Display the contents of num1, num2 and result in both binary format and as unsigned integers
	cout << "Num1 binary: " << binaryString1 << endl; 
	cout << "Num1 unsigned integers: ";
	displayBase10(binaryString1);

	cout << "Num2 binary: " << binaryString2 << endl;
	cout << "Num2 unsigned integers: ";
	displayBase10(binaryString2);

	cout << "Result binary: " << endl;
	cout << "Result unsigned integers: " << endl;






}
