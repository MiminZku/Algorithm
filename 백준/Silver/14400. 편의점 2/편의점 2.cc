#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vecX;
vector<int> vecY;

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);

    int n;
    cin>>n;
    vecX.resize(n);
    vecY.resize(n);

    for(int i=0; i<n; ++i)
    {
        cin>>vecX[i]>>vecY[i];
    }
    
    sort(vecX.begin(), vecX.end());
    sort(vecY.begin(), vecY.end());
    
    int x = vecX[(n-1)/2];
    int y = vecY[(n-1)/2];
    
    long long sum = 0;
    for(int i=0; i<n; ++i)
    {
        sum += abs(vecX[i] - x) + abs(vecY[i] - y);
    }
    cout<<sum<<endl;
}