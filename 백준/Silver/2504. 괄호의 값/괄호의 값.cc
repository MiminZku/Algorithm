#include <iostream>
#include <vector>
#define STACK_TOP stack[stack.size()-1]

using namespace std;

int Sol(const string& str){
    int res = 0;
    vector<pair<int,int>> stack;
    int len = str.size();
    for(int i=0; i<len; i++){
        if(str[i]=='('){
            stack.push_back({2,0});

        }
        else if(str[i]=='['){
            stack.push_back({3,0});
        }
        else{
            if(stack.empty())           return 0;
            if(str[i] == ')' && STACK_TOP.first != 2)    return 0;
            if(str[i] == ']' && STACK_TOP.first != 3)    return 0;
            
            int x = STACK_TOP.first;
            if(STACK_TOP.second)    x *= STACK_TOP.second;
            stack.pop_back();

            if(stack.empty())   res += x;
            else                STACK_TOP.second += x;
        }
    }
    if(stack.empty())   return res;
    else                return 0;
}

int main(){
    string str;
    cin>>str;
    cout<<Sol(str)<<endl;
}