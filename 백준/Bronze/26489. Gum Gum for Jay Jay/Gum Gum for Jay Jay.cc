#include <iostream>

using namespace std;

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);

    int i = 0;
    string str;
    while(getline(cin, str))
    {
        ++i;
    }
    cout<<i<<endl;
}