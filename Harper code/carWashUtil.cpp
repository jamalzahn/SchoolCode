#include "carWashUtil.h"
#include <iostream>
#include <cctype>
#include <climits>
#include <ctime>
#include <cstdlib>

using namespace std;

long genCode()
{
    long code = 0;
    for(long i = 1; i < 100000; i *= 10)
    {
        code += (1 + rand() % 10) * i;
    }
    code += ((1 + rand() % 9) + 1) * 1000000;//generate random digit, not 0
    return code;
}
void printCode()
{
    cout << "Your wash code is " << genCode() << ".";
}
void runProgram(char c)//takes input and runs
{
    bool isRunning = true;
    char t;

    if(tolower(c) == 'y')
    {
        while (isRunning)
        {
            getPrice();

            cout << "\nIs this OK?\n";
            cin >> t;
            cin.ignore(INT_MAX, '\n');

            if(tolower(t) == 'y')
            {
                isRunning = false;
            }
        }
        printCode();
    }
    return;
}
void getPrice()//prints choice header, handles selection and prints baised on sel
{
    const double super = 5.00;
    const double premium = 6.00;
    const double ultra = 8.00;
    bool isRunning = true;
    char s;

    while (isRunning)
    {
        cout << "\nPlease choose between Super, Premium or Ultra wash:\n";
        cin >> s;
        cin.ignore(INT_MAX, '\n');

        s = tolower(s);
        switch(s)
        {
            case's':
            {
                cout << "\nYour wash will cost $" << super;
                isRunning = false;
                break;
            }
            case'p':
            {
                cout << "\nYour wash will cost $" << premium;
                isRunning = false;
                break;
            }
            case 'u':
            {
                cout << "\nYour wash will cost $" << ultra;
                isRunning = false;
                break;
            }
            default:
            {
                cout << "Invalid selection. Use s, p, or u.";
                break;
            }
        }
    }
    return;
}
