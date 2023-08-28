#include <iostream>
#include <algorithm>

using namespace std;

int n,m;
int nums[8];
int path[8];
bool visited[8];

void Recur(int level)
{
    if(level == m)
    {
        for(int i: path)
        {
            if(i)   cout<<i<<' ';
            else
            {
                cout<<'\n';
                break;
            }
        }
        return;
    }
    for(int i=0; i<n; i++)
    {
        if(visited[i])   continue;
        visited[i] = true;
        path[level] = nums[i];
        Recur(level+1);
        visited[i] = false;
    }
}

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=0; i<n; i++)  cin>>nums[i];
    sort(nums, nums+n);
    Recur(0);
}