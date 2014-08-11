#include <iostream>
#include "RolodexEntry.h"
#include <vector>
#include <climits>
#include <cctype>

using namespace std;

//function dec
void printMainMenu();
void printEditMenu(vector<RolodexEntry> & list);
void editContactSub(const short c, vector<RolodexEntry> & list);
void printSearchMenu(vector<RolodexEntry> & list);
void printList(vector<RolodexEntry> & list);
void eraseEntry(vector<RolodexEntry> & list, short index);


int main(void)
{
    bool isRunning = true;
    vector<RolodexEntry> list;
    do
    {
        char c;
        printMainMenu();
        cin >> c;
        cin.ignore(INT_MAX, '\n');
        switch(tolower(c))
        {
        case '1': case 'a':
            {
                RolodexEntry newEntry;
                newEntry.readIn();
                list.push_back(newEntry);
                break;
            }
        case '2': case 'e':
            {
                printEditMenu(list);
                break;
            }
        case '3': case 'd':
            {
                printList(list);
                cout << "\nSelect Contact to delete:";
                if(cin.fail())
                {
                    cin.clear();
                    cin.ignore();
                }
                short c;
                cin >> c;

                eraseEntry(list, c-1);//resizes and moves back
                break;
            }
            case '4': case 's':
            {
                printSearchMenu(list);
                break;
            }
            case '5': case 'p':
                {
                    printList(list);
                    break;
                }
            case '6': case 'q':
                {
                    isRunning = false;
                    break;
                }
            default:
            {
                cout << "Invalid selection.";
                break;
            }
        }
    }while(isRunning);

    return 0;
}
void printMainMenu()
{
    cout << "\nMain Menu\n\n"
         << "1. Add contact\n"
         << "2. Edit contact\n"
         << "3. Delete contact\n"
         << "4. Search contacts\n"
         << "5. Print all contacts\n"
         << "6. Quit\n";
    return;
}
void printEditMenu(vector<RolodexEntry> & list)
{
    cout << "\n\n";
    printList(list);
    cout << "\nSelect Contact to edit:";//read in choice
    if(cin.fail())
    {
        cin.clear();
        cin.ignore();
    }
    short c;
    cin >> c;
    cin.ignore(INT_MAX, '\n');
    editContactSub(c, list);
    return;
}
void editContactSub(const short c, vector<RolodexEntry> & list)//and work
{
    short index = c;
    if(index >= 0 && index < list.size())//it's gooooood!
    {
        RolodexEntry edited = list[static_cast<short>(c)-1];

        //edit menu
        cout << "1. edit First name\n"
             << "2. edit Last name\n"
             << "3. edit Address\n"
             << "4. edit Phone number\n"
             << "5. edit Email\n";
        char sel;
        cin >> sel;
        cin.ignore(INT_MAX, '\n');

        switch(tolower(sel))
        {
        case '1': case 'f':
            {
                cout << "\nEnter new first name: ";
                string newName;
                cin >> newName;
                edited.setFName(newName);
                break;
            }
        case '2': case 'l':
            {
                cout << "\nEnter new last name: ";
                string newName;
                cin >> newName;
                edited.setLName(newName);
                break;
            }
        case '3': case 'a':
            {
                cout << "\nEnter new street number and street: ";
                string newStreet;
                cout.flush();
                if (cin.peek() == '\n')
                {
                    cin.ignore();
                }
                getline(cin, newStreet);
                edited.setStreet(newStreet);

                cout << "\nEnter new town: ";
                string newtown;
                cout.flush();
                if (cin.peek() == '\n')
                {
                    cin.ignore();
                }
                getline(cin, newtown);
                edited.setTown(newtown);

                cout << "\nEnter new state: ";
                string newstate;
                cout.flush();
                if (cin.peek() == '\n')
                {
                    cin.ignore();
                }
                getline(cin, newstate);
                edited.setState(newstate);

                cout << "\nEnter new zipcode: ";
                long newzip;
                cin >> newzip;
                if(newzip > 99999)//long zip
                {
                    edited.setZip(newzip);
                    edited.setSZipLong();//finds szip from long zip
                }
                else
                {
                    edited.setSZip(newzip);
                }
                break;
            }
        case '4': case 'p':
            {
                cout << "\nEnter new areacode: ";
                short newarea;
                cin >> newarea;
                edited.setArea(newarea);

                cout << "\nEnter new exchange number: ";
                short newex;
                cin >> newex;
                edited.setExchange(newex);

                cout << "\nEnter new line: ";
                short newLine;
                cin >> newLine;
                edited.setPLine(newLine);
                break;
            }
        case '5': case 'e':
            {
                cout << "\nEnter new email: ";
                string newemail;
                cin >> newemail;
                edited.setEmail(newemail);
                break;
            }
        }
    }
    else
    {
        cout << "Contact at this index does not exist.";
    }
    return;
}
void printSearchMenu(vector<RolodexEntry> & list)//and work
{
    cout << "1. search by Name\n"
         << "2. search by Address\n"
         << "3. search by Phone number\n"
         << "4. search by Email\n"
         << "5. Return to Main menu\n";

     char c;
     cin >> c;
     cin.ignore(INT_MAX, '\n');
     switch(tolower(c))
     {
     case '1': case 'n':
        {
            cout << "\nEnter search term: ";
            string search;
            cout.flush();
            if (cin.peek() == '\n')
            {
                cin.ignore();
            }
            getline(cin, search);

            for(vector<RolodexEntry>::size_type i = 0; i < list.size(); i++)
            {
                if(list[i].getFName().find(search) != string::npos ||
                   list[i].getLName().find(search) != string::npos)
                {
                    list[i].printEntry();
                }
            }
            break;
        }
     case '2': case 'a':
        {
            cout << "\nEnter search term: ";
            string search;
            cout.flush();
            if (cin.peek() == '\n')
            {
                cin.ignore();
            }
            getline(cin, search);

            for(vector<RolodexEntry>::size_type i = 0; i < list.size(); i++)
            {
                if(list[i].getStreet().find(search) != string::npos ||
                   list[i].getTown().find(search) != string::npos ||
                   list[i].getState().find(search) != string::npos)
                {
                    list[i].printEntry();
                }
            }
            break;
        }
     case '3': case 'p':
        {
            cout << "\nEnter part of phone number (last four digits gives best results): ";
            short search;

            while(cin.fail())
            {
                cin.clear();
                cin.ignore();
            }
            cin >> search;

            for(vector<RolodexEntry>::size_type i = 0; i < list.size(); i++)
            {
                if(list[i].getArea() == search || list[i].getExchange() == search ||
                   list[i].getPLine() == search)
                {
                    list[i].printEntry();
                }
            }
            break;
        }
     case '4': case 'e':
        {
            cout << "\nEnter email: ";
            string search;
            cout.flush();
            if (cin.peek() == '\n')
            {
                cin.ignore();
            }
            getline(cin, search);

            for(vector<RolodexEntry>::size_type i = 0; i < list.size(); i++)
            {
                if(list[i].getEmail().find(search) != string::npos)
                {
                    list[i].printEntry();
                }
            }
            break;
        }
     case '5': case 'q':
        {
            break;
        }
     default:
        {
            cout << "\nInvalid seletion.";
            break;
        }
     }
}
void printList(vector<RolodexEntry> & list)
{
    cout << '\n';
    for(vector<RolodexEntry>::size_type i = 0; i < list.size(); i++)
    {
        cout << i+1 << ".";
        list[i].printEntry();
    }
    return;
}
void eraseEntry(vector<RolodexEntry> & list, short index)
{
    vector<RolodexEntry>::size_type pos = index-1;
    vector<RolodexEntry>::size_type k;

    if (pos < list.size() && pos >= 0)
    {
        for (k = pos+1; k != list.size(); k++)
        {
            list[k-1] = list[k];
        }
        list.pop_back();
    }
    else
    {
        cout <<  "Out of bounds.";
    }
    return;
}
