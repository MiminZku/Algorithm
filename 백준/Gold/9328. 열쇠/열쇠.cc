#include <iostream>
#include <queue>

#define Y first
#define X second
#define KEY_IDX(key)   ((key)-97)
#define DOOR_IDX(door) ((door)-65)

using namespace std;

int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};
char mat[102][102];
bool visited[102][102];
bool hasKey[26];
vector<pair<int,int>> doorLoc[26];
int h,w;

void Clear()
{
    for(int i=0; i<26; i++)
    {
        doorLoc[i].clear();
        hasKey[i] = false;
    }
    for(int i=0; i<=h+1; i++)
    {
        for(int j=0; j<=w+1; j++)
        {
            visited[i][j] = false;
        }
    }
}

int BFS()
{
    int cnt = 0;
    queue<pair<int,int>> q;
    q.push({0,0});
    visited[0][0] = true;
    while(!q.empty())
    {
        int curY = q.front().Y;
        int curX = q.front().X;
        q.pop();

        char ch = mat[curY][curX];
        if(ch=='$') cnt++;
        else if(ch >= 'a' && ch <= 'z')
        {
            hasKey[KEY_IDX(ch)] = true;
            for(pair<int,int>& p : doorLoc[KEY_IDX(ch)])
                q.push({p.Y, p.X});
            doorLoc[KEY_IDX(ch)].clear();
        }

        for(int i=0; i<4; i++)
        {
            int ny = curY + dy[i];
            int nx = curX + dx[i];
            if(ny<0 || nx<0 || ny>h+1 || nx>w+1)    continue;
            if(mat[ny][nx]=='*')    continue;
            if(mat[ny][nx]>='A' && mat[ny][nx]<='Z' && !hasKey[DOOR_IDX(mat[ny][nx])])
            {
                doorLoc[DOOR_IDX(mat[ny][nx])].push_back({ny,nx});
                continue;
            }                
            if(visited[ny][nx])     continue;
            visited[ny][nx] = true;
            q.push({ny,nx});
        }
    }
    return cnt;
}

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>h>>w;
        Clear();
        for(int i=0; i<=h+1; i++)
        {
            for(int j=0; j<=w+1; j++)
            {
                if(i>=1 && i<=h && j>=1 && j<=w)    cin>>mat[i][j];
                else    mat[i][j] = '.';
            }
        }
        string keys;
        cin>>keys;
        if(keys.compare("0"))
        {
            for(char key : keys)    hasKey[KEY_IDX(key)] = true;
        }
        cout<<BFS()<<'\n';
    }
}