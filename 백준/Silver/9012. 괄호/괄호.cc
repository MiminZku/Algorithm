#include <iostream>
#include <stack>

using namespace std;

int main(){
    cin.tie(nullptr); ios::sync_with_stdio(false);
    int n;
    cin>>n;
    while(n--){
        bool nagari = false;
        string str;
        cin>>str;

        stack<char> st;
        for(int i=0; i<str.size(); i++){
            if(str[i]=='(') st.push('(');
            else{
                if(st.empty()){
                    nagari=true;
                    break;
                }
                if(st.top()=='(')   st.pop();
                else{
                    nagari = true;
                    break;
                }
            }
        }
        if(nagari){
            cout<<"NO\n";
            continue;   
        }
        if(st.empty())  cout<<"YES\n";
        else            cout<<"NO\n";
    }
}