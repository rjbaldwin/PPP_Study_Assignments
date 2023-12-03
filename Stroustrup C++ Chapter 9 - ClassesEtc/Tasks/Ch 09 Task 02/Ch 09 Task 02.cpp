// Ch 09 Task 02.cpp 
// written by Robert J Baldwin 22 Feb 2023
//
/* Design and implement a Name_pairs class holding (name,age) pairs where name is a string and age is a double.
Represent that as a vector<string> (called name) and a vector<double> (called age) member. 
Provide an input operation read_names() that reads a series of names. 
Provide a read_ages() operation that prompts the user for an age for each name. 
Provide a print() operation that prints out the (name[i],age[i]) pairs (one per line) in the order
determined by the name vector. 
Provide a sort() operation that sorts the name vector in alphabetical order and reorganizes the age vector to match. 
Implement all “operations” as member functions. 
Test the class (of course: test early
and often).*/



#include <iostream>
#include<vector>
#include "E:\06_Programming Work\Stroustrup C++ Chapter Exercises\PPP-chapter-tasks\std_lib_facilities.h"


        //  class definition for NamePairs
class NamePairs
{
public:

    // Default constructor
    NamePairs();

         
    
    // Accessor Functions: 

    void readNames();
    void readAges();
    void print();
    void sorting();
    
    
private:
    
    // Member variables:  These are retrieved by the accessor functions
    vector<string>vNames;
    vector<double>vAges;


};

//**********************************************************************************************

        // Function Declarations:

// Default Constructor

NamePairs::NamePairs()
{
    
}



// Member Functions 

void NamePairs::readNames() 
{
    string nn{};
    int userNo{};
    int counter{1};
    cout << "Enter number of entries to store: " << endl;
    cin >> userNo;

    for (int i = 0; i < userNo; ++i) {
        cout << "Enter name " << counter << " :" << endl;
        ++counter;
        cin >> nn;

        vNames.push_back(nn);
    }

}

void NamePairs::readAges()
{
    int aa{};
    int counter{ 1 };
    
    for (int i = 0; i < vNames.size(); ++i) {
        cout << "Enter age of person " << counter << " :" << endl;
        ++counter;
        cin >> aa;

        vAges.push_back(aa);
    }


}

void NamePairs::print()
{
    cout << "Unsorted names in the database: \n";
    for (int i = 0; i < vNames.size(); ++i) {
        cout << "(Name: " << NamePairs::vNames[i] << ", Age: " << NamePairs::vAges[i]<<')' << endl;
        
    }

    

}

void NamePairs::sorting()
{

    //copy the vectors

    vector<string>nameCopy = vNames;
    vector<double>ageCopy = vAges;

    //cout << "Copied pairs: \n";
    //for (int i = 0; i < nameCopy.size(); ++i) {
    //    cout << nameCopy[i] << " " << ageCopy[i] << '\n';
    //}
    ////------------------------------------------------------

    // Sorted name

    sort(vNames.begin(), vNames.end());

  
    for (int i = 0; i < vNames.size(); ++i) {
        for (int j = 0; j < vNames.size(); ++j) {
            if (vNames[i] == nameCopy[j]) {
                vAges[i] = ageCopy[j];
                break;
            }
        }

    }
    cout << "//**************************************************************\n";

    cout << "Sorted pairs: \n";
    for (int i = 0; i < vNames.size(); ++i) {
        
            cout << vNames[i] << " " << vAges[i] << '\n';
    }
}


//**********************************************************************************************

int main()
try{
    NamePairs np;
    np.readNames();
    np.readAges();
    np.print();
    np.sorting();

}
catch (exception& e) {
    cerr << e.what();
}
catch (...) {
    cerr << "Fuck you error!\n";
}

