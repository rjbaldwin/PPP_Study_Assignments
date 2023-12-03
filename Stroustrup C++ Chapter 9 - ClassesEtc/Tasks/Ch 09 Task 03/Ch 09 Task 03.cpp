// Ch 09 Task 03.cpp 
// written by Robert J Baldwin 27 Feb 2023
//
/* Replace Name_pair::print() with a (global) operator << and define == and != for Name_pairs. */



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
    void sorting();

    // Provides access to the private members for printing

    friend ostream& operator<<(ostream& COUT, const NamePairs& np);

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
    int counter{ 1 };
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



void NamePairs::sorting()
{

    //copy the vectors

    vector<string>nameCopy = vNames;
    vector<double>ageCopy = vAges;

  
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

// Output operator to print

ostream& operator<<(ostream& COUT, const NamePairs& np) {
    for (int i = 0; i < np.vNames.size(); ++i) {
        COUT << np.vNames[i] << ": " << np.vAges[i] << '\n';
    }
    return COUT;
}



//**********************************************************************************************

int main()
try {
    NamePairs np;
    np.readNames();
    np.readAges();
   
    cout << "Name pairs:\n" << np << '\n';
   // np.sorting();

}
catch (exception& e) {
    cerr << e.what();
}
catch (...) {
    cerr << "Oh no, error!\n";
}
