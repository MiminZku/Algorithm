#include <string>
#include <vector>
#include <queue>

using namespace std;

int n;
vector<vector<pair<int,int>>> pieces;
bool visited[50][50];

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int BFS(int r, int c, bool isPiece, const vector<vector<int>>& mat)
{
    queue<pair<int, int>> q;
    q.push({r, c});
    visited[r][c] = true;
    
    int size = 0;
    vector<pair<int, int>> pieceInfo;
    while(!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();
        
        size += 1;
        if(isPiece)
        {
            pieceInfo.push_back({cur.first - r, cur.second - c});
        }
        
        for(int i=0; i<4; ++i)
        {
            int nr = cur.first + dr[i];
            int nc = cur.second + dc[i];
            if(nr < 0 || nc < 0 || nr >= n || nc >= n)  continue;
            if(mat[nr][nc] != isPiece) continue;
            if(visited[nr][nc]) continue;
            visited[nr][nc] = true;
            q.push({nr, nc});
        }
    }
    
    if(isPiece)
    {
        pieces.push_back(pieceInfo);
    }
    return size;
}

bool Check(int r, int c, const vector<vector<int>>& mat, const vector<pair<int, int>> piece)
{
    for(const pair<int,int>& p : piece)
    {
        int nr = p.first + r;
        int nc = p.second + c;
        if(nr < 0 || nc < 0 || nr >= n || nc >= n ||
           mat[nr][nc] == 1)
        {
            return false;
        }
    }
        
    return true;
}

void Rotate(vector<vector<int>>& mat)
{
    vector<vector<int>> before(mat);
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<n; ++j)
        {
            mat[i][j] = before[n-1-j][i];
        }
    }
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) 
{
    n = table.size();
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<n; ++j)
        {
            if(table[i][j] == 0 || visited[i][j])    continue;
            BFS(i, j, true, table);
        }
    }
    
    int answer = 0;
    vector<bool> used(pieces.size(), false);    
    for(int i=0; i<4; ++i)
    {
        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                visited[i][j] = false;
            }
        }

        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                if(game_board[i][j] == 1 || visited[i][j])   continue;
                int size = BFS(i, j, false, game_board);
                for(int k=0; k<pieces.size(); ++k)
                {
                    if(used[k]) continue;
                    if(size != pieces[k].size()) continue;
                    if(Check(i, j, game_board, pieces[k]))
                    {
                        answer += size;
                        used[k] = true;
                        for(const pair<int, int>& p : pieces[k])
                        {
                            game_board[i + p.first][j + p.second] = 1;
                        }
                    }        
                }
            }
        }
        Rotate(game_board);
    }
    
    return answer;
}