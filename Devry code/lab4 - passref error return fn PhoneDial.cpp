#include <iostream>
#include <string>

using namespace std;

int readDials(char &p1, char &p2, char &p3, char &p4, char &p5, char &p6, char &p7, char &p8);
int toDigit(char &digit);
void printDigit(char &p1, char &p2, char &p3, char &p4, char &p5, char &p6, char &p7, char &p8);

void main()
{
	string input;
	char p1, p2, p3, p4, p5, p6, p7, p8;
	bool isRunning = true;
	while (isRunning)
	{
		int error = readDials(p1, p2, p3, p4, p5, p6, p7, p8);
		if (error == -5)
		{
			isRunning = false;
		}
		else if (error == -1)
		{
			cout << "\nAn invalid character was entered\n";
		}
		else if (error == -2)
		{
			cout << "\nPhone number cannot start with 0\n";
		}
		else if (error == -3)
		{
			cout << "\nPhone number can not begin with 555\n";
		}
		else if (error == -4)
		{
			cout << "\nHyphen is in the wrong position\n";
		}
		else
		{
			printDigit(p1, p2, p3, p4, p5, p6, p7, p8);
		}
	}
}
int readDials(char &p1, char &p2, char &p3, char &p4, char &p5, char &p6, char &p7, char &p8)
{
	cout << "\nPlease enter a phone number in xxx-xxxx format (include -).\nType 'Q' to quit\n";
	cin >> p1;
		if (p1 == 'Q')
	{
		return -5;
	}
	cin >> p2 >> p3 >> p4 >> p5 >> p6 >> p7 >> p8;

	if (toDigit(p1) == -1)
	{
		return -1;
	}
	if (toDigit(p2) == -1)
	{
		return -1;
	}
	if (toDigit(p3) == -1)
	{
		return -1;
	}
	if (p4 != '-')
	{
		return -4;
	}
	if (toDigit(p5) == -1)
	{
		return -1;
	}
	if (toDigit(p6) == -1)
	{
		return -1;
	}
	if (toDigit(p7) == -1)
	{
		return -1;
	}
	if (toDigit(p8) == -1)
	{
		return -1;
	}

	if (p1 == '0')
	{
		return -2;
	}

	if (p1 == '5' && p2 == '5' && p3 == '5')
	{
		return -3;
	}

	return 0;
}
//return -1 if not digit or alpha, else 0. changes char value to digit by reference.
int toDigit(char &digit)
{
	digit = tolower(digit);
	switch (digit)
	{
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	{
		return 0;
	}
	case 'a':
	case 'b':
	case 'c':
		digit = '2';
		return 0;
	case 'd':
	case 'e':
	case 'f':
	{
		digit = '3';
		return 0;
	}
	case 'g':
	case 'h':
	case 'i':
	{
		digit = '4';
		return 0;
	}
	case 'j':
	case 'k':
	case 'l':
	{
		digit = '5';
		return 0;
	}
	case 'm':
	case 'n':
	case 'o':
	{
		digit = '6';
		return 0;
	}
	case 'p':
	case 'q':
	case 'r':
	case 's':
	{
		digit = '7';
		return 0;
	}
	case 't':
	case 'u':
	case 'v':
	{
		digit = '8';
		return 0;
	}
	case 'w':
	case 'x':
	case 'y':
	case 'z':
	{
		digit = '9';
		return 0;
	}
	default:
	{
		return -1;
	}
	}
}
void printDigit(char &p1, char &p2, char &p3, char &p4, char &p5, char &p6, char &p7, char &p8)
{
	cout << "You dialed: " << p1 << p2 << p3 << p4 << p5 << p6 << p7 << p8 << '\n';
}
