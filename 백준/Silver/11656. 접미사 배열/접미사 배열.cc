#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string str;
vector<string> sArr;

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);
    cin>>str;

    for(int i=0; i<str.length(); i++)
    {
        sArr.push_back(str.substr(i, str.length()-i));
    }
    sort(sArr.begin(), sArr.end());
    for(const string& s : sArr)
    {
        cout<<s<<'\n';
    }
}