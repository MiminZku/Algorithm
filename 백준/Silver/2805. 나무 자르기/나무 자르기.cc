#include <iostream>
#include <vector>

using namespace std;

int n,m;
vector<int> trees;
int maxH = 0;

bool Check(int h)
{
    long long sum = 0;
    for(int i=0; i<n; i++)
    {
        if(trees[i] > h)    sum += trees[i]-h;
    }
    if(sum >= m)    return true;
    return false;
}

int Binary(long long s, long long e)
{
    if(s > e)   return e;
    long long mid = (s+e)/2;
    if(Check(mid))  return Binary(mid+1, e);
    else            return Binary(s, mid-1);
}

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);

    cin>>n>>m;
    trees.resize(n);
    for(int i=0; i<n; i++)
    {
        cin>>trees[i];
        if(maxH < trees[i]) maxH = trees[i];
    }

    cout<<Binary(0, maxH)<<endl;
}