#include <iostream>
#include <climits>
//level
using namespace std;
int main(void)
{
    double x1,x2,y1,y2;
    bool isRunning = true;

    while(isRunning == true)
    {
        cout << "Welcome to the Midpoint Program" <<
                "\n\nEnter your first endpoint: ";
        cin >> x1;

        cin >> y1;
        cout << "\nEnter your second endpoint: ";
        cin >> x2 >> y2;

        cout << "\nThe midpoint is (" << (x1 + x2)/2 << "," << (y1 + y2)/2 << ").\n";

        cout << "Run again? (y/n)";
        char c;
        cin >> c;
        cin.ignore(INT_MAX,'\n');
        if(tolower(c) != 'y')
        {
            isRunning = false;
        }

    }

    return 0;
}
short calcMid(short x1, short y1, short x2, short y2)
{

}
