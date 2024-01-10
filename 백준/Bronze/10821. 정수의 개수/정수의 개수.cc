#include <iostream>

using namespace std;

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    string str;
    cin>>str;
    str.append(",");

    int res = 0;
    for(char ch : str)
    {
        if(ch == ',')   res++;
    }
    cout<<res<<endl;
}