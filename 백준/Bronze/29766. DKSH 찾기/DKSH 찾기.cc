#include <iostream>

using namespace std;

string str;

int main()
{
    cin >> str;

    int cnt = 0;
    for(int i = 0; i < str.length(); ++i)
    {
        if(str[i] != 'D') continue;

        if(str[i+1] == 'K' && str[i+2] == 'S' && str[i+3] == 'H')
        {
            ++cnt;
            i += 3;
        }
    }

    cout << cnt << endl;
}