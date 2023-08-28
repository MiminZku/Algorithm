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

    int pre=0;
    for(int i=0; i<n; i++){
        if(nums[i] == pre)  continue;
        if(visited[i])      continue;
        visited[i] = true;
        pre = nums[i];
        path[level] = nums[i];
        Recur(level+1);
        visited[i] = false;
    }
}

int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++)  cin>>nums[i];
    sort(nums, nums+n);
    Recur(0);
}