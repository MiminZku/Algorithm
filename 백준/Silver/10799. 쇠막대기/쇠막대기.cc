#include <iostream>
#include <vector>

using namespace std;

int main(){
    cin.tie(nullptr); ios::sync_with_stdio(false);

    string str;
    cin>>str;

    vector<int> stack;
    char prev = 0;
    int res = 0;
    for(char ch : str){
        if(ch == '('){
            stack.push_back(1);
        }
        else if(ch == ')'){
            if(prev == '('){    // 레이저인 경우
                stack.pop_back();
                for(int i=0; i<stack.size(); i++){
                    stack[i] += 1;
                }
            }
            else{
                res += stack[stack.size()-1];
                stack.pop_back();
            }
        }
        prev = ch;
    }
    cout<<res<<endl;
}