// converts dollars, yen, and euro into pounds
//

#include "std_lib_facilities.h"

int main()
{
	constexpr double pound_per_dollar = 0.8676841;	//0.867 pound in a dollar
	constexpr double pound_per_euro = 0.868022;		//0.868 pound in a euro  
	constexpr double pound_per_yen = 0.00601714;	//0.00601714 pound in a yen

	double amount = 1;

	char currency = ' ';
	cout << "Please enter an amount followed by a currency type (d, e, y or p):\n";
	cin >> amount >> currency;

	if (currency == 'd')
		cout << amount << " dollar == " << pound_per_dollar * amount << " GBP\n";
	
	else if (currency == 'e')
		cout << amount << " euro == " << pound_per_euro * amount << " GBP\n";
	
	else if (currency == 'y')
		cout << amount << " yen == " << pound_per_yen * amount << " GBP\n";
	else if (currency == 'p')
		cout << amount << " pound == " << amount / pound_per_yen << " JPY\n" << amount / pound_per_dollar << " USD\n" << amount / pound_per_euro << " EUR\n";

	else

		cout << "Sorry, I don't know a currency called " << currency << "\n";


}