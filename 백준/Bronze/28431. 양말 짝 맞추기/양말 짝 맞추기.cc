#include <iostream>

using namespace std;

int cnt[10];

int main()
{
    int tmp = 5;
    int k;
    while(tmp--)
    {
        cin>>k;
        cnt[k]++;
    }

    for(int i=0; i<10; ++i)
    {
        if(cnt[i] % 2)
        {
            cout<<i<<endl;
            break;
        }
    }
}