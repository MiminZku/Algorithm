#include <iostream>
#include <vector>
#include <queue>

#define fastio cin.tie(nullptr); ios::sync_with_stdio(false);

using namespace std;

int n, m;
int minTime = 9999;
bool solExist = false;
vector<vector<int>> mat;
vector<pair<int, int>> virusLoc;

bool IsFilled(vector<vector<bool>>& mat) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!mat[i][j]) return false;
        }
    }
    return true;
}

void Solve(vector<int>& viruses, int startIdx, int count) {
    if (count == m) {
        vector<vector<bool>> visited;
        for(int i=0; i<n; i++){
            vector<bool> row;
            for(int j=0; j<n; j++){
                if(mat[i][j]==1)    row.push_back(true);
                else                row.push_back(false);
            }
            visited.push_back(row);
        }
        queue<pair<int,pair<int,int>>> q;
        for (int i : viruses) {
            int r = virusLoc[i].first;
            int c = virusLoc[i].second;
            visited[r][c] = true;
            q.push({0,{r,c}});
        }
        int timeSpend;
        while(!q.empty()){
            int time = q.front().first;
            pair<int,int> cur = q.front().second;
            q.pop();

            pair<int,int> navers[4] = {{0,1},{0,-1},{1,0},{-1,0}};
            for(pair<int,int> naver: navers){
                int r = naver.first;    int c = naver.second;
                r += cur.first;         c += cur.second;
                if(r<0 || c<0 || r>=n || c>=n)  continue;
                if(visited[r][c])   continue;

                q.push({time+1,{r,c}});
                visited[r][c] = true;
            }
            if(!mat[cur.first][cur.second]){    // 빈공간일때만
                timeSpend = time;
            }
        }
        if(IsFilled(visited)){
            minTime = min(minTime, timeSpend);
            solExist = true;
        }
    }
    else {
        for (int i = startIdx; i < virusLoc.size(); i++) {
            viruses.push_back(i);
            Solve(viruses, i + 1, count + 1);
            viruses.pop_back();
        }
    }
}

int main() {
    fastio;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        vector<int> temp;
        for (int j = 0; j < n; j++) {
            int k;
            cin >> k;
            temp.push_back(k);
            if(k==2){
                virusLoc.push_back({i,j});
            }
        }
        mat.push_back(temp);
    }
    vector<int> emptyVec;
    Solve(emptyVec, 0, 0);
    if(solExist){
        cout<<minTime<<'\n';
    }
    else{
        cout<<-1<<'\n';
    }
}