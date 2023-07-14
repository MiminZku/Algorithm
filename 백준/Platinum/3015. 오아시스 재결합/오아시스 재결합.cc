#include <iostream>
#include <vector>

#define INF 2147483647
#define STACK_TOP (*(stack.end()-1))

using namespace std;

int n;

int main(){
    cin.tie(nullptr); ios::sync_with_stdio(false);
    cin>>n;

    long long result = 0;

    vector<pair<long long, long long>> stack;    // 키, 같은 키인 사람 수

    for(int i=0, k; i<n; i++){
        cin>>k;
        long long cnt = 1;
        while(!stack.empty() && STACK_TOP.first <= k){
            result += STACK_TOP.second;
            if(STACK_TOP.first == k)    cnt+=STACK_TOP.second;
            stack.pop_back();
        }
        if(!stack.empty())  result++;
        stack.push_back({k,cnt});
    }

    cout<<result<<endl;
}