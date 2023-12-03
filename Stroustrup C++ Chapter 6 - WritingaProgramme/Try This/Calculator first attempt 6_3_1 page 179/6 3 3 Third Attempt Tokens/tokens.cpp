// 6_3_3 From page 183 of PPP - 12 Dec 2022 RJ Baldwin
//

#include <iostream>
#include "std_lib_facilities.h"

class Token {
public:
	char kind;
	double value;
};                                                          


int main()

{

	Token get_token();
	vector<Token>tok;

	while (cin) {
		Token t = get_token();
		tok.push_back(t);

	}
	for (int i = 0; i < tok.size(); ++i) {
		if (tok[i].kind == '*') {
			double d = tok[i - 1].value * tok[i + 1].value;

		}
	}
}
