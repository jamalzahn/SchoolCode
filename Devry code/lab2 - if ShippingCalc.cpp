#include <iostream>

using namespace std;

void main()
{
	double totAmnt, shipping;

	cout << "Enter total purchace amount: ";

	cin >> totAmnt;

	if (totAmnt > 5000)
	{
		shipping = 20;
	}
	else if (totAmnt > 1000)
	{
		shipping = 15;
	}
	else if (totAmnt > 500)
	{
		shipping = 10;
	}
	else if (totAmnt > 250)
	{
		shipping = 8;
	}
	else if (totAmnt > 0)
	{
		shipping = 5;
	}
	else //sale amount is 0 or negative
	{
		shipping = 0;
	}

	if (shipping == 0)
	{
		cout << "\nInvalid sale amount entered.\n";
	}
	else
	{
		cout << "\nSale Amount: $" << totAmnt << "\nShipping Amount: $" << shipping << endl;
	}

	system("pause");
}