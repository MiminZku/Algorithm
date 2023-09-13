#include <iostream>

using namespace std;

int n;
int cnt[10001];

void CountingSort()
{
    for(int i=0; i<10001; i++)
    {
        while(cnt[i]>0)
        {
            cout<<i<<'\n';
            cnt[i] -= 1;
        }
    }
}

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0; i<n; i++)
    {
        int k;
        cin>>k;
        cnt[k] += 1;
    }

    CountingSort();
}