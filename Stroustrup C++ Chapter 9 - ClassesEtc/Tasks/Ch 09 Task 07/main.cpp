/*
TASK 07:

07. Create an enumerated type for the Book class called Genre. Have the types be fiction, nonfiction, periodical,
biography, and children. Give each book a Genre and make appropriate changes to the Book constructor and member
functions.

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
   

  
    // creating a vector 
    RobsLibrary::Database libraryDatabase;
    // copying the books to the database (vector)
    libraryDatabase += deadZone;
    libraryDatabase += hotZone;
    libraryDatabase += audio;

   

   
   //************************************************************
   //** Prototype front end **
 
   cout << "**** Library Booking System v1.0 ****\n";

   

   

   while (true) // loop until user quits
   {
       cout << "** Select one of the following: ** \n";
       cout << '\n';
       cout << "1. Display library database.\n ";
       cout << '\n';
       cout << "2. Check book availability.\n ";
       cout << '\n';
       cout << "3. Loan a book.\n";
       cout << '\n';
       cout << "4. Return a book.\n";
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

       case'3':
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


       case'4':
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


