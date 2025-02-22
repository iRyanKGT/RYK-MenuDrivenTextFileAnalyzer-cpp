# RYK-MenuDrivenTextFileAnalyzer-cpp
![image](https://github.com/user-attachments/assets/86b87350-cb30-43ab-8786-d616fb8916f0)

/* ======================================================================== */

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

/* ======================================================================== */
