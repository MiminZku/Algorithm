#include <iostream>
#include <queue>

using namespace std;

struct cmp
{
    bool operator()(vector<int>& a, vector<int>& b)
    {
        if(a[0]>b[0])   return true;
        if(a[0]==b[0])
        {
            if(a[3]>b[3])   return true;
        }
        return false;
    }
};

int dy[4] = {0,0,-1,1};
int dx[4] = {-1,1,0,0};
int n,m,p;
int canMove[10];
priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
queue<vector<int>> tempQ;
char mat[1000][1000];
int result[10];

void BFS()
{
    while(!pq.empty())
    {
        int playerNum = pq.top()[0];
        int cy = pq.top()[1];
        int cx = pq.top()[2];
        int dist = pq.top()[3];
        pq.pop();

        if(cy==0 && cx==5)
        {
            int a=0;
        }
        if(dist == canMove[playerNum])
        {   
            tempQ.push({playerNum, cy, cx, 0});
            continue;
        }

        for(int i=0; i<4; i++)
        {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if(ny<0 || nx<0 || ny>=n || nx>=m)  continue;
            if(mat[ny][nx]!='.')    continue;
            mat[ny][nx] = '0'+playerNum;
            result[playerNum]++;
            pq.push({playerNum,ny,nx,dist+1});
        }
    }
}

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);
    cin>>n>>m>>p;
    for(int i=1; i<=p; i++)  cin>>canMove[i];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>mat[i][j];
            if(mat[i][j]>='1' && mat[i][j]<='9')
            {
                pq.push({mat[i][j]-'0', i, j, 0});
                result[mat[i][j]-'0']++;
            }
        }
    }

    while(true)
    {
        while(!tempQ.empty())
        {
            pq.push(tempQ.front());
            tempQ.pop();
        }
        BFS();
        if(tempQ.empty())   break;
    }

    for(int i=1; i<=p; i++)
    {
        cout<<result[i]<<' ';
    }cout<<'\n';
}