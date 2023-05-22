#include <iostream>
#include <vector>

#define INF 100

using namespace std;

int n,m;
int map[10][10];

int k;
vector<pair<int,int>> islandLoc[7]; // islandLoc[i] : i번 섬의 좌표들
int minDist[7][7];                  // minDist[i][j] : i번 섬과 j번 섬을 잇는 다리의 최소값 (초기값은 INF)

void Paint(int r, int c, int num){
    map[r][c] = num;
    islandLoc[num].push_back(make_pair(r,c));
    pair<int,int> navers[4] = {{0,1},{0,-1},{1,0},{-1,0}};
    for(pair<int,int>& rc : navers){
        int nr = rc.first + r;
        int nc = rc.second + c;
        if(nr<0 || nr>=n || nc<0 || nc>=m)  continue;
        if(map[nr][nc]==-1)
            Paint(nr,nc,num);
    }
}

int Prim(){
    int result = 0;
    bool visitedArr[7] = {};
    visitedArr[1] = true;
    vector<int> visited;
    visited.push_back(1);
    while(visited.size() < k){
        int min=INF;
        int src;
        int des;
        for(int island : visited){
            for(int i=1; i<=k; i++){
                if(visitedArr[i])  continue;
                if(minDist[island][i]<min){
                    min = minDist[island][i];
                    src = island;
                    des = i;
                }
            }
        }
        result += minDist[src][des];
        visited.push_back(des);
        visitedArr[des] = true;
    }
    return result;
}

void DFS(bool visited[7], int island){
    if(visited[island]) return;
    visited[island] = true;
    for(int i=1; i<=k; i++){
        if(minDist[island][i]<INF)
            DFS(visited, i);
    }
}

bool Linked(){
    int copy[7][7];
    bool visited[7] = {};
    DFS(visited,1);
    for(int i=1; i<=k; i++){
        if(!visited[i]) return false;
    }
    return true;
}

int main(){
    cin.tie(nullptr); ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>map[i][j];
            if(map[i][j])   map[i][j] *= -1;
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(map[i][j]!=-1)  continue;
            Paint(i,j,++k);
        }
    }
    
    for(int i=1; i<=k; i++){
        for(int j=1; j<=k; j++){
            minDist[i][j] = INF;
        }
    }
    for(int i=1; i<=k; i++){
        for(pair<int,int>& rc : islandLoc[i]){
            int r = rc.first;   int c = rc.second;
            int tempR = r;  int tempC = c;
            int count = 0;
            int naver = 0;
            while(true){    // 위쪽으로 탐색
                tempR--;
                if(tempR < 0)   break;
                if(map[tempR][tempC]){
                    if(count<2) break;
                    naver = map[tempR][tempC];
                    break;
                }
                count++;
            }
            if(naver){
                minDist[map[r][c]][naver] = min(count, minDist[map[r][c]][naver]);
                minDist[naver][map[r][c]] = min(count, minDist[naver][map[r][c]]);
            }

            tempR = r;  tempC = c;
            count = 0;
            naver = 0;
            while(true){    // 아래쪽으로 탐색
                tempR++;
                if(tempR >= n)   break;
                if(map[tempR][tempC]){
                    if(count<2) break;
                    naver = map[tempR][tempC];
                    break;
                }
                count++;
            }
            if(naver){
                minDist[map[r][c]][naver] = min(count, minDist[map[r][c]][naver]);
                minDist[naver][map[r][c]] = min(count, minDist[naver][map[r][c]]);
            }

            tempR = r;  tempC = c;
            count = 0;
            naver = 0;
            while(true){    // 왼쪽으로 탐색
                tempC--;;
                if(tempC < 0)   break;
                if(map[tempR][tempC]){
                    if(count<2) break;
                    naver = map[tempR][tempC];
                    break;
                }
                count++;
            }
            if(naver){
                minDist[map[r][c]][naver] = min(count, minDist[map[r][c]][naver]);
                minDist[naver][map[r][c]] = min(count, minDist[naver][map[r][c]]);
            }

            tempR = r;  tempC = c;
            count = 0;
            naver = 0;
            while(true){    // 오른쪽으로 탐색
                tempC++;
                if(tempC >= m)   break;
                if(map[tempR][tempC]){
                    if(count<2) break;
                    naver = map[tempR][tempC];
                    break;
                }
                count++;
            }
            if(naver){
                minDist[map[r][c]][naver] = min(count, minDist[map[r][c]][naver]);
                minDist[naver][map[r][c]] = min(count, minDist[naver][map[r][c]]);
            }
        }
    }

    if(!Linked())   cout<<-1<<endl;
    else            cout<<Prim()<<endl;
}