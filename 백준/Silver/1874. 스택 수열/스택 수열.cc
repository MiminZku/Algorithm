#include <iostream>
#include <vector>

using namespace std;

int main(){
    cin.tie(nullptr); ios::sync_with_stdio(false);
    int n,k;
    cin>>n;

    int lastPush = 0;
    vector<int> stack;
    stack.push_back(0);

    vector<char> res;
    while(n--){
        cin>>k;
        int top = stack[stack.size()-1];
        if(top < k){
            for(int i=lastPush+1; i<=k; i++){
                stack.push_back(i);
                res.push_back('+');
                lastPush++;
            }
            stack.pop_back();
            res.push_back('-');
        }
        else if(top == k){
            res.push_back('-');
            stack.pop_back();
        }
        else{
            cout<<"NO\n";
            return 0;
        }
    }

    for(char ch : res){
        cout<<ch<<'\n';
    }
}