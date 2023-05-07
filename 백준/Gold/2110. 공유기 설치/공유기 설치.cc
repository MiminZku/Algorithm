#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define fastio cin.tie(nullptr), ios::sync_with_stdio(false);

int n,c;
vector<int> houses;

bool Check(int interval){
    if(interval==1) return true;
    int count = 1; int pre = 0;        //처음 집 고름
    for(int i=1; i<houses.size(); i++){
        if(houses[i] - houses[pre] >= interval){    // 이전에 고른 집과 현재 집사이 거리가 c이상이면
            count++;
            pre = i;
        }
    }
    if(count>=c)    return true;
    else            return false;
}

int main(){
    fastio;
    cin>>n>>c;
    for(int i=0; i<n; i++){
        int x;  cin>>x;
        houses.push_back(x);
    }
    sort(houses.begin(),houses.end());
    int start = 1;
    int end = houses.back()-houses.front();
    
    if(c==2){
        cout<<end<<'\n';
        return 0;    
    }

    while(start != end){
        int mid = (start+end)/2;
        if(Check(mid)){
            start = mid+1;
        }
        else{
            end = mid;
        }
    }
    cout<<end-1<<'\n';
}