#include "carWashUtil.h"
#include <iostream>
#include <cctype>
#include <climits>
#include <ctime>
#include <cstdlib>
//level 5.5
using namespace std;

int main(void)
{
    char c;
    srand(time(NULL));

    cout << "Welcome to my gas station.\n";
    cout <<"Would you like a car wash?\n";
    cin >> c;
    cin.ignore(INT_MAX, '\n');

    runProgram(c);

    return 0;
}
