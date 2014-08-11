#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <climits>
//level 5
using namespace std;

short calcMinVal(short numDice, short mod);
short calcMaxVal(short sides, short dice, short mod);
double calcAverageRoll(short min, short max, short dice, short mod);
short rollDice(short dice, short sides, short mod);
void printOpen(void);
void printClose(void);
void printDiceStat(short min, short max, double avg, short singleRoll);
void printUserRoll(short num, short sides, short mod);

int main(void)
{
    short numDice, numSides, modifier; //user inputs
    short minVal, maxVal, rollResult, singleRoll;
    double averageRoll; //calculated variables
    bool isRunning = true;

    while(isRunning == true)
    {
        srand(time(NULL));

        modifier = 0; //no modifier by default
        rollResult = 0;
        numDice = 1;
        numSides = 0;
        minVal = 0;
        maxVal = 0;
        averageRoll = 0;

        printOpen();

        //reading in
        while(cin.peek() != '\n')
        {
            while(cin.fail())
            {
                cin.clear();
                cin.ignore();
            }
            if(isdigit(cin.peek()))
            {
                cin >> numDice;
            }

            cin.ignore(); //ignore the d

            cin >> numSides;
            if(cin.peek() == '+' || cin.peek() == '-')
            {

                cin >> modifier;
            }
        }
        minVal = calcMinVal(numDice, modifier);
        maxVal = calcMaxVal(numSides, numDice, modifier);
        averageRoll = calcAverageRoll(minVal, maxVal, numDice, modifier);
        singleRoll = rollDice(numDice, numSides, modifier);

        printUserRoll(numDice, numSides, modifier);

        printDiceStat(minVal, maxVal, averageRoll, singleRoll);
        cout << "Would you like to roll another? (y/n): ";

        char c;
        cin >> c;
        cin.ignore(INT_MAX,'\n');
        if(tolower(c) != 'y')
        {
            isRunning = false;
        }
    }
    printClose();
    return 0;
}
short calcMinVal(short numDice, short mod)
{
    return numDice + mod;
}
short calcMaxVal(short sides, short dice, short mod)
{
    return sides * dice + mod;
}
double calcAverageRoll(short min, short max, short dice, short mod)
{
    return ((static_cast<double>(min) + static_cast<double>(max))
              / 2 * dice) + mod; //cleaner way to write this?
}
short rollDice(short dice, short sides, short mod)
{
    short roll = 0;
    for(short i = 0; i < dice; i++)
    {
        roll += 1 + rand() % sides; //simulates a die roll
    }
    roll += mod; //modifier is added at the end
    return roll;
}
void printOpen(void)
{
    cout << "\nWelcome the the Dice Rolling program" <<
            "\nEnter your roll in dice notation. (<rolls> d <sides> + modifier)" <<
            "\nex. 5d6+2" <<
            "\n\nYour roll: ";
    return;
}
void printClose(void)
{
    cout << "\nThank you for using the Dice Rolling Program.";
    return;
}
void printDiceStat(short min, short max, double avg, short singleRoll)
{
    cout << "Lowest possible value: " << min << "\n";
    cout << "Highest possible value: " << max << "\n";
    cout << "Average total value: " << avg << "\n";
    cout << "A typical roll would be: " << singleRoll << "\n";
    return;
}
void printUserRoll(short num, short sides, short mod)
{
    if (mod > 0)
    {
        cout << "\nYou are rolling " << num << "d" << sides << "+" << mod << "\n";
    }
    else if (mod < 0)
    {
        cout << "\nYou are rolling " << num << "d" << sides << mod << "\n";
    }
    else //if there is no modifier
    {
        cout << "\nYou are rolling " << num << "d" << sides << "\n";
    }
    return;
}
