#include <iostream>
#include <vector>

using namespace std;

int n,m;
vector<int> jewels;
int maxNum = 0;

bool Check(int jealousy)
{
    int sum = 0;
    for(int i=0; i<m; i++)
    {
        sum += jewels[i]/jealousy;
        if(jewels[i]%jealousy)  sum++;
    }
    if(sum <= n)    return true;
    return false;
}

int Binary(int s, int e)
{
    if(s < e)   return e;
    int mid = (s+e)/2;
    if(Check(mid))  return Binary(mid-1, e);
    else            return Binary(s, mid+1);
}

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);

    cin>>n>>m;
    jewels.resize(m);
    for(int i=0; i<m; i++)
    {
        cin>>jewels[i];
        if(maxNum < jewels[i]) maxNum = jewels[i];
    }

    cout<<Binary(maxNum, 1)<<endl;
}