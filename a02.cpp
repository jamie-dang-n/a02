/******************************************************************************
# Author:           Jamie Dang
# Assignment:       Assignment 2
# Date:             4/13/23
# Description:      This program encodes a user’s information into a file name for D2L. 
#                   The encoded file name is based on the user’s first/last name, student 
#                   ID, whether they were late or not, the time the file was submitted 
#                   (in military time) and the name of the file they are submitting to class.
# Input:            char lastName[], firstName[], userID[], userFile[];
#                   char menuCHoice; int hour, min
# Output:           char encodedName[]
# Sources:          ZyBooks, GD Iyer's Code Examples
#******************************************************************************/

#include <iostream>
#include <limits> // for cin.ignore
using namespace std;

// Constants
const int MAXCHAR = 101;
const char ERROR[MAXCHAR] = "Invalid option! Please try again!!";

//Function Prototypes
void welcome();
void goodbye();
char displayMenu();
void charToLower(char charWord[]);
void encode(char encodeFileName[]);
void readInput(char fName[], char lName[], bool& lateFlag);
void readInput(char parsedID[], char fileName[]);
void readTime(char strTime[]);


// Main
int main()
{
    cout << "Hello World!\n";
}


// Function Definitions

//Name:   
//Desc:   
//input:  
//output: 
//return:

//Name:   welcome()
//Desc:   This function prints a welcome message
//input:  None
//output: welcome message
//return: None
void welcome() {
    cout << "Welcome to my fileName encoding program!" << endl;
}

//Name:   goodbye()
//Desc:   This function prints the thank you/goodbye message
//input:  None
//output: goodbye message
//return: None
void goodbye() {
    cout << "Thank you for using my fileName generator!" << endl;
}

//Name:   displayMenu()
//Desc:   This function displays the menu and reads the user's choice
//input:  none
//output: the options menu
//return: char choice
char displayMenu() {
    char choice;
    cout << "Please pick an option below: " << endl;
    cout << "(e)Encode a file name" << endl;
    cout << "(q)quit" << endl;
    cin >> choice;
    choice = tolower(choice);
    while (!cin || cin.peek() != '\n' || choice != 'q' || choice != 'e') {
        cout << ERROR << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please pick an option below: " << endl;
        cout << "(e)Encode a file name" << endl;
        cout << "(q)quit" << endl;
        cin >> choice;
    }
    return choice;

}

//Name:   charToLower()
//Desc:   This function takes a char array and converts it to lowercase
//input:  char charWord[]
//output: none
//return: none
void charToLower(char charWord[]) {
    for (int i = 0; i < strlen(charWord); i++) {
        if (isalpha(charWord[i])) {
            charWord[i] = tolower(charWord[i]);
        }
    }
}

//Name:   readInput(char fName[], lName[], bool& lateFlag) - overloaded 
//Desc:   This function reads in the user's name and stores
//        a boolean indicating assignment lateness.
//input:  char yesOrNo, char lName[], char fName[]
//output: prompts for name and lateness
//return: none
void readInput(char fName[], char lName[], bool& lateFlag) {
    char yesOrNo;
    
    cout << "Enter your last name:";
    cin >> lName;
    charToLower(lName);

    cout << "Enter your first name: ";
    cin >> fName;
    charToLower(fName);

    cout << "Was your assignment late (y/n)? ";
    cin >> yesOrNo;
    yesOrNo = tolower(yesOrNo);
    while (!cin || cin.peek() != '\n' || yesOrNo != '\n' || yesOrNo != '\n') {
        cout << ERROR << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Was your assignment late (y/n)? ";
        cin >> yesOrNo;
    }
    if (yesOrNo == 'y') {
        lateFlag = true;
    }
    else {
        lateFlag = false;
    }
}

//Name:   readInput(char parsedID[], charfileName[]) - overloaded 
//Desc:   This function reads in the user's student ID, parses it,
//        and stores it to parsedID[]. It also reads the user's 
//        file name.
//input:  char userID[], char fileName[]
//output: prompt for ID/File name
//return: none
void readInput(char parsedID[], char fileName[]) {
    char userID[12];
    cout << "Enter your Student-ID (format: 222-22-2222): ";
    cin >> userID;
    //strncpy(parsedID, userID + 7, 4);
    cout << "Enter the file name: ";
    cin >> fileName;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
