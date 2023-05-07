#include <iostream>
#include <vector>

#define fastio cin.tie(nullptr), ios::sync_with_stdio(false);

using namespace std;

const int INF = 100000000;
int n;
int timeToBuild[501];      // timeToBuild[i] : i번 건물만 짓는데 필요한 시간
int minTime[501];          // minTime[i] : i번 건물을 짓는데 필요한 최소 시간
vector<int> needs[501];    // needs[i] : i번 건물을 짓는데 필요한 건물들의 배열

int GetMinTime(int i){
    if(needs[i].size()==0) return timeToBuild[i];

    int needsTime = 0;
    for(int j : needs[i]){
        if(minTime[j] == INF){
            minTime[j] = GetMinTime(j);
        }
        if(minTime[j] > needsTime){
            needsTime = minTime[j];
        }
    }
    return timeToBuild[i] + needsTime;
}

int main(){
    fastio;
    fill_n(minTime, 501, INF);
    cin>>n;
    for(int i=1; i<=n; i++){
        int time;   cin>>time;
        timeToBuild[i] = time;

        int need;      
        while(true){
            cin>>need;
            if(need == -1)  break;
            needs[i].push_back(need);
        }
    }
    for(int i=1; i<=n; i++){
        cout<<GetMinTime(i)<<'\n';
    }
}