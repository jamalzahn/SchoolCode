#include "RolodexEntry.h"
#include <iostream>

using namespace std;

void RolodexEntry::printEntry()
{
    cout << "\nName: " << fName << " " << lName;
    cout << "\nAddress: " << street <<
                        "\n" << town << ", " <<
                        state << ' ';
                        if(zip != 0)
                        {
                            cout << zip;
                        }
                        else
                        {
                            cout << szip;
                        }
    cout << "\nPhone: (" << area << ')' << exchange << '-' << line << "\n";
}
void RolodexEntry::readIn()
{
    cout << "\nEnter new contact's first name:\n";
    cin >> fName;
    cout << "\nEnter new contacts's last name:\n";
    cin >> lName;
    cout << "\nEnter new contacts's address (number and street):\n";
    cout.flush();
    if (cin.peek() == '\n')
    {
        cin.ignore();
    }
    getline(cin, street);

    cout << "\nEnter new contacts's town:\n";
    cout.flush();
    if (cin.peek() == '\n')
    {
        cin.ignore();
    }
    getline(cin, town);

    cout << "\nEnter new contacts's state:\n";
    cout.flush();
    if (cin.peek() == '\n')
    {
        cin.ignore();
    }
    getline(cin, state);

    cout << "\nEnter new contacts's zipcode:\n";
    long tempZip;
    cin >> tempZip;
    if(tempZip > 99999)//long zip
    {
        zip = tempZip;
        setSZipLong();//finds szip from long zip
    }
    else
    {
        szip = tempZip;
    }
    cout << "\nEnter new contacts's phone number (separated by spaces):\n";
    cin >> area >> exchange >> line;
    cout << "\nEnter new contacts's email:\n";
    cin >> email;
}

