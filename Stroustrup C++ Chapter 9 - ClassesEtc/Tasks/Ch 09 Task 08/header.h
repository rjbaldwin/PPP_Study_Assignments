#pragma once

/*
TASK 08:

DONE 8. Create a Patron class for the library.
DONE The class will have a user’s name, library card number, and library fees (if
owed).
Have functions that access this data, as well as a function to set the fee of the user.
Have a helper function that returns a Boolean (bool) depending on whether or not the user owes a fee.
*/

// Created by Robert J Baldwin 07/03/2023
// Version: Task 07 - 07/03/2023



#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using std::ostream;
using std::string;
using std::stringstream;
using std::cout;
using std::endl;
using std::vector;


namespace RobsLibrary {

    // patron class definition 

    class Patron
    {
    public:

        Patron() = default;
        Patron(string name, int libCard, double fees);  // constructor declaration


        string getName()        // get name function
        {
            return mName;
        }    

        int getNo()             //get library card number 
        {
            return mLibCard;
        }
        
        
        
        double getFees()        //get outstanding fees
        {
            return mFees;
        }

        // Declare the << operator as a friend
        friend ostream& operator<<(ostream& os, const Patron& newPatron);

    private:

        string mName{};
        int mLibCard{};
        double mFees{};

    };








    // enumerator class for genre

    enum class Genre
    {
        fiction = 1,
        nonfiction,
        periodical,
        biography,
        childrens,
    };



    // 01 - struct ISBN definition 
    struct ISBN
    {
        int isbn1{};
        int isbn2{};
        int isbn3{};
        char isbnX{};


        // constructors

        ISBN(int n1, int n2, int n3, char x); // constructor function declaration 

        ISBN() = default;     // default constructor 

    };




    // 03 - class definition for Book

    class Book
    {
    public:

        // default constructor

        Book() = default;

        // constructor
        Book(string i, string t, string a, int d, Genre g);  // declaration of constructor function

        void availability();        // how many copies in stock
        void bookLend();             // Lend the book out
        void bookReturn();            // return the book



        // Declare the << operator as a friend

        friend ostream& operator<<(ostream& os, const Book& add);

        // return function values



        string getISBN() const
        {
            //cout << "ISBN No: ";
            return isbn;
        }
        string getTitle() const
        {
            //cout << "Title: ";
            return title;
        }
        string getAuthor() const
        {
            //cout << "Author: ";
            return author;
        }
        int getDate() const
        {
            //cout << "Copyright Date: ";
            return date;
        }
        Genre getGenre() const
        {
            return genre;
        }

    private:

        string isbn{};
        string title{};
        string author{};
        Genre genre{};
        int date{};
        int numCopies{ 2 };       // initial stock amount
        int numBorrowed{};


    };

    //--------------------------------------------------------------


    // 05 - Class definition for library Database class with vector 

    class Database
    {
    public:
        vector<Book>records;

        // operator member function

        void operator+=(Book& newBook)
        {
            this->records.push_back(newBook);
        }

    };

    // Class definition for patron Database class with vector 

    class PDatabase
    {
    public:
        vector<Patron>patrons;

        // operator member function

        void operator+=(Patron& newMember)
        {
            this->patrons.push_back(newMember);
        }

    };

    //-----------------------------------------------------------------------------------------------------
    //-----------------------------------------------------------------------------------------------------

    // function declarations 

    string toString(const ISBN& isbn);

    ostream& operator<<(ostream& os, const Book& add);

    ostream& operator<<(ostream& os, const Patron& newPatron);

    ostream& operator<<(ostream& os, Database& newBook);

    ostream& operator<<(ostream& os, PDatabase& newPatron);

    ostream& operator<<(ostream& os, const Genre& genre); // allows the enum Genre class to print 


}

