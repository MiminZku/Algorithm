#include <iostream>
#include <vector>

using namespace std;

int main(){string str;
    cin>>str;

    vector<int> stack;
    char prev = 0;
    int res = 0;
    for(char ch : str){
        if(ch == '('){
            stack.push_back(1);
        }
        else{
            if(prev == '('){    // 레이저인 경우
                stack.pop_back();
                res += stack.size();
            }
            else{ // 막대기 끝날 때
                stack.pop_back();
                res++;
            }
        }
        prev = ch;
    }
    cout<<res<<endl;
}