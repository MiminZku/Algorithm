#include <iostream>

using namespace std;

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    string str;
    cin>>str;
    int res = 10;
    char pre = str[0];
    for(int i=1; i<str.length(); i++)
    {
        if(pre == str[i])
        {
            res += 5;
        }
        else
        {
            res += 10;
            pre = str[i];
        }
    }
    cout<<res<<endl;
}