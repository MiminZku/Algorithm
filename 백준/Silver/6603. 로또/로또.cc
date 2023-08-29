#include <iostream>

using namespace std;

int n;
int arr[13];
int path[6];

void Recur(int level, int start)
{
    if(level == 6)
    {
        for(int i : path)
        {
            cout<<i<<' ';
        }
        cout<<'\n';
        return;
    }

    for(int i=start; i<n; i++)
    {
        path[level] = arr[i];
        Recur(level+1, i+1);
    }
}

int main()
{
    while(true)
    {
        cin>>n;
        if(n==0)    break;
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
        }

        Recur(0, 0);
        cout<<'\n';
    }
}