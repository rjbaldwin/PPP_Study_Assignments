/*
TASK 08:

8. Create a Patron class for the library. 
The class will have a user’s name, library card number, and library fees (if
owed). 
Have functions that access this data, as well as a function to set the fee of the user. 
Have a helper function that returns a Boolean (bool) depending on whether or not the user owes a fee.
*/

// Created by Robert J Baldwin 07/03/2023
// Version: Task 07 - 07/03/2023



#include<iostream>
#include<vector>
#include<string>
#include "header.h"

using std::endl;
using std::cin;
using std::cout;


int main()
{



    // adding details to each book
    RobsLibrary::ISBN dead(213, 42, 456, 'x');
    string deadISBN = toString(dead);
    RobsLibrary::Book deadZone(deadISBN, "The Dead Zone", "Stephen King", 1979, RobsLibrary::Genre::fiction);



    RobsLibrary::ISBN hot(1, 452, 222, 'b');
    string hotISBN = toString(hot);
    RobsLibrary::Book hotZone(hotISBN, "The Hot Zone", "Richard Preston", 1994, RobsLibrary::Genre::nonfiction);


    RobsLibrary::ISBN aud(222, 42454, 1771456, 'c');
    string audISBN = toString(aud);
    RobsLibrary::Book audio(audISBN, "The Audio Expert", "Ethan Winer", 2008, RobsLibrary::Genre::nonfiction);



    // testing the Patron class
    RobsLibrary::Patron baldwin("Robert Baldwin", 45612, 1.50);
    RobsLibrary::Patron kirkham("Rachel Kirkham", 41234, 2.25);


    // creating a vector for books
    RobsLibrary::Database libraryDatabase;
    // copying the books to the database (vector)
    libraryDatabase += deadZone;
    libraryDatabase += hotZone;
    libraryDatabase += audio;

    // creating a vector for patrons
    RobsLibrary::PDatabase patronRecords;
    // copying the patrons to the patron database (vector)
    patronRecords += baldwin;
    patronRecords += kirkham;

    


    


    //************************************************************
    //** Prototype front end **

    cout << "**** Library Booking System v1.8 ****\n";

    



    while (true) // loop until user quits
    {
        cout << "** Select one of the following: ** \n";
        cout << '\n';
        cout << "1. Display library database.\n ";
        cout << '\n';
        cout << "2. Display library patrons.\n ";
        cout << '\n';
        cout << "3. Check book availability.\n ";
        cout << '\n';
        cout << "4. Loan a book.\n";
        cout << '\n';
        cout << "5. Return a book.\n";
        cout << '\n';
        cout << "q. Quit. \n";


        char option{};
        cin >> option;



        switch (option)
        {
        case'1':
            cout << libraryDatabase;
            break;

            //--------------------------------------------------------------------
        case'2':
            cout << patronRecords;
            break;

            //--------------------------------------------------------------------
        case'3':
            cout << "What book would you like to check? \n";
            cout << "1. The Deadzone\n";
            cout << "2. The Hotzone\n";
            cout << "3. The Audio Expert\n";
            cout << "b. Back \n";


            cin >> option;
            switch (option)
            {
            case'1':
                deadZone.availability();
                break;
            case'2':
                hotZone.availability();
                break;
            case '3':
                audio.availability();
                break;
            case 'b':
                // Go back to the main menu
                break;
            default:
                cout << "Not a valid selection \n";
            }
            //--------------------------------------------------------------------

        case'4':
            cout << "What book would you like to loan? \n";
            cout << "1. The Deadzone\n";
            cout << "2. The Hotzone\n";
            cout << "3. The Audio Expert\n";
            cout << "b. Back \n";


            cin >> option;
            switch (option)
            {
            case'1':
                deadZone.bookLend();
                break;
            case'2':
                hotZone.bookLend();
                break;
            case '3':
                audio.bookLend();
                break;
            case 'b':
                // Go back to the main menu
                break;
            default:
                cout << "Not a valid selection \n";
            }
            //--------------------------------------------------------------------


        case'5':
            cout << "What book would you like to return? \n";
            cout << "1. The Deadzone\n";
            cout << "2. The Hotzone\n";
            cout << "3. The Audio Expert\n";
            cout << "b. Back \n";


            cin >> option;
            switch (option)
            {
            case'1':
                deadZone.bookReturn();
                break;
            case'2':
                hotZone.bookReturn();
                break;
            case '3':
                audio.bookReturn();
                break;
            case 'b':
                // Go back to the main menu
                break;
            default:
                cout << "Not a valid selection \n";
            }
            break;
        case'q':
            return 0;

        default:
            cout << "Not a valid selection \n";


        }




    }

}


