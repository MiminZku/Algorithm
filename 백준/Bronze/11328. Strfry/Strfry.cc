#include <iostream>

using namespace std;

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);
    int n;
    cin>>n;
    cin.ignore();
    string s1, s2;
    while(n--)
    {
        int arr[26] = {};
        cin>>s1>>s2;
        for(int i=0; i<s1.size(); i++)
        {
            arr[s1[i]-'a']++;
        }
        for(int i=0; i<s2.size(); i++)
        {
            arr[s2[i]-'a']--;
        }

        bool possible = true;
        for(int i=0; i<26; i++)
        {
            if(arr[i] != 0)
            {
                possible = false;
                break;
            }
        }
        if(possible)    cout<<"Possible\n";
        else            cout<<"Impossible\n";
    }
}