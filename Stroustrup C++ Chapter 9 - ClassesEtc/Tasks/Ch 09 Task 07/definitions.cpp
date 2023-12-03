/*
TASK 07:

07. Create an enumerated type for the Book class called Genre. Have the types be fiction, nonfiction, periodical,
biography, and children. Give each book a Genre and make appropriate changes to the Book constructor and member
functions.

*/

// Created by Robert J Baldwin 07/03/2023
// Version: Task 07 - 07/03/2023




#include "header.h"

namespace RobsLibrary {

	// function definitions

    // 01 - ISBN constructor function definition

    ISBN::ISBN(int n1, int n2, int n3, char x)
        :isbn1{ n1 }, isbn2{ n2 }, isbn3{ n3 }, isbnX{ x }
    {

    }



    // 02 - function to convert struct ISBN to string as per request

    string toString(const ISBN& isbn)
    {
        stringstream ss;
        ss << isbn.isbn1 << "-" << isbn.isbn2 << "-" << isbn.isbn3 << "-" << isbn.isbnX;

        return ss.str();
    }


    // 03 -  constructor initialiser list for Book class

    Book::Book(string i, string t, string a, int d, Genre g)
        :isbn{ i },
        title(t),
        author{ a },
        date{ d },
        genre{ g }
    {

    }

    // 03 -  availability function definition for Book class

    void Book::availability()
    {
        cout << "There are " << numCopies - numBorrowed << " copies of " << getTitle() << " available." << endl;

    }


    // 03 - bookLend function definition for Book class

    void Book::bookLend()
    {
        if (numBorrowed < numCopies)
        {
            numBorrowed++;
            cout << "One copy of " << getTitle() << " has been borrowed." << endl;
            availability();
        }
        else
        {
            cout << "All copies of " << getTitle() << " have been borrowed. " << endl;
        }
    }


    // 03 - bookReturn function definition for Book class

    void Book::bookReturn()
    {
        if (numBorrowed > 0)
        {
            numBorrowed--;
            cout << "One copy of " << getTitle() << " has been returned." << endl;
            availability();
        }
        else
        {
            cout << "No copies of " << getTitle() << " are currently lent out. " << endl;
        }
    }


    




    //-----------------------------------------------------------------------------------------------------
    // 
    // 04 - Global operator function for <<

    ostream& operator<<(ostream& os, const Book& add)
    {
        os << "ISBN No: " << add.isbn << '\n';
        os << "Book title: " << add.title << '\n';
        os << "Author: " << add.author << '\n';
        os << "Copyright Date: " << add.date << '\n';
        os << "Genre: " << add.genre << '\n';
        

        return os;
    }

    //  Global operator (requires all arguments) function for <<

    ostream& operator<<(ostream& os, Database& newBook)
    {
        for (Book i : newBook.records)
            os << i << endl;

        return os;
    }


    

    // Book class == operator - allows the use of == when comparing two Book class objects 

    bool operator==(const Book& a, const Book& b)
    {
        return a.RobsLibrary::Book::getISBN() == b.RobsLibrary::Book::getISBN();
    }

    // Book class != operator - allows the use of != when comparing two Book class objects

    bool operator!=(const Book& a, const Book& b)
    {
        return !(a==b);
    }

    // get genre info 

    ostream& operator<<(ostream& os, const Genre& genre)
    {
        switch (genre)
        {
        case Genre::fiction: cout << "Fiction\n";
            break;
        case Genre::nonfiction: cout << "Nonfiction\n";
            break;
        case Genre::periodical: cout << "Periodical\n";
            break;
        case Genre::biography: cout << "Biography\n";
            break;
        case Genre::childrens: cout << "Childrens\n";
            break;
        default: cout << "No such genre! \n";

        }
        return os;

    };





}








