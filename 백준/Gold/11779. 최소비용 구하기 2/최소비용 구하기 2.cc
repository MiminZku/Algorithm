#include <iostream>
#include <vector>

#define INF 2147483647

using namespace std;

int n,m;
vector<pair<int,int>> buses[1001];
vector<int> result;
int parent[1001];
bool visited[1001];
int src, des;

int Dijkstra(int src, int des)
{
    int dist[1001];
    for(int i=1; i<=n; i++) dist[i] = INF;
    dist[src] = 0;
    
    int curNode = src;
    while(true)
    {
        int minDist = INF;
        int nextNode = 0;
        for(const pair<int,int>& p : buses[curNode])
        {
            if(dist[p.first] > dist[curNode] + p.second)
            {
                dist[p.first] = dist[curNode] + p.second;
                parent[p.first] = curNode;
            }
        }
        for(int i=1; i<=n; i++)
        {
            if(visited[i])  continue;
            if(dist[i] < minDist)
            {
                minDist = dist[i];
                nextNode = i;
            }
        }
        if(nextNode == des) return dist[des];
        visited[curNode] = true;
        curNode = nextNode;
    }
}

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        int src, des, cost;
        cin>>src>>des>>cost;
        buses[src].push_back({des,cost});
    }
    cin>>src>>des;
    parent[src] = src;
    cout<<Dijkstra(src, des)<<endl;
    int node = des;
    while(parent[node] != node)
    {
        result.push_back(node);
        node = parent[node];
    }
    result.push_back(src);
    cout<<result.size()<<endl;
    for(int i = result.size()-1; i>=0; i--) cout<<result[i]<<' ';
    cout<<endl;
}