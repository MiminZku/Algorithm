#include <iostream>

using namespace std;

int main()
{
    while(true)
    {
        int a,b,c;
        if(cin>>a)
        {
            cin>>b>>c;
        }
        else break;

        int result = (c-b) > (b-a) ? (c-b) : (b-a);
        cout<<--result<<'\n';
    }    
}