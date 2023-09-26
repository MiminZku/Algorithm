#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<pair<int, string>> arr[51];


int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0; i<n; i++)
    {
        string str;
        cin>>str;
        int sum = 0;
        for(char ch : str)
        {
            if(ch >= '0' && ch <= '9')
            {
                sum += ch - '0';
            }
        }
        arr[str.size()].push_back({sum, str});
    }

    for(int i=1; i<=50; i++)
    {
        sort(arr[i].begin(), arr[i].end());
        for(int j=0; j<arr[i].size(); j++)
        {
            cout<<arr[i][j].second<<'\n';
        }
    }
}