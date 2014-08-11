#include <iostream>
#include <cstdlib>
#include <vector>
#include <climits>
//base an skip empty ranges level 6
using namespace std;

typedef vector<short>::size_type conSize;
void readData(vector<short> & l);
void selSort(vector<short> & v);
conSize findMin(vector<short> & v, conSize startFrom);
void swap(short & i1, short & i2);
void printStemLeaf(const vector<short> & v);

int main(void)
{
    vector<short> data;
    readData(data);

    selSort(data);

//    cout <<"\n Check data:\n";
//    for(conSize i = 0; i < data.size(); i++)//check data
//    {
//        cout << data[i] << " ";
//    }
    cout << '\n';
    printStemLeaf(data);

    return 0;
}
void readData(vector<short> & l)
{
    cout << "Enter your Data:\n";
    while(isdigit(cin.peek()) || isspace(cin.peek()))
    {
        short t;
        if(isdigit(cin.peek()))
        {
            cin >> t;
            l.push_back(t);
        }
        else if(isspace(cin.peek()) && cin.peek() != '\n')
        {
            cin.ignore();
        }
        else
        {
            cin.ignore(INT_MAX, '\n');//not a space or data
        }
    }
    return;
}
conSize findMin(vector<short> & v, conSize startFrom)
{
    conSize smallest=startFrom;
    for(conSize i = startFrom+1; i < v.size(); i++)
    {
        if(v[i] < v[smallest])
        {
            smallest = i;
        }
    }
    return smallest;
}
void selSort(vector<short> & v)//still has issues
{
    conSize min = findMin(v,0);
    for(conSize cur = 0; cur != v.size()-1; cur++)
    {
        if(min != cur)
        {
            swap(v[cur], v[min]);
        }
        min = findMin(v,cur+1);
    }
}
void swap(short & i1, short & i2)
{
    short t = i1;
    i1 = i2;
    i2 = t;
    return;
}
void printStemLeaf(const vector<short> & v)
{
    short tens = v[0]/10;
    cout << '\n' << tens << ':';//print beginng of start branch
    for(conSize i = 0; i<v.size(); i++)
    {
        if(v[i]/10 == tens)//if data is in current tens
        {
            cout << v[i]%10;//should print out digit
        }
        else//print next branch, first data
        {
            tens = v[i]/10;
            cout << '\n' << tens << ':' << v[i]%10;
        }
    }
    return;
}
