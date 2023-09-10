#include <iostream>

using namespace std;

int main()
{
    int e,s,m;
    cin>>e>>s>>m;
    int a=1, b=1, c=1;
    int k=1;
    while(true)
    {
        if(a==e && b==s && c==m)
        {
            cout<<k<<endl;
            break;
        }
        k++;
        a++; b++; c++;
        if(a>15)    a = 1;
        if(b>28)    b = 1;
        if(c>19)    c = 1;
    }
}