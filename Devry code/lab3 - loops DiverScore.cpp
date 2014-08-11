#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void main()
{
	string dName;
	string dCity;
	double score, dod;
	double diverTotScore = 0;
	double highScore = 0;
	double avgDiveScore = 0;
	double lowScore = 10;
	char moreDivers = 'y';
	int numDivers = 0;
	
	cout << "Diver Scoring Program" << endl;

	while (moreDivers == 'y' || moreDivers == 'Y')
	{	
		fflush(stdin);//flush input to use getline()
		cout << "\nEnter diver's name: ";
		getline(cin, dName);
		cout << "Enter diver's city: ";
		getline(cin, dCity);

		for (int judge = 1; judge <= 5; judge++)//judge control
		{
			do
			{
				cout << "\nEnter score for judge " << judge << ": ";
				cin >> score;
				if (score < 0 || score > 10)//check value
				{
					cout << "\nPlease enter a number between 0 and 10";
				}
			}while (score < 0 || score > 10);

			diverTotScore += score;
			if (score < lowScore) { lowScore = score; }
			if (score > highScore) { highScore = score; }
		}
		do
		{
			cout << "\nEnter diver's degre of dificulty: ";
			cin >> dod;
			if (dod < 0 || dod > 1.67)
			{
				cout << "\nPlease enter a number between 0 and 1.67.";
			}
		}while (dod < 0 || dod > 1.67);

		diverTotScore = (diverTotScore - highScore - lowScore) / 3;

		cout << "\n" << dName << "\n" << dCity << "\nDiver Score: " << diverTotScore;
		
		avgDiveScore += diverTotScore;//add diver's score to total
		numDivers++;

		cout << "\nEnter another diver? (y/n): ";
		cin >> moreDivers;
	}
	cout << "\nAverage score for all divers: " << avgDiveScore / numDivers << endl;

	system("pause");
}
