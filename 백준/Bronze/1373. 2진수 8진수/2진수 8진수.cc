#include <iostream>

using namespace std;

char change2oct(string str)
{
    if(!str.compare("000"))
    {
        return '0';
    }
    else if(!str.compare("001"))
    {
        return '1';
    }
    else if(!str.compare("010"))
    {
        return '2';
    }
    else if(!str.compare("011"))
    {
        return '3';
    }
    else if(!str.compare("100"))
    {
        return '4';
    }
    else if(!str.compare("101"))
    {
        return '5';
    }
    else if(!str.compare("110"))
    {
        return '6';
    }
    else if(!str.compare("111"))
    {
        return '7';
    }
    return 0;
}

int main()
{
    string str;
    cin>>str;

    for(int i=0; i<str.length()%3; i++)
    {
        str.insert(str.begin(), '0');
    }

    for(int i=0; i<str.length()-2; i+=3)
    {
        cout<<change2oct(str.substr(i,3));
    }
    cout<<endl;
}