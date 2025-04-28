#include <iostream>
#include <vector>

using namespace std;

int k, n;
vector<int> lans;
int maxNum = 0;

bool Check(int len)
{
    int sum = 0;
    for(int i=0; i<k; i++)
    {
        sum += lans[i]/len;
    }
    if(sum >= n)    return true;
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

    cin>>k>>n;
    lans.resize(k);
    for(int i=0; i<k; i++)
    {
        cin>>lans[i];
        if(maxNum < lans[i]) maxNum = lans[i];
    }

    cout<<Binary(1, maxNum)<<endl;
}