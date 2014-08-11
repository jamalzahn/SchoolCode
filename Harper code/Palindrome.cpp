#include <iostream>
#include <climits>
#include <cctype>
#include <string>
//level 6
using namespace std;
bool checkPalindrome(string phrase);
void printResult(bool isPalindrome);
string readPhrase();
string readWord();
string pureAlphaNum(string s);
string toLower(string s);

int main(void)
{


    return 0;
}
bool checkPalindrome(string phrase)
{
    for(size_t i=0; i<=phrase.length()/2; i++)
    {
        if(phrase[i] != phrase[phrase.length()-i])
        {
            return false;
        }
    }
    return true;
}
void printResult(bool isPalindrome)
{
    cout << "\nYour entry is ";
    if(!isPalindrome)
    {
        cout << "not ";
    }
    cout << "a palindrome.\n";
}
string readPhrase()
{
    string s;
    cout.flush();
    if (cin.peek() == '\n')
    {
        cin.ignore();
    }
    getline(cin, s);
    return s;
}
string readWord()
{
    string s;
    cin >> s;
    cin.ignore(INT_MAX, '\n');
    return s;
}
string pureAlphaNum(string s)
{
    string t = toLower(s); // copy beacuse erase() reduces length
    for(size_t i=0; i<=s.length(); i++)
    {
        if(isspace(s[i]) || ispunct(s[i])) //will remove \n
        {
            t.replace(i,0,"");//might work, watch out for null index
        }
    }
    return t;
}
string toLower(string s)
{
    for (size_t i=0; i<s.length(); i++)
    {
        s[i] = tolower(s[i]);
    }
    return s;
}

