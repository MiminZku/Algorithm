#include <iostream>
#include <vector>

using namespace std;

vector<int> stack;

int main(){
    cin.tie(nullptr); ios::sync_with_stdio(false);
    int k,n;
    cin>>k;
    while(k--){
        cin>>n;
        if(n)   stack.push_back(n);
        else    stack.pop_back();
    }
    int res = 0;
    for(int i : stack)  res += i;
    cout<<res<<endl;
}