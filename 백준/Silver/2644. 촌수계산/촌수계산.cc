#include <iostream>
#include <queue>

using namespace std;

int n;
int m;

queue<pair<int, int>> q;
vector<int> ilchon[101];
bool visited[101];

int BFS(int src, int des)
{
    q.push({src, 0});
    visited[src] = true;

    while(!q.empty())
    {
        int cur = q.front().first;
        int lev = q.front().second;
        q.pop();

        if(cur == des)
        {
            return lev;
        }

        for(int i : ilchon[cur])
        {
            if(visited[i])  continue;
            visited[i] = true;
            q.push({i, lev + 1});
        }
    }
    return -1;
}

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);

    cin>>n;
    int a,b;
    cin>>a>>b;
    cin>>m;
    while(m--)
    {
        int x,y;
        cin>>x>>y;
        ilchon[x].push_back(y);
        ilchon[y].push_back(x);
    }

    cout<<BFS(a, b)<<endl;
}