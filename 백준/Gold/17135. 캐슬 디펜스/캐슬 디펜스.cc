#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n,m,d;
int orgBoard[16][15];
int res = 0;    // 제거할 수 있는 적의 최대 수
vector<vector<int>> allArcherPos;  // 궁수 배치 모든 경우의 수

void PickArcherPos(){
    vector<int> archerPos;
    for(int i=0; i<m; i++){
        for(int j=i+1; j<m; j++){
            for(int k=j+1; k<m; k++){
                archerPos.push_back(i);
                archerPos.push_back(j);
                archerPos.push_back(k);
                allArcherPos.push_back(archerPos);
                archerPos.clear();
            }
        }
    }
}
bool EnemyExist(int board[][15]){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(board[i][j]) return true;
        }
    }
    return false;
}
int Attack(int board[][15], vector<int>& archerPos){    // 이번 공격에서 죽인 적의 수 반환
    for(int p : archerPos){
        queue<vector<int>> q;   // 0: 행, 1: 열, 2: 거리
        q.push({n-1,p,1});
        bool visited[15][15] = {};
        visited[n-1][p] = true;

        while(!q.empty()){
            vector<int> rcd = q.front();   q.pop();
            int r = rcd[0]; int c = rcd[1]; int dist = rcd[2];
            if(dist>d)  continue;
            if(board[r][c]){
                board[r][c] = 2;
                break;
            }
            pair<int,int> navers[3] = {{0, -1}, {-1, 0}, {0, 1}};
            for(pair<int,int>& rc : navers){
                int nr = rc.first + r; int nc = rc.second + c;
                if(nr<0 || nc<0 || nc>=m)  continue;
                if(visited[nr][nc]) continue;
                visited[nr][nc] = true;
                q.push({nr,nc,dist+1});
            }
        }
    }
    int count = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(board[i][j] == 2){
                count++;
                board[i][j] = 0;
            }
        }
    }
    return count;
}
void EnemyCome(int board[][15]){    // 적이 한칸씩 다가옴
    for(int i=n-1; i>=0; i--){
        for(int j=0; j<m; j++){
            if(!board[i][j])    continue;
            board[i][j] = 0;
            if(i==n-1)  continue;
            board[i+1][j] = 1;
        }
    }
}

int main(){
    cin.tie(nullptr); ios::sync_with_stdio(false);
    cin>>n>>m>>d;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>orgBoard[i][j];
        }
    }

    PickArcherPos();
    for(vector<int>& archerPos: allArcherPos){
        int count = 0;
        int tempBoard[16][15];
        for(int i=0; i<=n; i++){
            for(int j=0; j<m; j++){
                tempBoard[i][j] = orgBoard[i][j];
            }
        }
        while(EnemyExist(tempBoard)){
            count += Attack(tempBoard, archerPos);
            EnemyCome(tempBoard);
        }
        if(count>res)   res = count;
    }
    cout<<res<<endl;
}