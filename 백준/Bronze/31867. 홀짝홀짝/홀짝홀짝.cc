#include <iostream>

using namespace std;

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);

    string str;
    cin >> str >> str;
    
    int oddCnt = 0;
    int evenCnt = 0;
    for(char ch : str)
    {
        int i = ch - '0';
        if(i % 2)   oddCnt++;
        else        evenCnt++;
    }

    if(oddCnt > evenCnt)
    {
        cout << "1";
    }
    else if(oddCnt < evenCnt)
    {
        cout << "0";
    }
    else
    {
        cout << "-1";
    }
}