#include <iostream>
#include <climits>
//level 8
using namespace std;

double calcMid(double p1, double p2);
void printResult(double midX, double midY);
void printPoint(double x, double y);
void calcMid(double x1, double y1, double x2, double y2, double & midX, double midY);
void calcMid(double x1, double y1, double x2, double y2, double z1, double z2, double & midX, double & midY, double & midZ);

int main(void)
{
    double x1,x2,y1,y2,midX,midY;
    bool isRunning = true;

    while(isRunning == true)
    {
        cout << "Welcome to the Midpoint Program" <<
                "\n\nEnter your first endpoint: ";
        cin >> x1 >> y1;

        cout << "\nEnter your second endpoint: ";
        cin >> x2 >> y2;

        midX = calcMid(x1,x2);
        midY = calcMid(y1,y2);

        printResult(midX,midY);

        cout << "\nRun again? (y/n)";
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
double calcMid(double p1, double p2)
{
    return (p1 + p2)/2;
}
void calcMid(double x1, double y1, double x2, double y2, double & midX, double midY)
{
    midX = calcMid(x1,x2);
    midY = calcMid(y1,y2);
    return;
}
void calcMid(double x1, double y1, double x2, double y2, double z1, double z2, double & midX, double & midY, double & midZ)
{
    calcMid(x1,y1,x2,y2,midX,midY);
    midZ = calcMid(z1,z2);
    return;
}
void printPoint(double x, double y)
{
    cout << "(" << x << "," << y << ")";
    return;
}
void printResult(double midX, double midY)
{
    cout << "\nThe midpoint is ";
    printPoint(midX, midY);
    cout << ".\n";
    return;
}
