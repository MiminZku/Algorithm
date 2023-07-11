#include <iostream>
#include <stack>

using namespace std;

bool IsBalanced(const string& str){
    int len = str.size();
    stack<char> st;
    for(int i=0; i<len; i++){
        if(str[i]=='[' || str[i]=='('){
            st.push(str[i]);
        }
        else if(str[i] == ')'){
            if(st.empty())      return false;
            if(st.top()=='(')   st.pop();
            else                return false;
        }
        else if(str[i] == ']'){
            if(st.empty())      return false;
            if(st.top()=='[')   st.pop();
            else                return false;
        }
    }
    if(st.empty())  return true;
    else            return false;
}

int main(){
    cin.tie(nullptr); ios::sync_with_stdio(false);
    while(true){
        string str;
        getline(cin, str, '.');
        cin.ignore();   // 온점 뒤에 개행문자가 있으면 무시
        if(str.empty())   break;

        if(IsBalanced(str)) cout<<"yes\n";
        else                cout<<"no\n";
    }
}