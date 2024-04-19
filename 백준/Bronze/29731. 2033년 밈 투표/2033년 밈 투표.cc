#include <iostream>
#include <vector>

using namespace std;

int n;
vector<std::string> inArr;

string sArr[] = 
{
    "Never gonna give you up",
    "Never gonna let you down",
    "Never gonna run around and desert you",
    "Never gonna make you cry",
    "Never gonna say goodbye",
    "Never gonna tell a lie and hurt you",
    "Never gonna stop",
};

bool IsIn(const string& str)    // 문장 하나가 공약에 속하는지
{
    for(int i=0; i<7; ++i)
    {
        if(!str.compare(sArr[i]))   return true;
    }
    return false;
}

bool Check()    // 모든 문장이 공약에 속하면
{
    for(const string& str : inArr)
    {
        if(!IsIn(str))  return false;
    }
    return true;
}

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);

    cin>>n;
    cin.ignore();

    while(n--)
    {
        string str;
        getline(cin, str);
        inArr.push_back(str);
    }

    if(Check()) cout<<"No\n";
    else        cout<<"Yes\n";
}