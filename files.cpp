/* ========================================================================= */
/*	PROGRAM Menu-Driven Text File Analyzer

    AUTHOR: Ryan Kunjbehari
    FSU MAIL NAME: EF0825229
    RECITATION SECTION NUMBER: 02
    RECITATION INSTRUCTOR NAME: Yanan Yu
    COP 3014 - Summer 2009
    PROJECT NUMBER: 4
    DUE DATE: Wednesday 7/8/2009
    PLATFORM: Windows OS using Microsoft Visual C++ Express 2008 compiler

SUMMARY

This program initially opens up a file and then displays a menu to the user. 
This menu enables the user to choose between six options that either readout 
different information or quit the program.

INPUT

The input is entirely interactive.  It will only require the user to 
enter the file name for the document they would like to analyze.  All input
is typed in at the keyboard by the user (person running the program). 

OUTPUT

All output goes to the text (console) window.  The program prints an output 
title and echoprints the user's input in a readable fashion.  A six option 
menu is printed out as well for the user to enter in a choice.

ASSUMPTIONS

We cannot assume that all input data is valid and correctly entered by the 
user.  Therefore, this program counteracts this problem by looping the file
opening sequence as well as the menu choice selection.  The file opening
loop tests for correct spelling of file name whereas the menu choice
selection loop tests for correct choice of the numbers 1-6.

*/

/* ========================================================================= */

#include <iostream>
#include <fstream>			// for file I/O (Reading the text file)
#include <string>			// for reading the file name the user inputs
#include <cctype>			// for menu option 6 (the character analysis)
         	
using namespace std;

/* ========================================================================= */


/* Function Prototypes:

OpenNewFile() - Opens the text file, ShowMenu() - Display's the menu, 
PrintFile() - Prints the contents of the file, CountLines() - Counts lines in 
the text file, CountWords() - Counts words in the test file, 
CountSentences() - Counts sentences in the text file, 
CharacterAnalysis() - Counts characters, digit, alpha, punctuation, and 
whitespace characters, Quit() Terminates the Program */
void OpenNewFile(string& fileName,ifstream& inFile);		
void ShowMenu();											
void PrintFile(string fileName,ifstream& inFile); 
void CountLines(string fileName, ifstream& infile);		
void CountWords(string fileName,ifstream& inFile);		
void CountSentences(string fileName,ifstream& inFile);	
void CharacterAnalysis(string fileName,ifstream& inFile);			
void Quit(bool& flag, ifstream &inFile);


int main()
{
	// named symbolic constants and variables
	char choice;			// Holds the menu choice
	string fileName;		// Holds the file name
	ifstream inFile;		// holds the file stream variable
	bool flag = true;		// flag for menu choice error detection

	// print overall program output heading
	cout << "*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*\n\n";
	cout << "Welcome to Ryan's Menu-Driven Text File Analyzer\n\n";
	cout << "*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*\n\n";
	
	OpenNewFile(fileName,inFile);  // Call to OpenNewFile function

	do
	{		
		// This displays the menu and also gets the user's choice
		ShowMenu();
		cin >> choice;
		cin.ignore(80,'\n');	   // Ignores everything after 
								   // initial character choice
	
			
		/* All of the cases in this switch call to their respective 
		functions down below in order to perform the tasks selected 
		from the outputted user menu */
		switch (choice) 
				{
			case '1': PrintFile(fileName,inFile);		
				break;
			case '2': Quit(flag,inFile); 
				break;
			case '3': CountLines(fileName,inFile);
				break;
			case '4': CountWords(fileName,inFile);
				break;
			case '5': CountSentences(fileName,inFile);
				break;
			case '6': CharacterAnalysis(fileName,inFile);	
				break;
			default : // used for error detection
				cout << "You have entered an incorrect choice,\n";
				cout << "Please enter 1, 2, 3, 4, 5, or 6: \n";
				break;
									
		}
		
		// used to "rewind" the text file
		inFile.clear();
		inFile.seekg(0L, ios::beg);
		
	}while (flag);
	return 0;
}

	
//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
// Here is the function to dispaly the menu.				*									
//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

void ShowMenu()  
{ // ShowMenu
	cout << "\nPick a task to perform: \n\n";
	cout << "1. Print the file's contents\n"; 
	cout <<	"2. Quit the program\n"; 
	cout <<	"3. Count the number of lines in the file\n";
	cout <<	"4. Count the words in the file\n";
	cout <<	"5. Count the sentences in the file\n"; 
	cout <<	"6. Do a character analysis, including\n";
	cout << "\tcount the number of characters in the file\n"; 
	cout << "\tcount alphabetic characters\n";
	cout << "\tcount digit characters\n";
	cout << "\tcount punctuation characters\n";
	cout << "\tcount whitespace characters\n\n";
	cout << "Please enter your choice: ";
} // ShowMenu

		
//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
// Here is the function to initially open the file to be used for *	  
// analysis in this program.									  *									
//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

