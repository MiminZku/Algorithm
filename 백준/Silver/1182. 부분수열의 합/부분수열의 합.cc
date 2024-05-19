#include <iostream>

using namespace std;

int N,S;
int arr[20];
int path[20];
int cnt;

void Recur(int level, int start)
{
    if(0 < level && level <= N)
    {
        int sum=0;
        for(int i=0; i<level; i++)
        {
            sum += path[i];
        }
        if(sum==S)
        {
            cnt++;
        }
    }
    else if(level > N)   return;

    for(int i=start; i<N; i++)
    {
        path[level] = arr[i];
        Recur(level+1, i+1);
    }
}

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);
    cin>>N>>S;
    for(int i=0; i<N; i++)  cin>>arr[i];

    Recur(0,0);

    cout<<cnt<<endl;
}