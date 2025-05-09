#include <iostream>
#include <queue>

#define INF 2147483647

using namespace std;

int v,e;
int startNode;
bool visited[20001];

void Dijkstra(vector<pair<int,int>> edges[], int dist[])
{
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    q.push({0, startNode});
    dist[startNode] = 0;
    while(!q.empty())
    {
        int curNode = q.top().second;
        q.pop();

        if(visited[curNode])    continue;
        visited[curNode] = true;

        for(pair<int,int>& p : edges[curNode])
        {
            int naver = p.first;
            if(visited[naver])  continue;
            dist[naver] = min(dist[naver], dist[curNode] + p.second);
            q.push({dist[naver], naver});
        }        
    }
}

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);
    cin>>v>>e;
    cin>>startNode;
    vector<pair<int,int>> edges[v+1];   // 이웃노드, 가중치
    while(e--)
    {
        int u,v,w;
        cin>>u>>v>>w;
        edges[u].push_back({v,w});
    }
    
    int dist[v+1];
    for(int i=0; i<=v; i++) dist[i] = INF;

    Dijkstra(edges, dist);
    
    for(int i=1; i<=v; i++)
    {
        if(dist[i]==INF)    cout<<"INF\n";
        else                cout<<dist[i]<<'\n';
    }
}