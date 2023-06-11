#include <iostream>
#include <algorithm>

using namespace std;

int n,m;
int nums[8];
int path[8];

void Recur(int level, int start){
    if(level == m){
        for(int i: path){
            if(i)   cout<<i<<' ';
            else{
                cout<<'\n';
                break;
            }
        }
        return;
    }
    for(int i=start; i<n; i++){
        path[level] = nums[i];
        Recur(level+1, i);
    }
}

int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++)  cin>>nums[i];
    sort(nums, nums+n);
    Recur(0, 0);
}