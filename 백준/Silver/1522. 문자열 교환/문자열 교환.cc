#include <iostream>

using namespace std;

string str;

int main()
{
    cin >> str;

    int n = str.length();
    int aCnt = 0;
    for(char ch : str)
    {
        if(ch == 'a') ++aCnt;
    }

    str.append(str);

    int minCnt = 10000;
    for(int i = 0; i < n; ++i)
    {
        int bCnt = 0;
        for(int j = i; j < i + aCnt; ++j)
        {
            if(str[j] == 'b')   ++bCnt;
        }
        minCnt = min(minCnt, bCnt);
    }

    cout << minCnt << endl;
}