#include <iostream>
#include <vector>
#include <map>
#include <queue>

#define fastio cin.tie(nullptr); ios::sync_with_stdio(false);

using namespace std;

typedef pair<int,int> Pos;

int n,m,fuel;
int mat[21][21];
Pos taxiPos;
vector<Pos> guests;
map<Pos,Pos> desOf;
Pos navers[4] = {{-1,0},{1,0},{0,-1},{0,1}};

int GetDistanceTo(Pos pos){   // 택시가 현재 위치에서 pos 로 갈 때의 거리를 반환, 못가면 -1 반환
    bool visited[21][21];
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(mat[i][j]==1)    visited[i][j] = true;
            else                visited[i][j] = false;
        }
    } 
    visited[taxiPos.first][taxiPos.second] = true;
    
    queue<pair<Pos,int>> q;
    q.push({taxiPos, 0});
    while(!q.empty()){
        Pos curPos = q.front().first;
        int distance = q.front().second;
        q.pop();
        if(curPos == pos)   return distance;
        for(Pos& p : navers){
            int nr = curPos.first + p.first;
            int nc = curPos.second + p.second;
            if(nr < 1 || nc < 1 || nr > n || nc > n)    continue;
            if(visited[nr][nc]) continue;
            visited[nr][nc] = true;
            q.push({{nr,nc},distance+1});
        }
    }
    return -1;
}
Pos GetNextGuest(){
    bool visited[21][21];
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(mat[i][j]==1)    visited[i][j] = true;
            else                visited[i][j] = false;
        }
    } 
    visited[taxiPos.first][taxiPos.second] = true;

    int distance = 400;
    Pos resPos = {0,0};
    
    queue<pair<Pos,int>> q;
    q.push({taxiPos, 0});
    while(!q.empty()){
        Pos curPos = q.front().first;
        int d = q.front().second;
        q.pop();
        if(mat[curPos.first][curPos.second]==2){
            if(d < distance){
                distance = d;
                resPos = curPos;
            }
            else if(d == distance){
                if(curPos.first < resPos.first){
                    resPos = curPos;
                }
                else if(curPos.first == resPos.first){
                    if(curPos.second < resPos.second){
                        resPos = curPos;
                    }
                }
            }
        }
        for(Pos& p : navers){
            int nr = curPos.first + p.first;
            int nc = curPos.second + p.second;
            if(nr < 1 || nc < 1 || nr > n || nc > n)    continue;
            if(visited[nr][nc]) continue;
            visited[nr][nc] = true;
            q.push({{nr,nc},d+1});
        }
    }
    if(resPos.first)
        mat[resPos.first][resPos.second] = 0;
    return resPos;    
}

int main(){
    fastio;
    cin>>n>>m>>fuel;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            int k;   cin>>k;
            mat[i][j] = k;
        }
    }
    int r,c;    cin>>r>>c;
    taxiPos.first = r;
    taxiPos.second = c;
    for(int i=0; i<m; i++){
        cin>>r>>c;  Pos src = {r,c};
        cin>>r>>c;  Pos des = {r,c};
        mat[src.first][src.second] = 2;
        guests.push_back(src);
        desOf[src] = des;
    }

    bool nagari = false;
    while(m--){
        Pos nextGuest = GetNextGuest();
        if(nextGuest.first){
            fuel -= GetDistanceTo(nextGuest);
            taxiPos = nextGuest;
        }else{
            nagari = true;
            break;
        }

        int fuelSpend = GetDistanceTo(desOf[nextGuest]);
        if(fuelSpend >= 0){
            fuel -= fuelSpend;
            taxiPos = desOf[nextGuest];
        }else{
            nagari = true;
            break;
        }

        if(fuel < 0){
            nagari = true;
            break;
        }
        fuel += fuelSpend*2;
    }
    if(nagari)  cout<<-1<<endl;
    else        cout<<fuel<<endl;
}