#include <iostream>

using namespace std;

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    string str;
    cin>>str;

    for(char ch : str)
    {
        if(ch == 'C' ||
        ch == 'A' ||
        ch == 'M' ||
        ch == 'B' ||
        ch == 'R' ||
        ch == 'I' ||
        ch == 'D' ||
        ch == 'G' ||
        ch == 'E')  continue;
        cout<<ch;
    }
    cout<<endl;
}