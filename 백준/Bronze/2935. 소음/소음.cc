#include <iostream>

using namespace std;

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);
    string str1, str2;
    char op;
    cin>>str1>>op>>str2;

    if(op == '*')
    {
        cout<<str1;
        for(int i=1; i<str2.length(); i++)  cout<<0;
        cout<<endl;
    }
    else
    {
        if(str1.length() > str2.length())
        {
            for(int i=0; i<str1.length()-str2.length(); i++)    cout<<str1[i];
            cout<<str2<<endl;
        }
        else if(str1.length() < str2.length())
        {
            for(int i=0; i<str2.length()-str1.length(); i++)    cout<<str2[i];
            cout<<str1<<endl;
        }
        else
        {
            cout<<2;
            for(int i=1; i<str1.length(); i++)  cout<<0;
            cout<<endl;
        }
    }
}