void OpenNewFile 
(string& fileName,    // the name of the file being analyzed 
ifstream& inFile)     // its corresponding stream variable

{  // OpenNewFile
	bool badFile = true;   // true as long as file can't be opened

	while (badFile)        // loop until file IS open
	{
		// ask the user for a file name and try to open it
		cout << endl << "Enter the name of the file you want to analyze: ";
		cin >> fileName;
		inFile.open (fileName.c_str());

		// check for opening ok; if not, print an error message and re-prompt
		if (inFile)
		{
			cout << endl << "The file was opened successfully." << endl;
			badFile = false;
		}
		else // file did not open
		{
			inFile.clear ();
			cout << "Can't open the file - please re-enter the name and"
				 << endl << " be sure it is spelled correctly." << endl;
		}
	} // while loop

}   // OpenNewFile



//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
// Here is the function to print the contents of the file.		*	  																	
//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

void PrintFile
(string fileName,    // the name of the file being analyzed
ifstream& inFile)    // its corresponding stream variable

// This function simply reads the file one character at a time until 
// end of file, and prints every character read.

{  // PrintFile
   char ch;    // used to read one character at a time from the file

   // loop through entire file until eof, and echoprint every character
   cout << "The contents of the file " << fileName << ":" << endl << endl;
   inFile.get (ch); // read very first char in file
   while (inFile)
   {
      cout << ch;
      inFile.get (ch); // get the next char
   }

}  // PrintFile


//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
// Here is the function to quit the program						*	  																	
//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
void Quit(bool& flag, ifstream &inFile)
{ // Quit
	flag = false;		
	inFile.clear();		// clears file data from memory
	inFile.close();		// closes file on program exit
	cout << "\n\nEnding the File Analyzer, Thanks for trying!\n";
} // Quit


//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
// Here is the function to count lines in the file.				*	  																	
//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
void CountLines(string fileName, ifstream& inFile)
{ // CountLines
	char ch;
	int count = 0;		// set counter to zero.
	
	inFile.get (ch);

	while (inFile)		// loop to count lines that end with eol (/n)
	{
		if (ch == '\n')
			count ++;
		inFile.get (ch);
	}
	cout << "The number of lines in the file " << fileName << " is: " 
		 << count << endl;
} // CountLines


//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
// Here is the function to count sentences in the file.			*	  																	
//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
void CountSentences(string fileName,ifstream& inFile)
{ // CountSentences
	char ch;
	int count = 0;    // set counter to zero.
	
	inFile.get (ch);

	while (inFile)   //  loop to count sentences that end with periods
	{
		if (ch == '.')
			count ++;
		inFile.get (ch);
	}
	cout << "The number of sentences in the file " << fileName << " is: " 
		 << count << endl;
} // CountSentences


//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
// Here is the function to count words in the file.			    *	  																	
//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
void CountWords(string fileName,ifstream& inFile)
{ // CountWords
	bool flag = false;  
	char ch;
	int count = 0;

	inFile.get (ch);

	while(inFile)    // loop to check if character is alphabetic or numeric
	{
		if (isalnum (ch))
		{
			if(flag == false)
			{
				count ++;
				flag = true;
			}
		}
		else
			flag = false;
		inFile.get (ch);
	}
	cout << "The number of words in the file " << fileName << " is: " 
		 << count << endl;
} // CountWords


//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
// Here is the function to perform a character analysis in the file.  *
// This function counts characters, digit, alpha, punctuation, and    *
// whitespace characters,											  *	  																	
//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
void CharacterAnalysis(string fileName,ifstream& inFile)
{ // CharacterAnalysis
	int count = 0, 
		alphaCount = 0,		// alphabetic characters counter
		digitCount = 0,		// digit characters counter
		punctCount = 0,		// punctuation characters counter
		spcCount = 0;		// whitespace characters counter

	char ch;
	
	inFile.get (ch);

	while (inFile)  // loop to count all the types of characters
	{
		count ++;
		if (isalpha (ch)) 
			alphaCount ++;
		
		else if (isdigit (ch))
			digitCount ++;

		else if (ispunct (ch))
			punctCount ++;
		
		else if (isspace (ch))
			spcCount ++;
		
		inFile.get (ch);

	}
	
	cout << "The number of characters in the file " 
		 << fileName << " is: " << count << endl;
	cout << "The number of alphabetic characters in the file " 
		 << fileName << " is: " << alphaCount << endl;
	cout << "The number of digit characters in the file "
		 << fileName << " is: " 
		 << digitCount << endl;
	cout << "The number of punctuation characters in the file " 
		 << fileName << " is: " << punctCount << endl;
	cout << "The number of whitespace characters in the file " 
		 << fileName << " is: " << spcCount << endl;
} // Character Analysis


/* ========================================================================= */
/*                           END OF PROGRAM                                  */
/* ========================================================================= */

