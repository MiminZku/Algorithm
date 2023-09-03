#include <iostream>

using namespace std;

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);
    string str;
    getline(cin, str);
    for(char ch : str)
    {
        int tmp = ch+13;
        if( ch >= 'A' && ch <= 'Z')
        {
            if(tmp > 'Z')    tmp -= 26;
            cout<<char(tmp);
        }
        else if(ch >= 'a' && ch <= 'z')
        {
            if(tmp > 'z')   tmp -= 26;
            cout<<char(tmp);
        }
        else    cout<<ch;
    }
    cout<<endl;
}