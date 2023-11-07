#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n,w,h;
    cin>>n>>w>>h;
    while(n--)
    {
        int k;
        cin>>k;

        if(sqrt(w*w + h*h) >= k)
        {
            cout<<"DA\n";
        }
        else
        {
            cout<<"NE\n";
        }
    }
}