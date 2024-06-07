#include <iostream>

using namespace std;

int arr[1001];

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);

    int idx = 1;
    int num = 1;
    for(int i=1; ; ++i)
    {
        for(int j=0; j<i; ++j)
        {
            if(idx <= 1000) arr[idx++] = num;
        }
        if(idx > 1000)  break;
        ++num;
    }

    int a,b;
    cin>>a>>b;
    int sum = 0;
    for(int i=a; i<=b; ++i)
    {
        sum += arr[i];
    }
    cout<<sum << endl;
}