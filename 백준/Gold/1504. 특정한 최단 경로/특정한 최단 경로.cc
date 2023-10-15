#include <iostream>
#include <queue>

#define INF 3000000

using namespace std;

int n,e;
int v1,v2;

void Dijkstra(int startNode, const vector<pair<int,int>> edges[], int dist[])
{
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    bool visited[801] = {};
    q.push({0, startNode});
    dist[startNode] = 0;
    while(!q.empty())
    {
        int curNode = q.top().second;
        q.pop();

        if(visited[curNode])    continue;
        visited[curNode] = true;

        for(const pair<int,int>& p : edges[curNode])
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
    cin>>n>>e;
    vector<pair<int,int>> edges[n+1];   // 이웃노드, 가중치
    while(e--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        edges[a].push_back({b,c});
        edges[b].push_back({a,c});
    }
    cin>>v1>>v2;
    
    int dist[n+1];
    int dist1[n+1];
    int dist2[n+1];
    for(int i=0; i<=n; i++)
    {
        dist[i] = INF;
        dist1[i] = INF;
        dist2[i] = INF;
    }

    Dijkstra(1, edges, dist);
    Dijkstra(v1, edges, dist1);    
    Dijkstra(v2, edges, dist2);
    
    int result = min(dist[v1] + dist1[v2] + dist2[n], dist[v2] + dist2[v1] + dist1[n]);
    if(result >= INF)   cout<<"-1\n";
    else                cout<<result<<endl;
}