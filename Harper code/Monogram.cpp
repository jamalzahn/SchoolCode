#include <iostream>
#include <cctype>
#include <climits>
//level 2.5
using namespace std;
int main(void)
{
    char first, middle, last, t;
    bool isRunning = true;

    while(isRunning == true)
    {
        first = '\0';
        middle = '\0';
        last = '\0';
        cout << "\t\tMonogram Layout Program"
             << "\n\nEnter your initials: ";

        while(first == '\0')
        {
            cin >> ws;
            t = cin.peek();
            if(isalpha(t))
            {
                first = t;
            }
            cin.ignore();
        }
        while(middle == '\0')
        {
            cin >> ws;
            t = cin.peek();
            if(isalpha(t))
            {
                middle = t;
            }
            cin.ignore();
        }
        while(last == '\0')
        {
            cin >> ws;
            t = cin.peek();
            if(isalpha(t))
            {
                last = t;
            }
            cin.ignore();
        }

        cout << "\nYour monogram is: \n" << static_cast<char>(toupper(middle)) << "." <<
                static_cast<char>(tolower(first)) << "." << static_cast<char>(toupper(last)) << ".\n";


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
