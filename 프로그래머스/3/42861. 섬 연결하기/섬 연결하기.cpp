#include <string>
#include <vector>
#include <queue>

using namespace std;

int parent[100];

int Find(int a)
{
    if(a == parent[a])
    {
        return a;
    }
    return parent[a] = Find(parent[a]);
}

void Union(int a, int b)
{
    int aP = Find(a);
    int bP = Find(b);
    if(aP != bP)
    {
        parent[bP] = aP;
    }
}

priority_queue<pair<int, pair<int, int>>> edges;

int solution(int n, vector<vector<int>> costs) {
    for(int i=0; i<n; ++i)
    {
        parent[i] = i;
    }
    for(const vector<int>& v : costs)
    {
        edges.push({-v[2], {v[0], v[1]}});
    }
    
    int answer = 0;
    for(int i=1; i<n;)
    {
        int cost = -edges.top().first;
        int a = edges.top().second.first;
        int b = edges.top().second.second;
        edges.pop();
        
        if(Find(a) == Find(b))
        {
            continue;
        }
        
        Union(a, b);
        answer += cost;
        ++i;
    }
    
    return answer;
}