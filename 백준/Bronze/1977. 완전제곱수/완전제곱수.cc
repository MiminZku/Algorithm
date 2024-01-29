#include <iostream>

using namespace std;

bool isRight[10001];

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);

    for(int i=1; i<=100; i++)
    {
        isRight[i*i] = true;
    }

    int m, n;
    cin>>m>>n;

    int minNum;
    int sum = 0;
    for(int i=n; i>=m; i--)
    {
        if(isRight[i])
        {
            sum += i;
            minNum = i;
        }
    }
    if(sum == 0)
    {
        cout<<"-1\n";
    }
    else
    {
        cout<<sum<<endl<<minNum<<endl;
    }
}