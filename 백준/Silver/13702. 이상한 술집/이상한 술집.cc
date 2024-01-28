#include <iostream>
#include <vector>

using namespace std;

int n, k;
vector<int> alcohol;
int maxNum = 0;

bool Check(int h)
{
    int sum = 0;
    for(int i=0; i<n; i++)
    {
        sum += alcohol[i]/h;
    }
    if(sum >= k)    return true;
    return false;
}

int Binary(long long s, long long e)
{
    // cout<<s<<' '<<e<<'\n';
    if(s > e)   return e;
    long long mid = (s+e)/2;
    if(Check(mid))  return Binary(mid+1, e);
    else            return Binary(s, mid-1);
}

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);

    cin>>n>>k;
    alcohol.resize(n);
    for(int i=0; i<n; i++)
    {
        cin>>alcohol[i];
        if(maxNum < alcohol[i]) maxNum = alcohol[i];
    }

    cout<<Binary(1, maxNum)<<endl;
}