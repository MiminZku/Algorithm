#include <iostream>
#include <vector>

#define INF 2147483647
#define STACK_TOP (*(stack.end()-1))

using namespace std;

int n;

int main(){
    cin.tie(nullptr); ios::sync_with_stdio(false);
    cin>>n;

    int result[n+1];

    vector<pair<int,int>> stack;    // 탑의 높이, 위치
    stack.push_back({INF,0});

    for(int i=1, k; i<=n; i++){
        cin>>k;
        if(STACK_TOP.first < k){
            while(STACK_TOP.first < k){
                stack.pop_back();
            }
        }
        result[i] = STACK_TOP.second;
        stack.push_back({k,i});
    }
    for(int i=1; i<=n; i++)
        cout<<result[i]<<' ';
    cout<<'\n';
}