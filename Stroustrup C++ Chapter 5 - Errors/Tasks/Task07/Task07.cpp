#include <iostream>
#include <cmath>

using namespace std;


void quadratic(const double&a, const double& b, const double&c)
{
   

    double discriminant = (b * b) - (4 * a * c); //Discriminant - to do - handle negative numbers

    if (discriminant >= 0)
    { 
        // Calculate complex solutions using complex arithmetic
        double real_part_x1 = (-b + sqrt(discriminant)) / (2 * a);
        double real_part_x2 = (-b - sqrt(discriminant)) / (2 * a);


        cout << "Solution 1, x = " << real_part_x1 << endl;
        cout << "Solution 2, x = " << real_part_x2 << endl;
    }
    else
    {
        std::cout << "No real roots - Imaginary number!\n";
    }
   

    
}

int main()
{

    cout << "**Quadratic equation calculator v1.2**\n";
    cout << "Enter coefficients a, b, and c\n";

    double a{}, b{}, c{};
    cin >> a >> b >> c;

    quadratic(a, b, c);
    



}