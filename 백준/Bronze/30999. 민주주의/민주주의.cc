#include <iostream>

using namespace std;

int n, m;

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);
    cin >> n >> m;
    string str;
    int res = 0;
    while(n--)
    {
        int oCnt = 0, xCnt = 0;
        cin >> str;
        for(char ch : str)
        {
            if(ch == 'O')   ++oCnt;
            else            ++xCnt;
        }
        if(oCnt > xCnt) ++res;
    }
    cout << res << endl;
}