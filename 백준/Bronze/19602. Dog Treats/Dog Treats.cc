#include <iostream>

using namespace std;

int s, m, l;

int main()
{
    cin>>s>>m>>l;
    if(s + 2 * m + 3 * l >= 10) cout<<"happy\n";
    else    cout<<"sad\n";
}