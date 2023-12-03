/*
TASK 05:

DONE - This exercise and the next few require you to design and implement a Book class, such as you can imagine as part of
software for a library.

DONE - Class Book should have members for the ISBN, title, author, and copyright date.

DONE - Also store data on whether or not the book is checked out.

DONE - Create functions for returning those data values.

DONE - Create functions for checking a book in and out.

Do simple validation of data entered into a Book; for example, accept ISBNs only of the form n-n-nx where n is an integer and x is a digit or a letter.

DONE - Store an ISBN as a string.*/


// Written by Robert J Baldwin 27/02/2023






// class definition for Book

#include "E:\06_Programming Work\Stroustrup C++ Chapter Exercises\PPP-chapter-tasks\std_lib_facilities.h"

class Book
{
public:

    // default constructor

    Book();
     
    // constructor
    Book(string i, string t, string a, int d);

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

private:

    string isbn{};
    string title{};
    string author{};
    int date{};
    int numCopies{2};       // initial stock amount
    int numBorrowed{};


};

//--------------------------------------------------------------


// ****** function definitions ******


    // constructor definition

Book::Book(string i, string t, string a, int d)
    :isbn{ i },
    title(t),
    author{ a },
    date{ d }
{
  
}


// availability function definition

void Book::availability() 
{
    cout << "There are " << numCopies - numBorrowed << " copies of " << getTitle() << " available." << endl;

}


// bookLend function definition

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


// bookReturn function definition

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

//--------------------------------------------------------------





//  Global operator function for <<

ostream& operator<<(ostream& os, const Book& add)
{
    os << "ISBN No: " << add.isbn << '\n';
    os << "Book title: " << add.title << '\n';
    os << "Author: " << add.author << '\n';
    os << "Copyright Date: " << add.date << '\n';

    return os;
}

//--------------------------------------------------------------


//  Class definition for Database vector 

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

//--------------------------------------------------------------

//  Global operator (requires all arguments) function for <<

ostream& operator<<(ostream& os, Database& newBook)
{
    for (Book i : newBook.records)
        os << i << std::endl;

    return os;
}



//--------------------------------------------------------------

// ISBN Validation function 

string ISBNvalidation(int n1, int n2, int n3, char c1)
{
    int num1{ n1 };
    int num2{ n2 };
    int num3{ n3 };
    char letter2{ c1 };
    char hyphen{ '-' };

    stringstream ss;

    ss << num1;
    ss << hyphen;
    ss << num2;
    ss << hyphen;
    ss << num3;
    ss << hyphen;
    ss << letter2;


    string result = ss.str();

    return result;

}

//--------------------------------------------------------------
