

#include "std_lib_facilities.h" 
#include <iostream>

int main()
{
    //int i = 0;                                                                  //Initialize i to 0.
    //char c = 'a';
   
    //while (i < 26) {                                                            //26 letters in alphabet (0 to 25)
    //    cout << char(c+i) <<'\t' << int(c+i) <<'\n';                            //output char which is then incremented by the integer i
                                                                                //typecast char plus increment into integer giving th asci value        
    //    ++i;                                                                      //increment int i by 1


    char c = 'a';
    char cU = 'A';
    for (int i = 0;  i < 26; ++i)
        cout << char(c+i) <<'\t' << int(c+i) <<'\t' <<char(cU+i) <<'\t' << int(cU+i) << '\n';



          


    return 0;
}

