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

//function prototype
void encrypt(int x, char input[], int inputsize);
void decrypt(int x, char input[], int inputsize);

int main()
{
    //stores input user wants to encrypt/decrypt
    char userInput[100];

    //variable to store input for selections
    int numberSelection;

    char run = 'C';// stores info about wether program should run again or not

    //variable to store length of user input
    int inputSize;


    //while loop which runs as long as user wants to keep
    //using the program until they want to exit
    while (run)
    {
      
        cout << "Welcome to Cryptographic Techniques Program" << endl;

        //Ask user for input to encrypt/decrypt
        cout << "Enter your input: ";
       
        cin >> ws;// Removes all white space from input 

        //get input
        cin.getline(userInput, sizeof(userInput));

        cout << endl;

        //gets the length of the user input
        inputSize = strlen(userInput);

        //Ask user whether they want to encrypt or decrypt their message
        cout << "Select what you would like to do to your input. " << endl;

        //show user options 1 or 2 and ask them to enter one of them
        cout << "1. Encrypt" << endl;
        cout << "2. Decrypt" << endl;
        cout << "Enter 1 or 2: ";
        cin >> numberSelection;

        //if user inputs any number other than 1 or 2, it will ask again
        while (numberSelection != 1 && numberSelection != 2) {
            cout << "Enter either 1 or 2: ";
            cin >> numberSelection;
        }
        //if encrypt is selected, it will then ask what cipher they want to use
        if (numberSelection == 1)
        {
            cout << endl;
            cout << "Encrypt: " << endl;

            //call function to encrypt message
            encrypt(numberSelection, userInput, inputSize);
        }

        //if decrypt is selected, it will then ask what cipher they want to use
        else if (numberSelection == 2)
        {
            cout << endl;
            cout << "Decrypt: " << endl;

            //call function to decrypt message
            decrypt(numberSelection, userInput, inputSize);
        }

       
        cout << endl;

        //ask if user wants to use program again or exit
        cout << endl << "To continue with encrypting/decrypting enter C, else to exit enter E: "; // Prompt user to exit or re run
        cin >> run;

        //if user inputs lowercase, their input will be changed to uppercase
        run = toupper(run);
        
        //if user does not enter specified letters, they will be asked again
        while (run != 'E' && run != 'C') // Error check for input value, must be only E or C
        {
            cout << "To continue with encrypting/decrypting enter C, else to exit enter E: ";
            cin >> run;
            run = toupper(run);
        }

        //if user wants to exit, program will exit
        if (run == 'E') // If E is entered then exit the program
        {
            exit(2);
        }
        cout << endl;
    }
}

//function to encrypt message
void encrypt(int x, char input[], int inputsize)
{
    //VARIABLE TO ENCRYPT LETTERS TO AND STORE
    char newLetter;

    //ask user what cipher to use
    cout << "Which cipher would you like to use? " << endl;
    cout << "1. Caesar cipher" << endl;
    cout << "2. Vigenere cipher" << endl;
    cout << "Enter 1 or 2: ";
    cin >> x;
    cout << endl;

    //if user inputs any number other than specified numbers, they will be asked again
    while (x != 1 && x != 2)
    {
        cout << "Enter either 1 for Ceaser Cipher or 2 for Vigenere Cipher" << endl;
        cin >> x;
        cout << endl;
    }

    //if loop when user wants to encrypt their message through Caesar cipher
    if (x == 1)
    {
        cout << "You have selected Caesar cipher." << endl;
        cout << "Caesar encryption: ";

        //for loop which runs as long the amount of characters in the user input
        for (int i = 0; i < inputsize; i++)
        {
            //if user input is not empty
            //if loop will be run
            if (input[i] != ' ')
            {
                //turns any uppercase letters in input to lowercase
                input[i] = tolower(input[i]);

                //CAESAR CIPHER ENCRYPTION
                //Encrypts each letter in input to new letter          
                newLetter = (input[i] - 'a' + 7) % 26 + 'a';

                //prints out new encrypted letter
                cout << newLetter;
              
            }

            //if user input is empty,   
            //set new letter as empty  
            //and output nothing
            else if (input[i] == ' ')
            {            
                newLetter = ' ';
                cout << newLetter;
            }
        }
    }

    //if loop when user wants to encrypt their message through Vigenere cipher
    else if (x == 2)
    {
        char key;

        cout << "You have selected Vigenere cipher." << endl;

        //ask user for the key they want to use to encrypt their message
        cout << "Select a key. Choose a letter between a-z: ";
        
        //get user input for key
        cin >> key;

        //if key is uppercase, change it to lowercase
        key = tolower(key);

        cout << "Vigenere encryption: ";

        //for loop which runs as long the amount of characters in the user input
        for (int i = 0; i < inputsize; i++)
        {
            //if user input is not empty
            //if loop will be run
            if (input[i] != ' ')
            {
                //VIGENERE CIPHER ENCRYPTION
                //Encrypts each letter in input to new letter
                newLetter = (input[i] + 8) % 26;
                newLetter += (key - 1);

                //prints out new encrypted letter
                cout << newLetter;
            }

            //if user input is empty,   
            //set new letter as empty  
            //and output nothing       
            else if (input[i] == ' ')
            {       
                newLetter = ' ';    
                cout << newLetter;
            }
        }
    }
}

