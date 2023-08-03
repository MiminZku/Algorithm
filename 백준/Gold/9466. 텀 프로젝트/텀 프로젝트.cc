#include <iostream>

using namespace std;

int DFS(int wish[], int team[], int idx, int teamNum)
{
    team[idx] = teamNum;
    if(team[wish[idx]])
    {
        team[idx] = -1;
        return wish[idx];
    }
    int lastIdx = DFS(wish, team, wish[idx], teamNum);
    if(lastIdx == idx)
    {
        int tempIdx = wish[idx];
        while(tempIdx != idx)
        {
            team[tempIdx] = teamNum;
            tempIdx = wish[tempIdx];
        }
    }
    else
        team[idx] = -1;
    return lastIdx;
}

int main(){
    cin.tie(nullptr); ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int wish[n+1] = {};
        int team[n+1] = {};
        int teamNum = 1;
        for(int i=1; i<=n; i++)
        {
            cin>>wish[i];
            if(i==wish[i])  team[i] = teamNum++;
        }
        for(int i=1; i<=n; i++)
        {
            if(team[i])    continue;
            DFS(wish, team, i, teamNum++);
        }
        
        int result = 0;
        for(int i=1; i<=n; i++)
        {
            if(team[i]<0)  result += 1;
        }
        cout<<result<<'\n';
    }
}