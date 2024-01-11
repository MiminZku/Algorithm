#include <iostream>

using namespace std;

int cnt[26];

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    string str;
    while(cin>>str)
    {
        for(char ch : str)
        {
            cnt[ch-'a']++;
        }
    }

    int maxCnt = 0;
    for(int i=0; i<26; i++)
    {
        if(cnt[i] > maxCnt)
        {
            maxCnt = cnt[i];
        }
    }
    for(int i=0; i<26; i++)
    {
        if(cnt[i] == maxCnt)
        {
            cout<<char('a'+i);
        }
    }
    cout<<endl;
}