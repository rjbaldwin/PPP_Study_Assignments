// Drill 2.cpp : 02/02/2023 R J Baldwin

#include <iostream>
#include "std_lib_facilities.h";

void swap_v(int a, int b) {     // pass value
    
    
    int temp = a; 
    a = b;
    b = temp;

}

//------------------------------------------------------------

void swap_r(double& a, double& b) {   // Pass-by-reference 
    double temp = a;
    a = b;
    b = temp;
}

//------------------------------------------------------------


/*
void swap_cr(const int& a, const int& b) {      //pass-by-const-reference 
    int a;
    int b;
    int temp = a;
    a = b;
    b = temp;
}
*/


int main()
{
    int x = 7;
    int y = 9;

  
    //swap_v(x, y);
    //swap_r(7, 9);   //needs to be a variable, not a literal
    //swap_r(x, y);
    const int cx = 7;
    const int cy = 9;
    //swap_cr(cx, cy);
   // swap_cr(7.7, 9.9);  //truncated - takes an int
    double dx = 7.7;        // no function takes double.  I'll have to define a new double function
    double dy = 9.9;
   // swap_r(dx, dy);     //takes int
    //swap_r(7.7, 9.9);   //takes int variable and not literal 



    //cout << "Swap_v function call \n";
   // cout << "x == " << x <<" y == "<< y << '\n';
    //swap_v(x,y);
    //cout << "x == " << x << " y == " << y << '\n';

    //cout << "Swap_r function call \n";
    //cout << "x == " << x << " y == " << y << '\n';
    swap_r(dx, dy);
    //cout << "x == " << x << " y == " << y << '\n';
    //swap_cr(cx, cy);
    cout << "dx " << dx << " dy " << dy << '\n';
}