//function to decrypt message
void decrypt(int x, char input[], int inputsize)
{
    //VARIABLE TO DECRYPT LETTERS TO AND STORE
    char newLetter;


    //ask user what cipher to use
    cout << "Which cipher would you like to use? " << endl;
    cout << "1. Caesar cipher" << endl;
    cout << "2. Vigenere cipher" << endl;
    cout << "Enter 1 or 2: ";
    cin >> x;
    cout << endl;

    //if user inputs any number other than specified numbers, they will be asked again
    while (x != 1 && x != 2)
    {
        cout << "Enter either 1 for Ceaser Cipher or 2 for Vigenere Cipher: ";
        cin >> x;
        cout << endl;
    }

    //if loop when user wants to decrypt their message through Caesar cipher
    if (x == 1)
    {
        cout << "You have selected Caesar cipher." << endl;
        cout << "Caesar decryption: ";


        //for loop which runs as long the amount of characters in the user input
        for (int i = 0; i < inputsize; i++)
        {
            //if user input is not empty
            //if loop will be run
            if (input[i] != ' ')
            {
                
                //turns any uppercase letters in input to lowercase
                input[i] = tolower(input[i]);

                //CAESAR CIPHER DECRYPTION
                //Decrypts each letter in input to new letter
                newLetter = (input[i] - 'a' - 7 + 26) % 26 + 'a';

                //prints out new decrypted letter
                cout << newLetter;
            }

            //if user input is empty,   
            //set new letter as empty  
            //and output nothing         
            else if (input[i] == ' ')
            {          
                newLetter = ' ';
                cout << newLetter;
            }
        }
    }

    //if loop when user wants to decrypt their message through Vigenere cipher
    else if (x == 2)
    {
        char key;
        cout << "You have selected Vigenere cipher" << endl;

        //ask user for the key they want to use to encrypt their message
        cout << "Select a key: Choose a letter between a-z: ";

        //get user input for key
        cin >> key;

        //if key is uppercase, change it to lowercase
        key = tolower(key);

        cout << "Caesar decryption: ";
        
        //for loop which runs as long the amount of characters in the user input
        for (int i = 0; i < inputsize; i++)
        {
            //if user input is not empty
            //if loop will be run
            if (input[i] != ' ')
            {          
                //turns any uppercase letters in input to lowercase
                input[i] = tolower(input[i]);

                //VIGENERE CIPHER DECRYPTION
                //Decrypts each letter in input to new letter
                newLetter = (input[i] - (key)+26) % 26 + 'a';
               
                //prints out new decrypted letter
                cout << newLetter;
            }

            //if user input is empty,   
            //set new letter as empty  
            //and output nothing
            else if (input[i] == ' ')
            {                       
                newLetter = ' ';
                cout << newLetter;
            }
        }
    }
}