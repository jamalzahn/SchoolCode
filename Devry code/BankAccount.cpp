#include <iostream>
#include "BankAccount.h"
#include <iomanip>

using namespace std;
	
	double balance;

	BankAccount::BankAccount()
	{
		balance = 2439.45;
	}
	void BankAccount::checkBalance()
	{
		cout << "\nCurrent balance is : $" << fixed << showpoint << setprecision(2) << balance << endl;
	}
	void BankAccount::makeWithdraw()
	{
		double amnt;
		cout << "\nHow much would you like to withdraw?  ";
		cin >> amnt;
		if(amnt > balance)
		{
			cout << "\nInsufficient funds." << endl;
		}
		else
		{
			balance -= amnt;
		}
		checkBalance();
	}
	void BankAccount::makeDeposit()
	{
		double amnt;
		cout << "\nHow much would you like to deposit?  ";
		cin >> amnt;
		balance += amnt;
		checkBalance();
	}
	void BankAccount::printAccount()
	{
		cout << "\nName: Jason Malzahn" <<
				"\nAccount Number: 1234554321" << endl;
	}
	void BankAccount::printStatment()
	{
		cout << "\n01/01/11 - McDonald’s - $6.270" <<
				"\n1/15/11 - Kwik Trip - $34.93" <<
				"\n02/28/11 - Target - $124.21" << endl;
	}
	void BankAccount::printBankInfo()
	{
		cout << "\nDevry Bank, established 2011" <<
				"\n(123) 456-7890" <<
				"\n12345 1st St." <<
				"\nSomeplace, NJ 12345" << endl;
	}
