#include <iostream>

using namespace std;

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    string str;
    cin>>str;

    for(char ch : str)
    {
        cout<<char(ch-3<65 ? ch+23 : ch-3);
    }
    cout<<endl;
}