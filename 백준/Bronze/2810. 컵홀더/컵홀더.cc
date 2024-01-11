#include <iostream>
#include <sstream>

using namespace std;

int cnt[26];

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int n;
    string str;

    cin>>n; cin.ignore();
    cin>>str;

    int Snum = 0;
    int Lnum = 0;
    
    for(char ch : str)
    {
        if(ch == 'S')   Snum++;
        else            Lnum++;
    }
    int cupHolder = Snum+1 + Lnum/2;
    
    cout<<min(n, cupHolder)<<endl;
}