#include <iostream>

using namespace std;

int cnt[26];

bool Check()
{
    return cnt['M'-'A'] &&
           cnt['O'-'A'] &&
           cnt['B'-'A'] &&
           cnt['I'-'A'] &&
           cnt['S'-'A'];
}

int main()
{
    string str;
    cin>>str;
    for(char ch : str)
    {
       cnt[ch-'A']++; 
    }
    
    if(Check())
    {
        cout<<"YES\n";
    }
    else
    {
        cout<<"NO\n";
    }
}