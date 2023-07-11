#include <iostream>
#include <deque>

using namespace std;

int main(){
    cin.tie(nullptr); ios::sync_with_stdio(false);
    int n;
    cin>>n;

    int cnt=0;
    while(n--){
        string str;
        cin>>str;
        if(str.size()%2)    continue;

        deque<char> stack;
        stack.push_back(0);
        for(int i=0; i<str.size(); i++){
            if(str[i] == stack.back())  stack.pop_back();
            else    stack.push_back(str[i]);
        }
        stack.pop_front();

        int size = stack.size();
        bool isPalin = true;
        for(int i=0; i<size/2; i++){
            if(stack[i] != stack[size-1-i]){
                isPalin = false;
                break;
            }
        }
        if(!isPalin) continue;
        cnt++;
    }

    cout<<cnt<<'\n';
}