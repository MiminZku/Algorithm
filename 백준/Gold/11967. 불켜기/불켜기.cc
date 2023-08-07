#include <iostream>
#include <queue>

using namespace std;

#define Y first
#define X second

bool room[101][101];
bool visited[101][101];
int n,m;
vector<pair<int,int>> navers[101][101];
queue<pair<int,int>> q;

int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);
    cin>>n>>m;
    while(m--)
    {
        int x,y,a,b;
        cin>>x>>y>>a>>b;
        navers[x][y].push_back({a,b});
    }
    
    room[1][1] = true;
    visited[1][1] = true;
    q.push({1,1});
    while(!q.empty())
    {
        int cy = q.front().Y;
        int cx = q.front().X;
        q.pop();

        for(pair<int,int>& naver : navers[cy][cx])
        {
            if(room[naver.Y][naver.X]) continue;
            room[naver.Y][naver.X] = true;
            
            for(int i=0; i<4; i++)
            {
                int ny = naver.Y + dy[i];
                int nx = naver.X + dx[i];
                if(ny<1 || nx<1 || ny>n || nx>n)    continue;
                if(!visited[ny][nx])    continue;
                visited[naver.Y][naver.X] = true;
                q.push({naver.Y, naver.X});
                break;
            }
        }

        for(int i=0; i<4; i++)
        {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if(ny<1 || nx<1 || ny>n || nx>n)    continue;
            if(!room[ny][nx])   continue;
            if(visited[ny][nx]) continue;
            visited[ny][nx] = true;
            q.push({ny,nx});
        }

    }

    
    int result=0;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(room[i][j]) result++;
        }
    }
    cout<<result<<endl;
}