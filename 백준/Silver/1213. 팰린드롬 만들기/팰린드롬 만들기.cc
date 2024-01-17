#include <iostream>

using namespace std;

int cnt[26];

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);

    string str;
    cin>>str;

    for(char ch : str)
    {
        cnt[ch-'A']++;
    }

    int odd = 0;
    int oddIdx = -1;
    for(int i=0; i<26; i++)
    {
        if(cnt[i]%2)
        {
            odd++;
            if(odd>1)
            {
                cout<<"I'm Sorry Hansoo\n";
                return 0;
            }
            oddIdx = i;
        }
    }

    for(int i=0; i<26; i++)
    {
        if(cnt[i] == 0) continue;
        for(int j=0; j<cnt[i]/2; j++)
        {
            cout<<char('A'+i);
        }
    }
    if(oddIdx >= 0) cout<<char('A'+oddIdx);
    for(int i=26; i>=0; i--)
    {
        if(cnt[i] == 0) continue;
        for(int j=0; j<cnt[i]/2; j++)
        {
            cout<<char('A'+i);
        }  
    }
    cout<<endl;
}