/*
TASK 07:

07. Create an enumerated type for the Book class called Genre. Have the types be fiction, nonfiction, periodical,
biography, and children. Give each book a Genre and make appropriate changes to the Book constructor and member
functions.

*/

// Created by Robert J Baldwin 07/03/2023
// Version: Task 07 - 07/03/2023




#pragma once 


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


    // 05 - Class definition for Database class with vector 

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

    //-----------------------------------------------------------------------------------------------------
    //-----------------------------------------------------------------------------------------------------

    // function declarations 

    string toString(const ISBN& isbn);

    ostream& operator<<(ostream& os, const Book& add);

    ostream& operator<<(ostream& os, Database& newBook);

    ostream& operator<<(ostream& os, const Genre& genre); // allows the enum Genre class to print 

    
}

