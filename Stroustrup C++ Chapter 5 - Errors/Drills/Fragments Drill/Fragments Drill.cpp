// Fragments Drill.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "std_lib_facilities.h"

using namespace std;

int main()
try {
	
	cout << "Success!\n";						//01 Cout << "Success!\n";
	cout << "Success!\n";						//02 cout<<"Success!\n;
	cout << "Success" << "!\n";					//03 cout<<"Success"<<!\n"
	cout << "Success!" << '\n';					//04 cout << success << '\n';

	int res = 7; vector<int>v(10); v[5] = res; cout << "Success!\n";	//05 string res = 7; vector<int>v(10); v[5] = res; cout << "Success!\n";

	vector<int> v1(10); 
	v1[5] = 7; 
	if (v1[5] == 7)
		cout << "Success!\n";											//06 vector<int> v(10); v(5) = 7; if (v(5)!=7) cout<<"Success!\n";

	if (v1[5] == 7) cout << "success!\n"; else cout << "Fail!\n";				//07 if (cond) cout << "success!\n"; else cout << "Fail!\n";

	bool c = true; if (c) cout << "Success!\n"; else cout << "Fail!\n";		//08 bool c = false; if (c) cout << "Success!\n"; else cout << "Fail!\n";

	string s = "ape"; bool d = "fool" > s; if (d) cout << "Success!\n";		//09 string s = "ape"; bool c = "fool" < s; if (c) cout << "Success!\n";

	string s2 = "ape"; if (s2 != "fool") cout << "10 Success!\n";				//10 string s = "ape"; if (s=="fool") cout << "Success!\n";

	string s3 = "ape"; if (s3 != "fool") cout << "11 Success!\n";					//11 string s = "ape"; if (s=="fool") cout < "Success!\n";

	string s4 = "ape"; if (s4 != "fool") cout << "12 Success!\n";							//12 string s = "ape"; if (s+"fool") cout < "Success!\n";

	vector<char> f(5); for (int i = 0; i < f.size(); ++i); cout << "13 Success!\n";			//13 vector<char> v(5); for (int i=0; 0<v.size(); ++i) ; cout << "Success!\n";

	vector<char> v2(5); for (int i = 0; i < v2.size(); ++i); cout << "14 Success!\n";			//14 vector<char> v(5); for (int i=0; i<=v.size(); ++i) ; cout << "Success!\n";

	string s5 = "15 Success!\n"; for (int i = 0; i < 1; ++i) cout << s5;							//15 string s = "Success!\n"; for (int i=0; i<6; ++i) cout << s[i];

	if (true) cout << "Success!\n"; else cout << "Fail!\n";									//16 if (true) then cout << "Success!\n"; else cout << "Fail!\n";

	int x = 2000; int y = x; if (y == 2000) cout << "17 Success!\n";							//17 int x = 2000; char c = x; if (c==2000) cout << "Success!\n";
	
	string s6 = "Success!\n"; for (int i = 0; i < 10; ++i) cout << s6[i];							//18 string s = "Success!\n"; for (int i=0; i<10; ++i) cout << s[i];

	vector<int>v3(5); for (int i = 0; i <= v3.size(); ++i); cout << "19 Success!\n";							//19 vector v(5); for (int i=0; i<=v.size(); ++i) ; cout << "Success!\n";

	int i = 0; int j = 9; while (i < 10) ++i; if (j < i) cout << "Success!\n";								//20 int i=0; int j = 9; while (i<10) ++j; if (j<i) cout << "Success!\n";

	int i2 = 2; double d2 = 5 / (i2-1); if (d2 == 2 * i2 + 1.0) cout << "21 Success!\n";							//21 int x = 2; double d = 5/(x–2); if (d==2*x+0.5) cout << "Success!\n";

	string s7 = "22 Success!\n"; for (int i = 0; i < 10; ++i) cout << s7[i]; cout << '\n';										//22 string<char> s = "Success!\n"; for (int i=0; i<=10; ++i) cout << s[i];

	int temp = 4; double d3 = 5 / (temp - 2); if (d3 = 2 * x + 0.5) cout << "23 Success!\n";											//23 int x = 4; double d = 5/(x–2); if (d=2*x+0.5) cout << "Success!\n";

	int i3 = 0; while (i < 10) ++j; if (j < i) cout << "24 Success!\n";														//24 int i=0; while (i<10) ++j; if (j<i) cout << "Success!\n";

	cout << "25 Success!\n";																									//25  cin << "Success!\n";

		keep_window_open();
	return 0;
}

catch (exception& e) {
	cerr << "error: " << e.what() << '\n';
	keep_window_open();
	return 1;
}

catch (...) {
	cerr << "Oops: unknown exception!\n";
	keep_window_open();
	return 2;
}
