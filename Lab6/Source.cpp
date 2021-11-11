/*
	Nikola Trajanovski
	Lab 6 due Nov 10th

	program that reads characters representing binary (base 2)
	numbers from a data file called BinaryIn.dat and translates them to decimal (base 10)
	numbers.There is only one binary number per input line, but an arbitrary number of blanks can 
	precede the number. The program must read the binary numbers one character at a 
	time. As each character is read, the program multiplies the total decimal value by 2 and 
	adds either a 1 or 0, depending on the input character.
*/

#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
using namespace std;

int convertToDecimal(string theBinary);

int main() {

	ifstream binaryIn;
	//error check to see if the file will open
	binaryIn.open("C:/Users/nikol/Desktop/C++/binaryIn.dat");
	if (binaryIn.fail()) {
		cerr << "error opening file";
		exit(1);
	}

	// num1 is a string that holds all the values from the binaryIn.dat file, one line at a time
	string num1;

	cout << "Binary value" << "\t\t\t   Decimal Value" << endl;
	while (!binaryIn.eof()){
			getline(binaryIn, num1);

		// statement that can output three different statements based on the convertToDecimal() function
		if (convertToDecimal(num1) == -2) {
			cout << "Bad digit on input!!!" << "\t\t\t\t" << endl;
		}
		else if (convertToDecimal(num1) != -1) {
			cout << "  " << num1 << "\t\t\t\t"<< convertToDecimal(num1) << endl;
		}
		else {
			cout << "Bad digit on input" << "\t\t\t\t" << endl;
		}
	}
	
	

	binaryIn.close();
	return 0;
}


//Precondition - this function must have a string as the parameter, 
//Postcondition - (1)this function can return an int(the converted decimal).
//				  (2)Or can return -1 if the string contains anything but 
//				  ones and zeroes.
//				  (3)Or it returns -2 if the string contains more than 2 consecutive spaces
int convertToDecimal(string theBinary){// theBinary holds the whole line of data from the binaryIn file
	int count = theBinary.length();
	int theBase = 1;
	int decimalNum = 0;
	
	
	for (int i = count-1; i >= 0; i--) {
		if (theBinary[i] != '1' && theBinary[i] != '0' && theBinary[count - 1] != ' ') {
			if (theBinary[i] == ' ' && theBinary[i - 1] == ' ') {
				return -2;
			}
			else if (theBinary[i] != ' ') {
				return -1;
			}
		}
		else{
			if (theBinary[i] == '1') {
				decimalNum = decimalNum + theBase;
			}
			theBase = theBase * 2;
		}
	}

	return decimalNum;
}