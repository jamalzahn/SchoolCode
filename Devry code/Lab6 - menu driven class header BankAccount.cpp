#include "BankAccount.h"
#include <iostream>

using namespace std;

void main()
{
	BankAccount atm;
	int input;

	cout << "Welcome, What would you like to do?";
	do
	{
		//show menu
		 cout << "\n1) Check Balance" <<
				"\n2) Make Withdraw" <<
				"\n3) Make Deposit" <<
				"\n4) Display Account Info" <<
				"\n5) Display Transaction History" <<
				"\n6) Display Bank Info" <<
				"\n7) Quit" << endl;
		//read in selection
		cin >> input;

		switch(input)
		{
		case 1: atm.checkBalance(); break;
		case 2: atm.makeWithdraw(); break;
		case 3: atm.makeDeposit(); break;
		case 4: atm.printAccount(); break;
		case 5: atm.printStatment(); break;
		case 6: atm.printBankInfo(); break;
		case 7: cout << "Thank you for using our ATM" << endl; break;
		default: cout << "\nInvalid selection." << endl;
		}
	}while(input != 7);
	system("pause");
}
