// Chapter 4 task 17 Quadratic.cpp : RJ Baldwin 15 Nov 2022
//

#include <iostream>
#include <complex>
#include <cmath>

using namespace std;

int main()
{
    
    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0; 
    double sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, sum5 = 0, ans1 = 0, ans2 = 0;

    cout << "**Quadratic equation calculator v1.0**\n";
    cout << "Enter coefficients a, b, and c\n";
    
    cin >> a >> b >> c;
    

    sum1 = 4 * a * c;
    sum2 = b * b;
    sum3 = sum2 - sum1;     //Discriminant 
    sum4 = sqrt(sum3);
    ans1 = -b + sum4;
    ans2 = -b - sum4;
    sum5 = 2 * a;
    x1 = ans1 / sum5;
    x2 = ans2 / sum5;
    cout << "Two solutions: x1 = " << x1 << endl;
    cout << "               x2 = " << x2 << endl;


    system("pause");
    return 0;

}




