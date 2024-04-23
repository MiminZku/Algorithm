#include <iostream>
#include <queue>

using namespace std;

int n, m, k;
int mat[101][101];
int dy[] = {0,0,-1,1};
int dx[] = {-1,1,0,0};

int BFS(int r, int c)
{
    queue<pair<int,int>> q;
    q.push({r,c});
    int cnt = 0;

    while(!q.empty())
    {
        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();

        ++cnt;
        mat[curY][curX] = 1;

        for(int i=0; i<4; ++i)
        {
            int ny = curY + dy[i];
            int nx = curX + dx[i];
            if(ny<1 || ny>n || nx<1 || nx>m)    continue;
            if(0 <= mat[ny][nx]) continue;
            mat[ny][nx] = 1;
            q.push({ny,nx});
        }
    }
    return cnt;
}

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);

    cin>>n>>m>>k;

    while(k--)
    {
        int r, c;
        cin>>r>>c;
        mat[r][c] = -1;
    }

    int max = 0;
    for(int i=1; i<=n; ++i)
    {
        for(int j=1; j<=m; ++j)
        {
            if(0 <= mat[i][j])  continue;
            int size = BFS(i, j);
            if(max < size)  max = size;
        }
    }

    cout<<max<<endl;
}