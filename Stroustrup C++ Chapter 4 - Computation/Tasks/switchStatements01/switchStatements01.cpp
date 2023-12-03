// converts dollars, yen, and euro into pounds
//

#include "std_lib_facilities.h"

int main()
{
	constexpr double pound_per_dollar = 0.8676841;	//0.867 pound in a dollar
	constexpr double pound_per_euro = 0.868022;		//0.868 pound in a euro  
	constexpr double pound_per_yen = 0.00601714;	//0.00601714 pound in a yen
	constexpr double pound_per_yuan = 0.12562523;	//0.12562523 pound in cny

	double amount = 1;								//enter amount of money to convert

	char currency = ' ';							//currency type 
	cout << "Please enter an amount followed by a currency type (d, e, y, c, or p):\n";
	cin >> amount >> currency;

	switch (currency) {
	case 'd':
		cout << amount << " dollar == " << pound_per_dollar * amount << " GBP\n";
		break;

	case 'e':
		cout << amount << " euro == " << pound_per_euro * amount << " GBP\n";
		break;
		
	case 'y':
		cout << amount << " yen == " << pound_per_yen * amount << " GBP\n";
		break;

	case 'p':
		cout << amount << " pound == " << amount / pound_per_yen << " JPY\n" << amount / pound_per_dollar << " USD\n" << amount / pound_per_euro << " EUR\n" << amount / pound_per_yuan << " CNY\n";
		break;

	case 'c':
		cout << amount << " yuan == " << pound_per_yuan * amount << " GBP\n";
		break;

	default:
		cout << "Sorry, I don't know a currency called " << currency << "\n";
	}






	

}