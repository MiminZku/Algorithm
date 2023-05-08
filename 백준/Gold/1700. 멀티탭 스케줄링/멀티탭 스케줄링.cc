#include <iostream>
#include <vector>

#define fastio cin.tie(nullptr); ios::sync_with_stdio(false);

using namespace std;

int n,k;
int plug;      // 현재 사용중인 플러그 개수
int seq[100];       // 사용 순서
vector<int> plan[101];   // i번 전기용품을 사용하는 시점의 배열;
bool isPluged[101];     // i번 전기용품이 현재 꽂혀져 있는지

int main(){
    fastio
    cin>>n>>k;
    for(int i=0; i<k; i++){
        int id; cin>>id;
        seq[i] = id;
        plan[id].push_back(i);
    }

    int res = 0;
    for(int i=0; i<k; i++){
        int cur = seq[i];
        if(plan[cur].size()){
            plan[cur].erase(plan[cur].begin());
        }
        if(isPluged[cur])    continue;
        if(plug<n){
            plug++;
            isPluged[cur] = true;
        }
        else{
            int target; int maxIdx = 0;
            for(int id=1; id<=100 ;id++){   // 꽂혀져 있는 것 중 가장 나중에 사용하게 되는 거
                if(!isPluged[id])    continue;
                if(plan[id].size() == 0){
                    target = id;
                    break;
                }
                if(plan[id].front() > maxIdx){
                    maxIdx = plan[id].front();
                    target = id;
                }
            }
            isPluged[target] = false;
            isPluged[cur] = true;
            res++;
        }
    }
    cout<<res<<endl;
}

/*
3 100
56 71 70 25 52 77 76 8 68 71 51 65 13 23 7 16 19 54 95 18 86 74 29 76 61 93 44 96 32 72 64 19 50 49 22 14 7 64 24 83 6 3 2 76 99 7 76 100 60 60 6 50 90 49 27 51 37 61 16 84 89 51 73 28 90 77 73 39 78 96 78 13 92 54 70 69 62 78 7 75 30 67 97 98 19 86 90 90 2 39 41 58 57 84 19 8 52 39 26 7
// 80

3 14
1 4 3 2 5 4 3 2 5 3 4 2 3 4
// 4

4 20
1 2 3 4 5 1 2 3 4 5 1 2 3 4 5 1 2 3 4 5
// 4

2 15
3 2 1 2 1 2 1 2 1 3 3 3 3 3 3
// 2

2 9
1 2 3 1 2 3 1 2 3
// 4
*/