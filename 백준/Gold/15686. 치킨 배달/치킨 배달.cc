#include <iostream>
#include <vector>

using namespace std;

int n,m;
int result = 100000000;

vector<pair<int,int>> houses;
vector<pair<int,int>> hubo;     // 모든 치킨집 좌표
vector<pair<int,int>> chickens; // 위에 중에 m 개 추린거

bool visited[13];

int DistToChicken(int r, int c)
{
    int result = 10000;
    for(pair<int,int>& pos : chickens)
    {
        int distY = abs(pos.first - r);
        int distX = abs(pos.second - c);
        result = min(result, distY + distX);
    }    
    return result;
}

void Solve()
{
    int sum = 0;
    for(int i=0; i<houses.size(); i++)
    {
        sum += DistToChicken(houses[i].first, houses[i].second);
    }
    result = min(result, sum);
}

void Recur(int level, int start)
{
    if(level == m)
    {        
        Solve();
        return;
    }

    for(int i=start; i<hubo.size(); i++)
    {
        if(visited[i])  continue;
        visited[i] = true;
        chickens[level] = hubo[i];
        Recur(level+1, i+1);
        visited[i] = false;
    }
}

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);
    cin>>n>>m;
    chickens.resize(m);
    int k;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>k;
            if(k == 1)
            {
                houses.push_back({i,j});
            }
            else if(k == 2)
            {
                hubo.push_back({i, j});
            }
        }
    }

    Recur(0, 0);

    cout<<result<<endl;
}