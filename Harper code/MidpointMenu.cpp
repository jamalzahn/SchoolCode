#include <iostream>
#include <climits>
#include <cmath>
//level 9
using namespace std;

double calcMid(double p1, double p2);
void calcMid(double x1, double y1, double x2, double y2, double & midX, double midY);
void calcMid(double x1, double y1, double x2, double y2, double z1, double z2, double & midX, double & midY, double & midZ);
void printPoint(double x, double y);
void printMidPt(double x, double y);
void getPoint(double & x, double & y, string pointNumber);

int main(void)
{

    double x1,x2,y1,y2,midX,midY;
    bool isRunning = true;

    while(isRunning == true)
    {
    cout << "Welcome to the Midpoint Program\n";

        getPoint(x1,y1,"first");
        getPoint(x2,y2,"second");

        calcMid(x1,y1,x2,y2,midX,midY);
        printMidPt(midX,midY);

        cout << "\nRun again? (y/n)\n";
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
void printMidPt(double midX, double midY)
{
    cout << "\nThe midpoint is ";
    printPoint(midX, midY);
    cout << ".\n";
    return;
}
// @pointNumber "first", "second", ect.
void getPoint(double & x, double & y, string pointNumber)
{
    cout << "Enter your " << pointNumber << " endpoint:\n";
    cin >> x >> y;
    return;
}
