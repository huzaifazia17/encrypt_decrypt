// Assignment 2- Information Technology
// Zubair Islam
// Huzaifa Zia
// Hanzalah Patel

#include <iostream>
#include <math.h>
#include <string>
#include <stdlib.h>
#include <sstream>

using namespace std;

void encrypt(int x, char input[], int inputsize);
char decrypt(int x, char input[]);

int main()
{
	char userInput[100];
	int numberSelection;
	char run = 'C';
	char s[100];
	string input;
	int inputSize;

	while (run = 'C')
	{
		//Ask for input and get input
		cout << "Welcome to Cryptographic Techniques Program" << endl;
		cout << "Enter your input: ";
		cin.ignore();
		cin.getline(userInput, sizeof(userInput));
		cout << endl;
		inputSize = sizeof(userInput);

		//Ask user what they want to do
		cout << "Select what you would like to do to your input. " << endl;
		cout << "1. Encrypt" << endl;
		cout << "2. Decrypt" << endl;
		cout << "Enter 1 or 2: ";
		cin >> numberSelection;

		//if encrypt is selected, it will then ask what cipher they want to use
		if (numberSelection == 1)
		{
			cout << endl;
			cout << "Encrypt: " << endl;

			//call function
			encrypt(numberSelection, userInput, inputSize);
		}

		//if decrypt is selected, it will then ask what cipher they want to use
		else if (numberSelection == 2)
		{
			cout << endl;
			cout << "Decrypt: " << endl;

			//call function
			decrypt(numberSelection, userInput);
		}
		cout << endl;
		cout << "To continue with encrypting/decrypting enter C, else to exit enter E" << endl; // Prompt user to exit or re run
		cin >> run;
		run = toupper(run);

		while (run != 'E' && run != 'C') // Error check for input value, must be only E or C
		{
			cout << "To continue with encrypting/decrypting enter C, else to exit enter E" << endl;
			cin >> run;
			run = toupper(run);
		}

		if (run == 'E') // If E is entered then exit the program
		{
			exit(2);
		}
	}
}

void encrypt(int x, char input[], int inputsize)
{
	char newLetter[100];

	cout << "Which cipher would you like to use? " << endl;
	cout << "1. Caesar cipher" << endl;
	cout << "2. Vigenere cipher" << endl;
	cout << "Enter 1 or 2: ";
	cin >> x;

	while (x != 1 && x != 2)
	{
		cout << "Enter either 1 for Ceaser Cipher or 2 for Vigenere Cipher" << endl;
		cin >> x;
	}

	if (x == 1)
	{
		cout << "You have selected Caesar cipher" << endl;

		// ONLY PRINTS 4 LETTERS, NEED TO CHANGE THE i< sizeof(input) to something else
		//SO IT LOOPS AS LONG AS INPUT

		for (int i = 0; i <= inputsize; i++)
		{
			if (input[i] != ' ')
			{
				// Caesar encryption algorithm which works perfectly
				newLetter[i] = (input[i] - '0' + 7) % 75 + '0';
				// cout << newLetter;
			}
			else
			{
				newLetter[i] = ' ';
				//cout << newLetter;
			}
		}
	}
	else if (x == 2)
	{
		cout << "You have selected Vigenere cipher" << endl;

		for (int i = 0; i <= inputsize; i++)
		{

			// Vigenere encryption cipher formula but needs to be fixed
			//  This works but it is not the way its supposed to be in the algorithm
			// that is provided in assignment;  E = (C + k) % 26

			newLetter[i] = (input[i] + 8) % 26;
			newLetter[i] += 'a';

			//cout << newLetter;
		}
	}

	for (int i = 0; i < inputsize; i++)
	{
		cout << newLetter[i];
	}
}

// NEED TO FILL IN CODE FOR DECRYPT
char decrypt(int x, char input[])
{

	//VARIABLE TO DECRYPT LETTER TO AND STORE
	char newLetter;

	cout << "Which cipher would you like to use? " << endl;
	cout << "1. Caesar cipher" << endl;
	cout << "2. Vigenere cipher" << endl;
	cout << "Enter 1 or 2: ";
	cin >> x;

	if (x == 1)
	{
		cout << "You have selected Caesar cipher" << endl;

		//ENTER CAESAR DECRYPTION ALGORITHM HERE
	}
	else if (x == 2)
	{
		cout << "You have selected Vigenere cipher" << endl;

		//ENTER VIGENERE DECRYPTION ALGORITHM HERE
	}
	return x;
}