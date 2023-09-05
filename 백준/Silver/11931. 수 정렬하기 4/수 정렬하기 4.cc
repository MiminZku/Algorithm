#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<int> vec;
    for(int i=0; i<n; i++)
    {
        int k;
        cin>>k;
        vec.push_back(k);
    }
    sort(vec.begin(), vec.end(), greater<int>());
    for(int i : vec)    cout<<i<<'\n';
}