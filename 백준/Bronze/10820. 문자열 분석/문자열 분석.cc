#include <iostream>

using namespace std;

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);
    string str;
    while(getline(cin, str))
    {
        int a=0, b=0, c=0, d=0;
        for(char ch : str)
        {
            if(ch == ' ')   d++;
            else if(ch >= '0' && ch <= '9') c++;
            else if(ch >= 'a' && ch <= 'z') a++;
            else if(ch >= 'A' && ch <= 'Z') b++;
        }
        cout<<a<<' '<<b<<' '<<c<<' '<<d<<'\n';
    }
}