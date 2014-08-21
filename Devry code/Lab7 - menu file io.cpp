#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void menu(void);
void writeData(void);
void readData(void);
string * split(string, char);

const char FileName[] = "TestAddress.txt";
int main()
{
	cout << "Welcome to the Address Book\n\n";
	menu();
	system("pause");
	return 0;
} //end main
void menu(void)
{
	char loop = 'y';
	do
	{
		cout << "\nWhat would you like to do ?";
		cout << "\n1 Append records";
		cout << "\n2 Display records";
		cout << "\n3 Exit\n";
		cin >> loop;

		loop = tolower(loop);
		switch (loop)
		{
		case 'a':
		case '1':
			cout << "\nEnter data\n";
			writeData();
			break;
		case 'd':
		case '2':
			readData();
			break;
		case 'e':
		case 'q':
		case '3':
			loop = 'n';
			break;
		default:
			cout << "Ivalid Selection";
		}

	} while (loop != 'n');
}//end menu
void writeData(void)
{
	ofstream out;
	out.open("testAddress.txt",ios::app);
	if (out.is_open())
	{
		string name, address, city, state, zip;

		fflush(stdin);

		cout << "\nName: ";
		getline(cin, name);
		cout << "\nStreet: ";
		getline(cin, address);
		cout << "\nCity: ";
		getline(cin, city);
		cout << "\nState: ";
		getline(cin, state);
		cout << "\nZip Code: ";
		getline(cin, zip);

		out << name << ",";
		out << address << ",";
		out << city << ",";
		out << state << ",";
		out << zip;
		out << endl;

		out.close();
	}
}
void readData(void)
{
	ifstream inFile;
	inFile.open(FileName);
	if (!inFile.is_open())
	{
		cout << "\nError opening file.";
		return;
	}
	while (!inFile.eof())
	{
		string input;
		getline(inFile, input);
		if (input.length() > 0)
		{
			string *output = split(input, ',');

			cout << "Name: " << output[0] << endl;
			cout << "Street: " << output[1] << endl;
			cout << "City: " << output[2] << endl;
			cout << "State: " << output[3] << endl;
			cout << "Zip Code: " << output[4] << endl << endl;
		}
	}
	inFile.close();
}//end read data
string * split(string theLine, char theDeliminator)
{
	//Break theline into fields and save the fields to an array.
	//Each field will occupy one element in a character array.
	//theLine is a string with fields separated with theDeliminator character.
	//Assumes the last field in the string is terminated with a newline.
	//Useage: string *theFields = split(lineBuffer, ',');

	//determine how many splits there will be so we can size our array
	int splitCount = 0;
	for (int i = 0; i < theLine.size(); i++)
	{
		if (theLine[i] == theDeliminator)
			splitCount++;
	}
	splitCount++; //add one more to the count because there is not an ending comma 
	//create an array to hold the fields
	string* theFieldArray;
	theFieldArray = new string[splitCount];
	//split the string into seperate fields
	string theField = "";
	int commaCount = 0;

	for (int i = 0; i < theLine.size(); i++)
	{ //read each character and look for the deliminator
		if (theLine[i] != theDeliminator)
		{
			theField += theLine[i]; //build the field
		}
		else
		{ //the deliminator was hit so save to the field to the array
			theFieldArray[commaCount] = theField; //save the field to the array
			theField = "";
			commaCount++;
		}
	}
	theFieldArray[commaCount] = theField; //the last field is not marked with a comma...

	return theFieldArray;
} //end split