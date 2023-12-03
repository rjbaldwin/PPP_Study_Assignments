/*
TASK 05:

DONE - This exercise and the next few require you to design and implement a Book class, such as you can imagine as part of
software for a library.

DONE - Class Book should have members for the ISBN, title, author, and copyright date.

DONE - Also store data on whether or not the book is checked out.

DONE - Create functions for returning those data values.

DONE - Create functions for checking a book in and out.

Sort of DONE (revisit) -  Do simple validation of data entered into a Book; for example, accept ISBNs only of the form n-n-nx where n is an integer and x is a digit or a letter.

Store an ISBN as a string.*/


// Written by Robert J Baldwin 27/02/2023



#include<iostream>
#include<vector>
#include<string>
#include "book.h"
#include "E:\06_Programming Work\Stroustrup C++ Chapter Exercises\PPP-chapter-tasks\std_lib_facilities.h"

//--------------------------------------------------------------





int main()
{
   
   
    
    // adding details to each book
    string isbn1 = ISBNvalidation(213, 42, 456, 'x');

    Book deadZone(isbn1, "The Dead Zone", "Stephen King", 1979);


    string isbn2 = ISBNvalidation(1, 452, 222, 'b');

    Book hotZone(isbn2, "The Hot Zone", "Richard Preston", 1994);


    string isbn3 = ISBNvalidation(222, 42454, 1771456, 'c');

    Book audio(isbn3, "The Audio Expert", "Ethan Winer", 2008);
   
  
    // creating a vector 
    Database libraryDatabase;
    // copying the books to the database (vector)
    libraryDatabase += deadZone;
    libraryDatabase += hotZone;
    libraryDatabase += audio;
    
   
   // get info from class

   /*cout  << deadZone.getISBN() << '\n';
   cout  << deadZone.getTitle() << '\n';
   cout  << deadZone.getAuthor() << '\n';
   cout  << deadZone.getDate() << '\n';*/
   

   // get info from vector 
   // cout << libraryDatabase << endl;
 
   // test availability function

  /* deadZone.availability();

   deadZone.bookReturn();
   deadZone.bookLend();
   deadZone.bookLend();
   deadZone.bookLend();
   deadZone.bookReturn();
   deadZone.bookReturn();
   deadZone.bookReturn();*/

   
   //************************************************************
   //** Prototype front end **
 
   cout << "**** Library Booking System v1.0 ****\n";

   

   

   while (true) // loop until user quits
   {
       cout << "** Select one of the following: ** \n";
       cout << endl;
       cout << "1. Display library database.\n ";
       cout << endl;
       cout << "2. Check book availability.\n ";
       cout << endl;
       cout << "3. Loan a book.\n";
       cout << endl;
       cout << "4. Return a book.\n";
       cout << endl;
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


