// Assignment 2- Information Technology
// Zubair Islam
// Huzaifa Zia
// Hanzalah Patel

#include <iostream>
#include <math.h>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <cstring>

using namespace std;

void encrypt(int x, char input[], int inputsize);
void decrypt(int x, char input[], int inputsize);

int main()
{
    char userInput[100];
    int numberSelection;
    char run = 'C';
    char s[100];
    string input;
    int inputSize;

    while (run)
    {
        //Ask for input and get input
        cout << "Welcome to Cryptographic Techniques Program" << endl;
        cout << "Enter your input: ";
        cin.ignore(cin.rdbuf()->in_avail(), '\n');
        cin.getline(userInput, sizeof(userInput));

        cout << endl;
        inputSize = strlen(userInput);

        //Ask user what they want to do
        cout << "Select what you would like to do to your input. " << endl;
        cout << "1. Encrypt" << endl;
        cout << "2. Decrypt" << endl;
        cout << "Enter 1 or 2: ";
        cin >> numberSelection;

        while (numberSelection != 1 && numberSelection != 2) {
            cout << "Enter either 1 or 2: ";
            cin >> numberSelection;
        }
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
            decrypt(numberSelection, userInput, inputSize);
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
    char newLetter;

    cout << "Which cipher would you like to use? " << endl;
    cout << "1. Caesar cipher" << endl;
    cout << "2. Vigenere cipher" << endl;
    cout << "Enter 1 or 2: ";
    cin >> x;
    cout << endl;

    while (x != 1 && x != 2)
    {
        cout << "Enter either 1 for Ceaser Cipher or 2 for Vigenere Cipher" << endl;
        cin >> x;
        cout << endl;
    }

    if (x == 1)
    {
        cout << "You have selected Caesar cipher" << endl;

        for (int i = 0; i < inputsize; i++)
        {
            if (input[i] != ' ')
            {
                // Caesar encryption algorithm which works perfectly only after first run
                // During first run it skips first letter?
                input[i] = tolower(input[i]);
                newLetter = (input[i] - 'a' + 7) % 26 + 'a';
                cout << newLetter;
            }
            else if (input[i] == ' ')
            {
                newLetter = ' ';
                cout << newLetter;
            }
        }
    }
    else if (x == 2)
    {
        char key;
        cout << "You have selected Vigenere cipher" << endl;
        cout << "Select a key: Choose a letter between a-z:" << endl;
        cin >> key;
        key = tolower(key);

        for (int i = 0; i < inputsize; i++)
        {
            if (input[i] != ' ')
            {

                newLetter = (input[i] + 8) % 26;
                newLetter += (key - 1);

                cout << newLetter;
            }
            else if (input[i] == ' ')
            {
                newLetter = ' ';
                cout << newLetter;
            }
        }
    }
}

// NEED TO FILL IN CODE FOR DECRYPT
void decrypt(int x, char input[], int inputsize)
{

    //VARIABLE TO DECRYPT LETTER TO AND STORE
    char newLetter;

    cout << "Which cipher would you like to use? " << endl;
    cout << "1. Caesar cipher" << endl;
    cout << "2. Vigenere cipher" << endl;
    cout << "Enter 1 or 2: ";
    cin >> x;
    cout << endl;

    while (x != 1 && x != 2)
    {
        cout << "Enter either 1 for Ceaser Cipher or 2 for Vigenere Cipher" << endl;
        cin >> x;
        cout << endl;
    }

    if (x == 1)
    {
        cout << "You have selected Caesar cipher" << endl;

        for (int i = 0; i < inputsize; i++)
        {
            if (input[i] != ' ')
            {
                input[i] = tolower(input[i]);
                newLetter = (input[i] - 'a' - 7 + 26) % 26 + 'a';
                cout << newLetter;
            }
            else if (input[i] == ' ')
            {
                newLetter = ' ';
                cout << newLetter;
            }
        }
    }
    else if (x == 2)
    {

        char key;
        cout << "You have selected Vigenere cipher" << endl;
        cout << "Select a key: Choose a letter between a-z:" << endl;
        cin >> key;
        key = tolower(key);

        for (int i = 0; i < inputsize; i++)
        {
            if (input[i] != ' ')
            {
                input[i] = tolower(input[i]);
                newLetter = (input[i] - (key)+26) % 26 + 'a';
                //newLetter += (key-1);

                cout << newLetter;
            }
            else if (input[i] == ' ')
            {
                newLetter = ' ';
                cout << newLetter;
            }
        }
    }
}