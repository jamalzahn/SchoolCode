#include <iostream>
#include <string>

using namespace std;

int inputData(string players[], int scores[], int size);
void printData(string players[], int scores[], int numPlayers);
void printAvg(string players[], int scores[], int numPlayers);
int calcAvg(int scores[], int numScores);

void main()
{
	string players[100];
	int scores[100];
	int numPlayers = 0;


	numPlayers = inputData(players, scores, 100);
	cout << "\n";
	printData(players, scores, numPlayers);
	cout << "\n";
	printAvg(players, scores, numPlayers);

	system("pause");
}
int inputData(string players[], int scores[], int size)
{
	int numPlayers = 0;
	while (numPlayers < size)
	{
		cout << "Enter player name: \t";
		cin >> players[numPlayers];

		if (players[numPlayers] == "Q" || players[numPlayers] == "q")
		{
			return numPlayers;
		}
		cout << "Enter score for " << players[numPlayers] << ": \t";
		cin >> scores[numPlayers];

		numPlayers++;
	}
	return numPlayers;
}
void printData(string players[], int scores[], int numPlayers)
{
	cout << "Player\tScore\n";
	for (int i = 0; i < numPlayers; i++)
	{
		cout << players[i] << "\t" << scores[i] << "\n";
	}
}
void printAvg(string players[], int scores[], int numPlayers)
{
	double avg = calcAvg(scores, numPlayers);
	cout << "Average Score: " << avg << "\n";
	cout << "\nScores below average: \nPlayer\tScore\n";

	for (int i = 0; i < numPlayers; i++)
	{
		if (scores[i] < avg)
		{
			cout << players[i] << "\t" << scores[i] << "\n";
		}
	}
}
int calcAvg(int scores[], int numScores)
{
	int total = 0;
	for (int i = 0; i < numScores; i++)
	{
		total += scores[i];
	}
	return total / numScores;
}