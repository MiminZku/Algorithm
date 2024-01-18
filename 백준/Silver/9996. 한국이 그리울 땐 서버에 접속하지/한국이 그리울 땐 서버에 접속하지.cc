#include <iostream>

using namespace std;

int n;
string str;
string head;
string tail;

bool Check(string& s)
{
    if(s.length() < head.length() + tail.length())  return false;
    for(int i=0; i<head.length(); i++)
    {
        if(s[i] != head[i]) return false;
    }
    for(int i=0; i<tail.length(); i++)
    {
        if(s[s.length()-tail.length()+i] != tail[i])    return false;
    }
    return true;
}

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    cin>>n;
    cin>>str;
    bool isHead = true;
    for(int i=0; i<str.length(); i++)
    {
        if(str[i] == 42)
        {
            isHead = false;
            continue;
        }

        if(isHead)  head.push_back(str[i]);
        else        tail.push_back(str[i]);
    }
    
    for(int i=0; i<n; i++)
    {
        string s;
        cin>>s;
        if(Check(s))
        {
            cout<<"DA\n";
        }
        else
        {
            cout<<"NE\n";
        }
    }
}