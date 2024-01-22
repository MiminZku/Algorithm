#include <iostream>

using namespace std;

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    string str;
    cin>>str;

    int n;
    cin>>n;

    int res = 0;
    for(int i=0; i<n; i++)
    {
        string s;
        cin>>s;

        for(int j=0; j<s.length(); j++)
        {
            bool check = true;
            for(int k=0; k<str.length(); k++)
            {
                int idx = j+k;
                if(idx >= s.length())   idx -= s.length();
                if(s[idx] != str[k])
                {
                    check = false;
                    break;
                }
            }

            if(check)
            {
                res++;
                break;
            }
        }
    }
    cout<<res<<endl;
}