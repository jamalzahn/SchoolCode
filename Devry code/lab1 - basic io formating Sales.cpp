#include <iostream>
#include <iomanip>
//commit test
using namespace std;

void main()
{
	double wklySales;
	double grossPay;
	double fedTax;
	double socSec;
	double retCon;
	double totDeduc;

	cout << "Enter weekly sales: ";
	cin >> wklySales;

	grossPay = wklySales * .7;
	fedTax = grossPay * .18;
	socSec = grossPay * .06;
	retCon = grossPay *.1;
	totDeduc = fedTax + socSec + retCon;

	cout << fixed << setprecision(2);

	cout << "Total Sales: \t $" << setw(8) << wklySales;
	cout << "\nGross Pay: \t $" << setw(8) << grossPay;
	cout << "\nFederal Tax: \t $" << setw(8) << fedTax;
	cout << "\nSocial Security paid: \t $" << setw(8) << socSec;
	cout << "\nRetirement Contribution: \t $" << setw(8) << retCon;
	cout << "\nTotal Deductions: \t $" << setw(8) << totDeduc;
	cout << "\nTake-home Pay: \t $" << setw(8) << grossPay - totDeduc;

	system("pause");
}
