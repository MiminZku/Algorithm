#include <iostream>
#include <queue>

using namespace std;

typedef pair<int,int> Pos;

int n;
int mat[21][21];
int curSize = 2;
Pos curPos;
Pos navers[4] = {{0,1},{0,-1},{1,0},{-1,0}};

pair<int,Pos> GetNearestFish(){
    bool visited[21][21];
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            visited[i][j] = false;
        }
    }visited[curPos.first][curPos.second] = true;

    Pos res={0,0};  int minDist = 400;
    queue<pair<int,Pos>> q;
    q.push({0,curPos});

    while(!q.empty()){
        int dist = q.front().first;
        Pos cur = q.front().second;
        q.pop();

        if(mat[cur.first][cur.second] >0 && mat[cur.first][cur.second]<curSize){
            if(dist < minDist){
                res = cur;
                minDist = dist;
            }
            else if(dist == minDist){
                if(cur.first < res.first){
                    res = cur;
                    minDist = dist;
                }
                else if(cur.first == res.first){
                    if(cur.second < res.second){
                        res = cur;
                        minDist = dist;
                    }
                }
            }
        }
        for(Pos p : navers){
            int nr = cur.first + p.first;
            int nc = cur.second + p.second;
            if(nr < 1 || nc < 1 || nr > n || nc > n)    continue;
            if(mat[nr][nc] > curSize)   continue;
            if(visited[nr][nc]) continue;
            q.push({dist+1, {nr,nc}});
            visited[nr][nc] = true;
        }
    }
    return make_pair(minDist, res);
}

int main(){
    cin>>n;
    for(int i=1 ; i<=n ; i++){
        for(int j=1; j<=n; j++){
            int k;  cin>>k;
            if(k!=9)    mat[i][j] = k;
            else{
                curPos.first = i;
                curPos.second = j;
                mat[i][j] = 0;
            }
        }
    }
    int exp = 0;
    int time = 0;
    while(true){
        pair<int,Pos> p = GetNearestFish();
        int dist = p.first;
        Pos next = p.second;
        if(next.first == 0) break;
        curPos = next;
        mat[next.first][next.second] = 0;
        exp++;
        if(exp == curSize){
            curSize++;
            exp = 0;
        }
        time+=dist;
    }
    cout<<time<<endl;
}