#include <iostream>
#include <queue>

using namespace std;

pair<int,int> direct[8] = {
    {-2, -1},
    {-2, 1},
    {-1, -2},
    {-1, 2},
    {1, -2},
    {1, 2},
    {2, -1},
    {2, 1}
};

int main(){
    cin.tie(nullptr); ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int sR, sC, eR, eC;
        cin>>sR>>sC>>eR>>eC;
        
        bool visited[n][n];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++)
                visited[i][j] = false;
        }
        visited[sR][sC] = true;

        queue<pair<pair<int,int>,int>> q;
        q.push({{sR,sC},0});

        while(!q.empty()){
            int cR = q.front().first.first;
            int cC = q.front().first.second;
            int moveCnt = q.front().second;
            q.pop();

            if(cR == eR && cC == eC){
                cout<<moveCnt<<'\n';
                break;
            }

            for(pair<int,int>& p : direct){
                int nR = p.first + cR;
                int nC = p.second + cC;
                if(nR<0 || nC<0 || nR>=n || nC>=n)  continue;;
                if(visited[nR][nC]) continue;
                visited[nR][nC] = true;
                q.push({{nR,nC},moveCnt+1});
            }
        }
    }
}