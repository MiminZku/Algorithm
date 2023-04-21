#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int n, m;
    scanf("%d %d",&n,&m);
    vector<vector<int>> vec(n+1);
    while(m--){
        int u, v;
        scanf("%d %d",&u, &v);
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    int count = 0;
    bool visited[n+1] = {false};
    for(int i = 1; i <= n; i++){
        if(visited[i])  continue;
        visited[i] = true;
        queue<int> q;
        q.push(i);
        while(q.size()){
            int cur = q.front();    q.pop();
            for(int naver : vec[cur]){
                if (visited[naver]) continue;
                visited[naver] = true;
                q.push(naver);
            }
        }
        count++;
    }
    printf("%d\n",count);
    return 0;
}